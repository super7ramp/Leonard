#include "controlTask.h"

#define THRESHOLD 0.001

/**
 * \brief The different mission states used in calcul_mission()
 */
typedef enum {
    INIT = 0, //< the mission has not started yet
    LOST,     //< the drone is not on a known node
    DRIFTED,  //< the drone is on a known node, but shouldn't be there
    RUNNING,  //< normal state, the drone is moving as expected
    ARRIVED,  //< mission succeeded (transient state)
    FINISHED  //< mission is over
} mission_state_t;

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

void go_up();

void break_drone();

/** \brief Rotate to desired angle
  * \param Desired angle in degrees
  * \return 0 if no error; -1 if error */
int rotate_to_desired_angle(float angle)
{
    struct timespec init, current;
    int timeout = 0;

    clock_gettime(CLOCK_MONOTONIC, &init);
    Main_Nav = return_navdata();

    while(!timeout && (Main_Nav.magneto.heading_fusion_unwrapped > (angle + 5.0) || Main_Nav.magneto.heading_fusion_unwrapped < (angle - 5.0)))
    {
        // Timeout check
        clock_gettime(CLOCK_MONOTONIC, &current);
        timeout = (current.tv_sec - init.tv_sec) > ROTATION_TIMEOUT;

        // Keep sending rotation command
        SWITCH_DRONE_COMMANDE(5);
        Main_Nav = return_navdata();

        printf("\r[Rotation] Current: %f - Desired: %f", Main_Nav.magneto.heading_fusion_unwrapped, angle);
        usleep(10000);
    }

    if (timeout)
        return -1;

    return 0;
}

/** \brief Move to given coordinates, without checking the map
  * \param dest Destination coordinates
  * \param current Pointer to current coordinates (will be updated)
  * \return 0 if no error, > 0 if error */
int move_to(struct coordinates_ dest, struct coordinates_ *current)
{
    float distance, lastDistance;
    int findy_lost = 0;

    distance = sqrt(pow(dest.x-current->x,2) + pow(dest.y-current->y,2));
    lastDistance = distance;

    while(distance > ERROR_COORD && !findy_lost)
    {
        printf("BT location: X = %f, Y = %f (want to go to (%f, %f)\n", current->x, current->y, dest.x, dest.y);
        
        int j = 0;
        while(j < 6000) {
            pitch_move = FRONT;
            pitch_power = 0.15;
            SWITCH_DRONE_COMMANDE(4);
            j++;
        }
        break_drone();
        sleep(5);
        read_data_bluetooth(&(current->x),&(current->y));

        printf("BT location: X = %f, Y = %f (want to go to (%f, %f)\n", current->x, current->y, dest.x, dest.y);

        // Check if we're going in the wrong direction
        lastDistance = distance;
        distance = sqrt(pow(dest.x-current->x,2) + pow(dest.y-current->y,2));

        if (distance > lastDistance)
            findy_lost = 1;
    }

    return findy_lost;
}

/** \brief Move to given destination, check the map to detect any faulty path
  * \param nextPoint Next point coordinates
  * \param path Shortest path
  * \param current Pointer to current coordinates (will be updated)
  * \return 0 if we reached destination; 1 if the drone get lost; 2 if the drone drifted */
int move_to_next_point(struct coordinates_ nextPoint, const node_t **path, struct coordinates_ *current)
{
    int findy_lost = 0;
    float lastDistance, distance;

    distance = sqrt(pow(nextPoint.x-current->x,2) + pow(nextPoint.y-current->y,2));
    lastDistance = distance;
    while((distance > ERROR_COORD) && !findy_lost)
    {
        printf("Going to (%f, %f), currently at (%f, %f)\n", nextPoint.x, nextPoint.y, current->x, current->y);
        
        int j = 0;
        while (j < 6000) {
            pitch_move = FRONT;
            pitch_power = 0.15;
            SWITCH_DRONE_COMMANDE(4);
            j++;
        }
        break_drone();
        sleep(5);
        read_data_bluetooth(&(current->x),&(current->y));

        printf("Going to (%f, %f), currently at (%f, %f)\n", nextPoint.x, nextPoint.y, current->x, current->y);

        // Check if we're going in the wrong direction
        lastDistance = distance;
        distance = sqrt(pow(nextPoint.x-current->x,2) + pow(nextPoint.y-current->y,2));
        printf("Last distance: %f - Current distance: %f\n", lastDistance, distance);

        if (distance > lastDistance)
        {
            printf("We are farther than before...\n");

            // Check if we have drifted to another point
            if(find_point(graph, current->x, current->y) == -1)
            {
                //if((check = find_point_in_path(path, current.x, current.y)) == -1)
                printf("(%f, %f) is not accessible on the map\n", current->x, current->y);
                findy_lost = 1;
            }
            else
                findy_lost = 2;
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
    //printf("ordre genere par la machine scade = %d\r", outC.order_called);

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
  //printf("power: %f\n", p_power);
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
	//printf("controlTask : emergency called\n");
	pthread_mutex_lock(&mutex_control);
	inC.flag_emergency = 1;
	pthread_mutex_unlock(&mutex_control);
}
void anti_emergency_() //OK
{
  //printf("controlTask : emergency called\n");
  pthread_mutex_lock(&mutex_control);
  inC.falg_antiemergency = 1;
  pthread_mutex_unlock(&mutex_control);
}
//END FONCTIONS : EMERGENCY

void start_mission(float x_destination, float y_destination)
{
  printf("controlTask : start_mission called\n");
  pthread_mutex_lock(&mutex_control);
  go_up(); // take a bit more altitude
  destination.x = x_destination;
  destination.y = y_destination;
  inC.flag_control_s = STATE_MISSION;
  pthread_mutex_unlock(&mutex_control);
}

void stop_mission()  //fonction appelée dans la boucle whil(1) déjà protégée par un mutex
{
  printf("controlTask : end_mission called\n");
  force_land();
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
    pitch_power = pitch_power + 0.1;
    for(i = 0 ; i < 200 ; i++)
      SWITCH_DRONE_COMMANDE(4);
    pitch_power = 0;
    for(i = 0 ; i < 100 ; i++)
        SWITCH_DRONE_COMMANDE(4);

}

// Make the drone take altitude 
void go_up()
{
    int i;
    for(i = 0 ; i < 100 ; i++)
      SWITCH_DRONE_COMMANDE(9);
    for(i = 0 ; i < 100 ; i++)
        SWITCH_DRONE_COMMANDE(10);
}

void force_land()
{
    int i;
    for(i = 0 ; i < 300 ; i++)
      SWITCH_DRONE_COMMANDE(1);
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
    mission_state_t state;
    int indice = 0;
    int index = 0;
    int bad_move = 0;
    float angle_actuel, calcul_x, calcul_y, angle_desire;
    node_t **path = NULL;

    C_blue.x = 0.0;
    C_blue.y = 0.0;


    // First of all, check if the given destination is valid
    if(find_point(graph, destination.x, destination.y) == -1)
    {
        printf("Invalid destination: (%.2f, %.2f)\n", destination.x, destination.y);
        state = FINISHED;
    }
    else
        state = INIT;

    while(state != FINISHED)
    {
        if(inC.flag_control_s == STATE_MANUAL)
        {
            state = FINISHED;
        }
        switch(state)
        {
            case INIT:

                printf("[Mission state: INIT]\n");

                // Wait for the data to stabilize
                sleep(5);
                read_data_bluetooth(&C_blue.x,&C_blue.y);

                printf("BT location: X = %f, Y = %f\n", C_blue.x, C_blue.y);
                printf("Destination point: (%f, %f)\n", destination.x, destination.y);

                path = dijkstra(C_blue.x, C_blue.y, destination.x, destination.y, graph);

                if (path == NULL)
                    state = LOST;
                else
                {
                    printf("Path to follow\n");
                    int i;
                    for(i = 0 ; path[i] != NULL ; i++)
                    {
                        indice = i;
                        printf("%s (%f,%f)\n", path[i]->name, path[i]->x, path[i]->y);
                    }
                    state = RUNNING;
                }

            break;

            case LOST:

                printf("[Mission state: LOST]\n");

                sleep(3);
                read_data_bluetooth(&C_blue.x,&C_blue.y);

                index = find_closest_node(graph, C_blue.x, C_blue.y);
                startPoint.x = graph->nodes[index].x;
                startPoint.y = graph->nodes[index].y;

                Main_Nav = return_navdata();

                angle_actuel = Main_Nav.magneto.heading_fusion_unwrapped;
                angle_desire = computeDesiredAngle(C_blue, startPoint);

                computeOffsetMag(&angle_desire, nav_prec, nav_suiv);
                yaw_power = computeDirection(angle_actuel, angle_desire, 0.3, &yaw_move);

                if(rotate_to_desired_angle(angle_desire) == -1)
                {
                    fprintf(stderr, "[%s:%d] Error: Rotation to desired angle failed\n", __FILE__, __LINE__);
                    break_drone();
                    stop_mission();
                    free(graph);
                    return;
                }

                // Let the drone stabilize itself
                sleep(1);

                bad_move = move_to(startPoint, &C_blue);
                break_drone();

                // If we find a start point, we can switch to state RUNNING
                if(!bad_move)
                {

                    printf("BT location: X = %f, Y = %f\n", C_blue.x, C_blue.y);
                    printf("Destination point: (%f, %f)\n", destination.x, destination.y);

                    path = dijkstra(C_blue.x, C_blue.y, destination.x, destination.y, graph);

                    if(path == NULL)
                    {
                        fprintf(stderr, "[%s:%d] Error: Bluetooth Data too unstable, aborting\n", __FILE__, __LINE__);
                        break_drone();
                        stop_mission();
                        free(graph);
                        return;
                    }

                    printf("Path to follow\n");
                    int i;
                    for(i = 0 ; path[i] != NULL ; i++)
                    {
                        indice = i;
                        printf("%s (%f,%f)\n", path[i]->name, path[i]->x, path[i]->y);
                    }
                    state = RUNNING;
                }

            break;

            case DRIFTED:

                printf("[Mission state: DRIFTED]\n");

                // Pretty much the same that LOST, at the difference that we think that we know where we are
                sleep(3);
                read_data_bluetooth(&C_blue.x,&C_blue.y);

                printf("BT location: X = %f, Y = %f\n", C_blue.x, C_blue.y);
                printf("Destination point: (%f, %f)\n", destination.x, destination.y);

                path = dijkstra(C_blue.x, C_blue.y, destination.x, destination.y, graph);

                if (path == NULL)
                {
                    // Mmh, Bluetooth data unstable, going to LOST
                    state = LOST;
                }
                else
                {
                    printf("New path to follow\n");
                    int i;
                    for(i = 0 ; path[i] != NULL ; i++)
                    {
                        indice = i;
                        printf("%s (%f,%f)\n", path[i]->name, path[i]->x, path[i]->y);
                    }
                    state = RUNNING;
                }


            break;

            case RUNNING:

                printf("[Mission state: RUNNING]\n");

                sleep(3);
                read_data_bluetooth(&C_blue.x,&C_blue.y);

                printf("BT location: X = %f, Y = %f\n", C_blue.x, C_blue.y);
                printf("Destination point: (%f, %f)\n", destination.x, destination.y);

                // Let's start
                indice--;

                if (indice <= 0)
                {
                    state = ARRIVED;
                }
                else
                {
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
                    yaw_power = computeDirection(angle_actuel, angle_desire, 0.3, &yaw_move);
                    //printf("Valeur de la puissance mise : %1.f, Valeur de l'angle souhaité = %2.f, valeur de l'angle actuel = %2.f sens de rotation = %d\n", yaw_power, angle_desire, angle_actuel, yaw_move);

                    if (rotate_to_desired_angle(angle_desire) == -1)
                    {
                        break_drone();
                        stop_mission();
                        free(graph);
                        return;
                    }

                    // Let the drone stabilize itself
                    sleep(1);

                    // Let's move to next point
                    bad_move = move_to_next_point(nextPoint, (const node_t **) path, &C_blue);

                    // Stop the drone movement
                    break_drone();

                    if(bad_move == 1)
                        state = LOST;
                    else if(bad_move == 2)
                        state = DRIFTED;
                    else
                        printf("One step made\n");
                }

            break;

            case ARRIVED:
                printf("[Mission state: ARRIVED]\n");
                printf("You're arrived to destination\n");
                state = FINISHED;
            break;

            case FINISHED:
                // if stop mission called
            break;

            default:
                fprintf(stderr, "[%s:%d] Error: Unknown mission state\n", __FILE__, __LINE__);
                break_drone();
                stop_mission();
                free(graph);
                return;
            break;
        }
    }

    printf("[Mission state: FINISHED]\n");

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
            //printf("case 3 : set_roll, roll_power=%f\n", roll_power);
            set_roll(message, roll_move, roll_power);
            inC.flag_rollcalled = 0;
            break;

        case 4 :
            //printf("case 4 : set_pitch, pitch_power=%f, yaw_power=%f\n", pitch_power, yaw_power);
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

            set_yaw(message, LEFT, 0.0);

            inC.flag_calibM = 0;
            break;

        case 9 :
            //set_emergency(message);
            inC.flag_emergency = 0;
            set_gaz(message, UP, 0.2);// this is an ugly hack (don't commit this)
            break;

        case 10 :
            //anti_emergency(message);
            inC.falg_antiemergency = 0;
            set_gaz(message, UP, 0.0);// this is an ugly hack (don't commit this)
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
