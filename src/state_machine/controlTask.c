#include "controlTask.h"

#define THRESHOLD 0.001

/** \brief Get the index of a point in the path
  * \param path The path of nodes
  * \param other_x x coordinate
  * \param other_y y coordinate
  * \return The index of the point in the path; -1 if not found */
int find_point_in_path (node_t ** path, float other_x, float other_y);

/** \brief Get the index of the closest node to the current position of the drone in the graph
  * \param graph The graph_t structure (our map)
  * \param current_x Current x coordinate
  * \param current_y Current y coordinate
  * \return The index */
int find_closest_node(graph_t *graph, float current_x, float current_y);

/** \brief Rotate to desired angle
  * \param Desired angle in degrees
  * \return 0 if no error; -1 if error */
int rotate_to_desired_angle(float angle)
{
    struct timespec init, current;
    int timeout = 0;

    clock_gettime(CLOCK_MONOTONIC, &init);
    Main_Nav = return_navdata();

    while(!timeout && (Main_Nav.magneto.heading_fusion_unwrapped > (angle + 3.0) || Main_Nav.magneto.heading_fusion_unwrapped < (angle - 3.0)))
    {
        // Timeout check
        clock_gettime(CLOCK_MONOTONIC, &current);
        timeout = (current.tv_sec - init.tv_sec) > ROTATION_TIMEOUT;

        // Keep sending rotation command
        SWITCH_DRONE_COMMANDE(5);
        Main_Nav = return_navdata();

        //printf("\rValeur de angle_trouve et angle désiree = %f, %f     ,Bat = %d",
        //Main_Nav.magneto.heading_fusion_unwrapped, angle_desire,Main_Nav.demo.vbat_flying_percentage);

        usleep(20000);
    }

    if (timeout)
        return -1;

    return 0;
}

/** \brief Move to given coordinates, without checking the map
  * \param Destination coordinates
  * \return 0 if no error */
int move_to(struct coordinates_ dest)
{
    struct coordinates_ current = { 0.0, 0.0 };

    sleep(5); // Wait for the drone to stabilize 
    read_data_bluetooth(&current.x, &current.y);

    pitch_move = FRONT;
    pitch_power = 0.2;

    while(sqrt(pow(dest.x-current.x,2) + pow(dest.y-current.y,2)) > ERROR_COORD)
    {
        int j = 0;
        while(j < 5000) {
            pitch_move = FRONT;
            pitch_power = 0.2;
            SWITCH_DRONE_COMMANDE(4);
            j++;
        }
        break_drone();
        sleep(5);
        read_data_bluetooth(&current.x,&current.y);

        //printf("(Start point not found) Enter x and y\n");
        //scanf("%f", &(C_blue.x));
        //scanf("%f", &(C_blue.y));

        printf("\rBT location: X = %f, Y = %f (want to go to (%f, %f)", current.x, current.y, dest.x, dest.y);
    }

    return 0;
}

/** \brief Move to given destination, check the map to detect any faulty path
  * \param nextPoint Next point coordinates
  * \param path Shortest path
  * \return 0 if we reached destination; > 0 if a drift is detected */
int move_to_next_point(struct coordinates_ nextPoint, const node_t **path)
{
    int check = 0;
    int findy_lost = 0;
    struct coordinates_ current = { 0.0, 0.0 };

    sleep(5); // Wait for the drone to stabilize 
    read_data_bluetooth(&current.x, &current.y);
    
    //printf("Valeur de tab_algo_x[%d] = %.2f |&&| Valeur de C_blue.x = %.2f\n", indice, path[indice]->x, C_blue.x);
    //printf("Valeur de tab_algo_y[%d] = %.2f |&&| Valeur de C_blue.x = %.2f\n", indice, path[indice]->y, C_blue.y);

    while((sqrt(pow(nextPoint.x-current.x,2) + pow(nextPoint.y-current.y,2)) > ERROR_COORD) && (findy_lost != 1))
    {
        int j = 0;
        while (j < 5000) {
            pitch_move = FRONT;
            pitch_power = 0.2;
            SWITCH_DRONE_COMMANDE(4);
            j++;
        }
        break_drone();
        sleep(3);
        read_data_bluetooth(&current.x,&current.y);

        //printf("main move, enter x and y\n");
        //scanf("%f", &(C_blue.x));
        //scanf("%f", &(C_blue.y));

        printf("\rGoing to (%f, %f), currently at (%f, %f)", nextPoint.x, nextPoint.y, current.x, current.y);

        if((check = find_point(graph, current.x, current.y)) != -1)
        {
            if((check = find_point_in_path(path, current.x, current.y)) == -1)
            findy_lost = 1;
        }
    }

    return findy_lost;
}

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

void start_mission(float x_destination, float y_destination)
{
  printf("controlTask : start_mission called\n");
  pthread_mutex_lock(&mutex_control);
  destination.x = x_destination;
  destination.y = y_destination;
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
    pitch_power = 0;
    for(i = 0 ; i < 100 ; i++)
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
    struct coordinates_ nextPoint;
    struct coordinates_ startPoint;
    int indice = 0;
    int index = 0;
    int check = 0;
    int findy_lost = 0;
    float angle_actuel, calcul_x, calcul_y, angle_desire;

    C_blue.x = 0.0;
    C_blue.y = 0.0;

    // Wait for the data to stabilize
    sleep(3);
    read_data_bluetooth(&C_blue.x,&C_blue.y);

    //printf("Enter first x and first y\n");
    //scanf("%f", &(C_blue.x));
    //scanf("%f", &(C_blue.y));

    //printf("BT location: X = %f, Y = %f\n", C_blue.x, C_blue.y);
    //printf("Destination point: (%f, %f)\n", destination.x, destination.y);

    node_t **path = dijkstra(C_blue.x, C_blue.y, destination.x, destination.y, graph);

    if (path == NULL)
    {
        /*
        // Destination point not found, cannot do the mission
        fprintf(stderr, "[%s:%d] Error: destination point not found, mission aborted\n", __FILE__, __LINE__);
        stop_mission();
        return;
        */

        index = find_closest_node(graph, C_blue.x, C_blue.y);
        startPoint.x = graph->nodes[index].x;
        startPoint.y = graph->nodes[index].y;

        Main_Nav = return_navdata();

        angle_actuel = Main_Nav.magneto.heading_fusion_unwrapped;
        angle_desire = computeDesiredAngle(C_blue, startPoint);

        computeOffsetMag(&angle_desire, nav_prec, nav_suiv);
        yaw_power = computeDirection(angle_actuel, angle_desire, 0.2, &yaw_move);

        if(rotate_to_desired_angle(angle_desire) == -1)
        {
            fprintf(stderr, "[%s:%d] Error: Rotation to desired angle failed\n", __FILE__, __LINE__);
            break_drone();
            stop_mission();
            free(graph);
            return;
        }

        move_to(startPoint);

        break_drone();
        
        read_data_bluetooth(&C_blue.x,&C_blue.y);
        
        path = dijkstra(C_blue.x, C_blue.y, destination.x, destination.y, graph);

        if (path == NULL)
        {
            fprintf(stderr, "[%s:%d] Error: destination point not found, mission aborted\n", __FILE__, __LINE__);
            stop_mission();
            free(graph);
            return;
        }
    }

    printf("Path to follow\n");
    int i;
    for(i = 0 ; path[i] != NULL ; i++)
    {
        indice = i;
        printf("%s (%f,%f)\n", path[i]->name, path[i]->x, path[i]->y);
    }

    // Let's start
    indice = indice - 1;
  
    while(indice >= 0) 
    {
        //printf("Valeurs des coordonnees bluetooth   (x,y) = (%2.f,%2.f) \n" ,C_blue.x,C_blue.y);
        //printf("Valeurs des coordonnees à atteindre (x,y) = (%2.f,%2.f) \n" ,path[indice]->x, path[indice]->y);
        int mission_finie = 0;

        // FIXME: Cast path[indice] from node_t to coordinates_ since we don't use the samee structure...
        nextPoint.x = path[indice]->x;
        nextPoint.y = path[indice]->y;

        Main_Nav = return_navdata();
        angle_actuel = Main_Nav.magneto.heading_fusion_unwrapped; 
        angle_desire = computeDesiredAngle(C_blue, nextPoint);

        /* 
         * angle désiré
         */

        //calcul the new angle_desire
        computeOffsetMag(&angle_desire, nav_prec, nav_suiv);

        //printf("Calcul angle desire final v1 : %2.f\n", angle_desire);

        //calculating the direction of rotation of the Z-axis for optimum positioning.
        yaw_power = computeDirection(angle_actuel, angle_desire, 0.2, &yaw_move);
        //printf("Valeur de la puissance mise : %1.f, Valeur de l'angle souhaité = %2.f, valeur de l'angle actuel = %2.f sens de rotation = %d\n", yaw_power, angle_desire, angle_actuel, yaw_move);

        if (rotate_to_desired_angle(angle_desire) == -1)
        {
            break_drone();
            stop_mission();
            free(graph);
            return;
        }

        // Let's move to next point
        findy_lost = move_to_next_point(nextPoint, (const node_t **) path);

        // Stop the drone movement
        break_drone();
       
        sleep(3); 
        read_data_bluetooth(&C_blue.x,&C_blue.y);

        // If the drone is lost, we calculate a new path and we re-initialize the variable "indice"
        // Else decrementation of "indice"
        if(findy_lost > 0)
        {
            printf("Findy deviated, recalculating path...\n");
            path = dijkstra(C_blue.x, C_blue.y, destination.x, destination.y, graph);
            printf("New path to follow:\n");
            for(i = 0 ; path[i] != NULL ; i++)
            {
                indice = i;
                printf("%s (%f,%f)\n", path[i]->name, path[i]->x, path[i]->y);
            }
            indice--;
            findy_lost = 0;
        }
        else
        {
            // Reached first step successfully
            printf("One step made\n");
            indice = indice - 1;
        }

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
            //printf("SWITCH COMMANDE take off\n");
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

int find_closest_node(graph_t *graph, float current_x, float current_y)
{
  float distance = 9999;
  float tmp;
  int i;
  int indice = -1;

  for(i = 0 ; i < graph->numberOfNodes ; i++)
  {
    tmp = sqrt(pow(graph->nodes[i].x - current_x,2) + pow(graph->nodes[i].y - current_y, 2));

    if(tmp < distance)
    {
      indice = i;
      distance = tmp;
    }
  }
  return indice;
}
