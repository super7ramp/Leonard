#include "controlTask.h"


void* controlTask(void* arg)
{ 
  pthread_mutex_t verrou_control; 
  pthread_cond_t cond;  
  pthread_cond_init(&cond, NULL); 
  pthread_mutex_init(&verrou_control, NULL);

  struct timeval tp;
  struct timespec ts;

  char message [64];
  float pitch_cmd = 0.0;
  float roll_cmd = 0.0;
  float angular_speed_cmd = 0.0;
  float vertical_speed_cmd = 0.0; 

  initialize_at_com();    //initialisation du soket pour les commandes AT.
  //initNavdata();          //initialisation du soket pour les navdata.
  //initialisation_uart();  //initialisation de la commuication Uart.

  pthread_mutex_lock(&mutex_control);
  inC.flag_control_e = CONTROL_ENABLED;
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

    system_state_machine(&inC,&outC); //CODE SCADE
    
    switch(outC.order_called){

      case 0 : 
          //printf("Auncun ordre envoyé donc passage envoi de l'ordre reset_com\n");
          reset_com(message);
          break;

      case 1 :
          //printf("Envoi de la commande AT=land\n");
          landing(message);
          landCalled = 0;
          break;

      case 2 :
          //printf("Envoi de la commande AT=takeoff\n");
          take_off(message);
          takeOffCalled = 0;
          break;

      case 3 :
          set_roll(message, roll_move, roll_power);
          rollCalled = 0;
          break;

      case 4 :
          set_pitch(message, pitch_move, pitch_power);
          pitchCalled = 0;
          break;

      case 5 :
          //set_Yaw(message, yaw_move, pitch_power);
          yawCalled = 0;
          break;

      case 6 :
          set_roll(message, roll_move, roll_power);
          set_pitch(message, pitch_move, pitch_power);
          rollpitchCalled = 0;
          break;

      case 7 :
          set_trim(message);
          calibHorCalled = 0;
          break;

      case 8 :
          //sendCalibMagn(seqNumber);
          calibMagnCalled = 0;
          break;

      case 9 :
          set_emergency(message);
          emergencyCalled = 0;
          break;

      case 10 :
          anti_emergency(message);
          emergencyCalled = 0;
          break;

      case 20 : 
          start_mission(0.0,0.0);
          break;

      default :
          printf("Scade ne marche pas si bien que ça finalement\n");
          break;
    }
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

void stop_mission()
{
  printf("controlTask : end_mission called\n");
  pthread_mutex_lock(&mutex_control);
  inC.flag_control_s = STATE_MANUAL;
  pthread_mutex_unlock(&mutex_control);

}

void calcul_mission()
{
  struct coordinates_ C_blue; //coordinates of drone
  float nav_z,calcul_x, calcul_y, calcul_a;
  read_data_bluetooth(&C_blue.x,&C_blue.y);
  nav_z = GetYaw();  //à changer
  calcul_x = map.x - C_blue.x;
  calcul_y = map.y - C_blue.y;
  calcul_a = atanf(abs(map.y-C_blue.y)/abs(map.x-C_blue.x)); //calcul de l'angle
  calcul_a = calcul_a / (PI/2) * 180.0; //radians en dergrées
  if(calcul_x>0.0 && calcul_y>0.0) //si quadrant haut droite
    calcul_a;
  else if (calcul_x<0.0 && calcul_y>0.0) //si quadrant bas droite
    calcul_a = - calcul_a;
  else if (calcul_x>0.0 && calcul_y<0.0) //Si quadrant haut gauche
    calcul_a = 180.0 - calcul_a;
  else if (calcul_x<0.0 && calcul_y<0.0) //Si quadrant bas gauche
    calcul_a = -180.0 + calcul_a;

  if(calcul_a > 150.0) //nécessaire au vu des donnée renvoyées par le navdata. [-210:0:+150]
    calcul_a = calcul_a - 360.0;
}