#include "controlTask.h"

#define THRESHOLD 0.001

//return the index of a point in the path
int find_point_in_path (node_t ** path, float other_x, float other_y);

void* controlTask(void* arg)
{ 
  pthread_mutex_t verrou_control; 
  pthread_cond_t cond;  
  pthread_cond_init(&cond, NULL); 
  pthread_mutex_init(&verrou_control, NULL);

  struct timeval tp;
  struct timespec ts;


  float pitch_cmd = 0.0;
  float roll_cmd = 0.0;
  float angular_speed_cmd = 0.0;
  float vertical_speed_cmd = 0.0; 

  initialize_at_com();    //initialisation du soket pour les commandes AT.
  
  initNavdata();          //initialisation du soket pour les navdata.
  Main_Nav = getNavdata();
  //initialisation_uart();  //initialisation de la commuication Uart.

  //creation of graph
  FILE* file = fopen(NAME_MAP_DEMO, "r");
  graph = createGraph(file);
  fclose(file);

  pthread_mutex_lock(&mutex_control);
  inC.flag_control_e = CONTROL_ENABLED_SCADE;
  inC.flag_control_s = STATE_MANUAL;
  inC.flag_takeoff = 0;
  inC.flag_land = 0;
  inC.flag_emergency = 0;
  inC.flag_calibH = 0;
  inC.flag_calibM = 0;
  inC.flag_pitchcalled = 0;
  inC.flag_rollcalled = 0;
  inC.flag_rollpitchcalled = 0;
  inC.flag_yawcalled = 0;
  system_state_machine_reset(&outC);
  pthread_mutex_unlock(&mutex_control);

  while(1)
  {
    //printf("Debut de la boucle while(1) du thread controlTask\n");
  	//récupération de la clock courante
    gettimeofday(&tp, NULL);
    ts.tv_sec = tp.tv_sec;
    ts.tv_nsec = tp.tv_usec * 1000;
    //application de la nouvelle période d'éxécution du thread_envoi_ordre
    ts.tv_nsec += CONTROLTASK_PERIOD_CONTROLE_MS * 1000000;
    ts.tv_sec += ts.tv_nsec / 1000000000L;
    ts.tv_nsec = ts.tv_nsec % 1000000000L;
    pthread_mutex_lock(&verrou_control);
    //printf("Passage du pthread_mutex_lock(&verrou_control) dans controlTask\n"); 
    pthread_mutex_lock(&mutex_control);
    //printf("Passage du pthread_mutex_lock(&mutex_control) dans controlTask\n");

    system_state_machine_reset(&outC);
    system_state_machine(&inC,&outC); //CODE SCADE
    printf("ordre genere par la machine scade = %d\r", outC.order_called);

    SWITCH_DRONE_COMMANDE(outC.order_called);//SWITCH pour l'envoi des ordres
    
    
    pthread_mutex_unlock(&mutex_control);
    pthread_cond_timedwait(&cond, &verrou_control, &ts);
    pthread_mutex_unlock(&verrou_control);    
  } 
}


void takeOff() //OK
{
	//printf("controlTask : takeOff called\n");
	pthread_mutex_lock(&mutex_control);
	inC.flag_takeoff = 1;
	pthread_mutex_unlock(&mutex_control);
}


void land() //OK
{
	//printf("controlTask : land called\n");
	pthread_mutex_lock(&mutex_control);
	inC.flag_land = 1;
	pthread_mutex_unlock(&mutex_control);
}

//FONCTIONS : MOVE BACK,FRONT,LEFT,RIGHT,BACK-LEFT,BACK-RIGHT,FRONT-LEFT,FRONT-RIGHT
void move_PitchRoll(direction pitch_dir, direction roll_dir, float p_power, float r_power) //OK
{
	//printf("controlTask : move called\n");
	pthread_mutex_lock(&mutex_control);
  pitch_move  = pitch_dir;
  pitch_power = p_power;
  roll_move   = roll_dir;
  roll_power  = r_power;
  inC.flag_rollpitchcalled = 1;
	pthread_mutex_unlock(&mutex_control);
}
void move_Pitch(direction pitch_dir, float p_power) //OK
{
  //printf("controlTask : move_Pitch called\n");
  pthread_mutex_lock(&mutex_control);
  pitch_move  = pitch_dir;
  pitch_power = p_power;
  inC.flag_pitchcalled = 1;
  pthread_mutex_unlock(&mutex_control);
}
void move_Roll(direction roll_dir, float r_power) //OK
{
  //printf("controlTask : move_Roll called\n");
  pthread_mutex_lock(&mutex_control);
  roll_move  = roll_dir;
  roll_power = r_power;
  inC.flag_rollcalled = 1;
  pthread_mutex_unlock(&mutex_control);
}
void move_Yaw(direction yaw_dir, float y_power)
{
  //printf("controlTask : move_Yaw called\n");
  pthread_mutex_lock(&mutex_control);
  yaw_move  = yaw_dir;
  yaw_power = y_power;
  inC.flag_yawcalled = 1;
  pthread_mutex_unlock(&mutex_control);
}
//END FONCTIONS : MOVE BACK,FRONT,LEFT,RIGHT,BACK-LEFT,BACK-RIGHT,FRONT-LEFT,FRONT-RIGHT


//FONCTIONS : CALIBRATION TRIM AND MAGNETO
void calibHor() //OK
{
	printf("controlTask : calibHor called\n");
	pthread_mutex_lock(&mutex_control);
	inC.flag_calibH = 1;
	pthread_mutex_unlock(&mutex_control);
}
void calibMagn() //OK
{
	printf("controlTask : calibMagn called\n");
	pthread_mutex_lock(&mutex_control);
	inC.flag_calibM = 1;
	pthread_mutex_unlock(&mutex_control);
}
//END FONCTIONS : CALIBRATION TRIM AND MAGNETO

//FONCTIONS : EMERGENCY
void emergency_() //OK
{
	printf("controlTask : emergency called\n");
	pthread_mutex_lock(&mutex_control);
	inC.flag_emergency = 1;
	pthread_mutex_unlock(&mutex_control);
}
void anti_emergency_() //OK
{
  printf("controlTask : emergency called\n");
  pthread_mutex_lock(&mutex_control);
  inC.falg_antiemergency = 1;
  pthread_mutex_unlock(&mutex_control);
}
//END FONCTIONS : EMERGENCY

void start_mission(float x_map, float y_map)
{
  printf("controlTask : start_mission called\n");
  pthread_mutex_lock(&mutex_control);
  map.x = x_map;
  map.y = y_map;
  inC.flag_control_s = STATE_MISSION;
  pthread_mutex_unlock(&mutex_control);
}

void stop_mission()  //fonction appelée dans la boucle whil(1) déjà protégée par un mutex
{
  printf("controlTask : end_mission called\n");
  inC.flag_control_s = STATE_MANUAL;
  ORDER = NOTDONE;
}

void break_drone()
{
/*
  break the drone
*/
    int i;
    pitch_move = BACK;
    pitch_power = pitch_power + 0.2;
    for(i = 0 ; i < 200 ; i++)
      SWITCH_DRONE_COMMANDE(4);
}

Navdata return_navdata()
{
    while(isControllerReady()==0); //attente données navdata actualisées
    return getNavdata();
}

void calcul_mission()
{
  struct coordinates_ C_blue; //coordinates of drone
  int indice = 0;
  int check = 0;
  int findy_lost = 0;
  float angle_actuel,calcul_x, calcul_y, angle_desire;

/*
  map.tab_algo_x[0] = map.x - map.x; //Simulation
  map.tab_algo_y[0] = map.y;  //Simulation
  map.tab_algo_x[1] = map.x;  //Simulation
  map.tab_algo_y[1] = map.y;  //Simulation

  map.tab_algo_x[2] = 100.0; //Simulation
  map.tab_algo_y[2] = 100.0; //Simulation
*/

  read_data_bluetooth(&C_blue.x,&C_blue.y);
printf("BT x = %f \nBT y = %f\n", C_blue.x, C_blue.y);
  node_t **path = dijkstra(C_blue.x, C_blue.y, map.x, map.y, graph);
  printf("                                                                           \n");

  int i;
  for(i = 0 ; path[i] != NULL ; i++)
    indice = i;
  
  while(indice >= 0) 
  {
    printf("Valeur de l'indice du pour le tab_algox/y[] = %d\n", indice);
    printf("Valeurs des coordonnees bluetooth   (x,y) = (%2.f,%2.f) \n" ,C_blue.x,C_blue.y);
    printf("Valeurs des coordonnees à atteindre (x,y) = (%2.f,%2.f) \n" ,path[indice]->x, path[indice]->y);
    int mission_finie = 0;

    Main_Nav = return_navdata();
    angle_actuel = Main_Nav.magneto.heading_fusion_unwrapped; 

/*
    calcul_x = map.tab_algo_x[indice] - C_blue.x;
    calcul_y = map.tab_algo_y[indice] - C_blue.y;
*/
    calcul_x = path[indice]->x - C_blue.x;
    calcul_y = path[indice]->y - C_blue.y;

    printf("Valeur de calcul_x (x : destination-bluetooth) = %2.f\n" ,calcul_x);
    printf("Valeur de calcul_y (y : destination-bluetooth) = %2.f\n" ,calcul_y);

    if(path[indice]->x-C_blue.x == 0.0)
      angle_desire = 0.0;
    else
      angle_desire = atanf(abs(path[indice]->y-C_blue.y)/abs(path[indice]->x-C_blue.x)); //calcul de l'angle
    
    printf("Calcul angle desire (rad)   : %2.f\n", angle_desire);
    angle_desire = angle_desire / (PI/2) * 180.0 / 2.0; //radians en dergrées
    printf("Calcul angle desire (degree): %2.f\n", angle_desire);
    if(calcul_x == 0.0 && calcul_y > 0.0)
      angle_desire = 0.0;
    else if(calcul_x == 0.0 && calcul_y < 0.0)
      angle_desire = 180.0;
    else if(calcul_y == 0.0 && calcul_x > 0.0)
      angle_desire = 90.0;
    else if(calcul_y == 0.0 && calcul_x < 0.0)
      angle_desire = -90.0;
    else if(calcul_x>0.0 && calcul_y>0.0) //si quadrant haut droite
      angle_desire = angle_desire;
    else if (calcul_x<0.0 && calcul_y>0.0) //si quadrant bas droite
      angle_desire = - angle_desire;
    else if (calcul_x>0.0 && calcul_y<0.0) //Si quadrant haut gauche
      angle_desire = 180.0 - angle_desire;
    else if (calcul_x<0.0 && calcul_y<0.0) //Si quadrant bas gauche
      angle_desire = -180.0 + angle_desire;

    printf("Calcul angle desire final v0.1 : %2.f\n", angle_desire);
    /*
    angle désiré
    */
    //On doit récuperer la valeur de heading_unwrapped pour trouver le min et max de la plage de variation des valeurs MAG pfff (thank parrot)
    printf("Valeur de heading_unwrapped = %.2f                        | Valeur de angle desire = %.2f\n", Main_Nav.magneto.heading_unwrapped, angle_desire);   
    printf("Valeut de 180 + Main_Nav.magneto.heading_unwrapped = %.2f | Valeur de -180 + Main_Nav.magneto.heading_unwrapped = %.2f \n", (180.0+Main_Nav.magneto.heading_unwrapped), (-180.0+Main_Nav.magneto.heading_unwrapped));
    printf("                                                                                                                           \n");
    if(angle_desire > nav_prec)// (180.0 + Main_Nav.magneto.heading_unwrapped)) 
    {
      angle_desire = angle_desire - 360.0;
    }
    else if(angle_desire < nav_suiv) 
    {
      angle_desire = angle_desire + 360.0;
    }

    printf("Calcul angle desire final v1 : %2.f\n", angle_desire);
    
    //Calcul du sens de rotation de l'axe Z pour un positionnement le plus rapide.
    if(angle_actuel < 0 && angle_desire > 0){
      if((angle_desire - angle_actuel)>180)
        yaw_move = LEFT;
      else
        yaw_move = RIGHT;
    }
    else if(angle_actuel > 0 && angle_desire < 0){
      if((angle_actuel - angle_desire) > 180)
        yaw_move = RIGHT;
      else
        yaw_move = LEFT;
    }
    else if(angle_actuel > 0 && angle_desire > 0)
      yaw_move = RIGHT;
    else if(angle_actuel < 0 && angle_desire < 0)
      yaw_move = LEFT;
    //fin du calcul

    yaw_power = 0.2;
    
    printf("Valeur de la puissance mise : %1.f, Valeur de l'angle souhaité = %2.f, valeur de l'angle actuel = %2.f sens de rotation = %d\n", yaw_power, angle_desire, angle_actuel, yaw_move);
    //Début de la rotation
    while(Main_Nav.magneto.heading_fusion_unwrapped > (angle_desire + 3.0) || Main_Nav.magneto.heading_fusion_unwrapped < (angle_desire - 3.0))
    {
      //SWITCH_DRONE_COMMANDE(5);
      Main_Nav = return_navdata();
      printf("Valeur de angle_trouve et angle désiree = %f, %f     ,Bat = %d  \r", Main_Nav.magneto.heading_fusion_unwrapped, angle_desire,Main_Nav.demo.vbat_flying_percentage);
    }

    printf("\n");
    //Début du déplacement FRONT
    pitch_move = FRONT;
    pitch_power = 0.2;

    //int ploki=0; //Simulation

    printf("Valeur de tab_algo_x[%d] = %.2f |&&| Valeur de C_blue.x = %.2f\n", indice, path[indice]->x, C_blue.x);
    printf("Valeur de tab_algo_y[%d] = %.2f |&&| Valeur de C_blue.x = %.2f\n", indice, path[indice]->y, C_blue.y);

//envoie commande pitch tant qu'on est pas a la coordonnée bluetooth
    while((((path[indice]->x - C_blue.x) < THRESHOLD) || ((path[indice]->y - C_blue.y) < THRESHOLD)) && (findy_lost != 1))
    {
      //SWITCH_DRONE_COMMANDE(4);
      read_data_bluetooth(&C_blue.x,&C_blue.y);

      if((check = find_point(graph, C_blue.x, C_blue.y)) != -1)
      {
        if((check = find_point_in_path(path, C_blue.x, C_blue.y)) == -1)
          findy_lost = 1;
      }
/*
      ploki = ploki + 1; //Simulation      
      if(ploki > 4000) //Simulation
      {
        printf("ploki vaut = %d\n", ploki);
        C_blue.y = map.tab_algo_y[indice]; //Simulation
        C_blue.x = map.tab_algo_x[indice]; //Simulation
      } //Simulation
*/
    }

    //if the drone is lost, we calculate a new path and we re-initialize the variable "indice"
    //else decrementation of "indice"
    if(findy_lost == 1)
    {
      path = dijkstra(C_blue.x, C_blue.y, map.x, map.y, graph);
      for(i = 0 ; path[i] != NULL ; i++)
        indice = i;
    }
    else
      indice = indice - 1;

    break_drone();
  }
  stop_mission();
  printf("fin mission\n");
  free(path);
}

void SWITCH_DRONE_COMMANDE(int _order)
{
  char message [64];
  
  switch(_order){

        case 0 : 
            reset_com(message);
            break;

        case 1 :
            landing(message);
            inC.flag_land = 0;
            break;

        case 2 :
            take_off(message);
            inC.flag_takeoff = 0;
            break;

        case 3 :
            set_roll(message, roll_move, roll_power);
            inC.flag_rollcalled = 0;
            break;

        case 4 :
            set_pitch(message, pitch_move, pitch_power);
            inC.flag_pitchcalled = 0;
            break;

        case 5 :
            set_yaw(message, yaw_move, yaw_power);
            inC.flag_yawcalled = 0;
            break;

        case 6 :
            set_roll(message, roll_move, roll_power);
            set_pitch(message, pitch_move, pitch_power);
            inC.flag_rollpitchcalled = 0;
            break;

        case 7 :
            set_trim(message);
            inC.flag_calibH = 0;
            break;

        case 8 :
            calibrate_magneto(message);
            sleep(3);
            while(1)
            {
              set_yaw(message, RIGHT, 0.1);
              while(isControllerReady()==0);
              
              Main_Nav = getNavdata();
              if (Main_Nav.magneto.heading_fusion_unwrapped > 0.0)
                nav_suiv = Main_Nav.magneto.heading_fusion_unwrapped - 360.0;
              else
                nav_suiv = Main_Nav.magneto.heading_fusion_unwrapped + 360.0;
              
              printf("angle_trouve et angle +/- 360 = %.2f, %.2f                   \r", Main_Nav.magneto.heading_fusion_unwrapped, nav_suiv);
              if(nav_suiv < 0.0 && nav_prec > 0.0 || nav_suiv > 0.0 && nav_prec < 0.0)
              {
                inC.flag_calibM = 0;
                printf("\nnav_suiv = %.2f | nav_prec = %.2f\n", nav_suiv, nav_prec);
                break;
              }
              nav_prec = nav_suiv;
            }
            inC.flag_calibM = 0;
            break;

        case 9 :
            set_emergency(message);
            inC.flag_emergency = 0;
            break;

        case 10 :
            anti_emergency(message);
            inC.falg_antiemergency = 0;
            break;

        case 20 : 
            calcul_mission();
            break;

        default :
            printf("Scade ne marche pas si bien que ça finalement\n");
            break;
      }  
}

int find_point_in_path (node_t ** path, float other_x, float other_y)
{
  int i;
  float x, y;
  for(i = 0 ; path[i] != NULL ; i++)
  {
    x = path[i]->x;
    y = path[i]->y;
    if(sqrt(pow(x-other_x,2) + pow(y-other_y,2)) < ERROR_COORD)
      return i;
  }
  return -1;
}