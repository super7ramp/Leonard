#include "controlTask.h"


void* controlTask(void* arg)
{ 
  pthread_mutex_t verrou; 
  pthread_cond_t cond;  
  pthread_cond_init(&cond, NULL); 
  pthread_mutex_init(&verrou, NULL);

  struct timeval tp;
  struct timespec ts;

  char message [64];
  float pitch_cmd = 0.0;
  float roll_cmd = 0.0;
  float angular_speed_cmd = 0.0;
  float vertical_speed_cmd = 0.0; 

  //initControl(); fonction à créer permettant d'initialiser le socket pour l'envoie des commande AT
  //et la réception des nvdata pour la régulation.

  pthread_mutex_lock(&mutex_control);
  control_enable = CONTROL_ENABLED;
  control_state  = STATE_MANUAL;
  seqNumber = 1;
  takeOffCalled = 0;
  landCalled = 0;
  moveCalled = 0;
  emergencyCalled = 0;
  calibHorCalled = 0;
  calibMagnCalled = 0;
  initNavDataCalled = 1;
  move_done = 0;
  pthread_mutex_unlock(&mutex_control);

  while(1)
  {
  	//récupération de la clock courante
    gettimeofday(&tp, NULL);
    ts.tv_sec = tp.tv_sec;
    ts.tv_nsec = tp.tv_usec * 1000;
    //application de la nouvelle période d'éxécution du thread_envoi_ordre
    ts.tv_nsec += CONTROLTASK_PERIOD_MS * 1000000;
    ts.tv_sec += ts.tv_nsec / 1000000000L;
    ts.tv_nsec = ts.tv_nsec % 1000000000L;
    pthread_mutex_lock(&verrou);
    pthread_mutex_lock(&mutex_control);
	printf("valeur de ts.tv_nsec : %ld\n", ts.tv_nsec);
    if(control_enable == CONTROL_ENABLED)
    {
    
      if(control_state == STATE_MISSION)
      {
        /*mission(x_cons, y_cons, z_cons, angle_cons, &pitch_cmd, &roll_cmd, &angular_speed_cmd, &vertical_speed_cmd);
        sendMovement(seqNumber, 1, pitch_cmd, roll_cmd, vertical_speed_cmd, angular_speed_cmd);
        //printf("x=%f\ty=%f\tz=%f\tangle=%f\t\tpitch=%f\troll=%f\taspeed=%f\tvspeed=%f\n",getX(),getY(),getZ(),getAngle(),pitch_cmd,roll_cmd,angular_speed_cmd,vertical_speed_cmd);
        */
        checkEndOfMission_();
      }
      else if(control_state==STATE_MANUAL || move_done==1)
      {
        if(move_done==1)
        {
          movement(message, seqNumber, 12, power);
          move_done = 0;
        }
        else if(landCalled==1)
        {
          landing(message, seqNumber);
          landCalled = 0;
        }
        else if(takeOffCalled==1) 
        {
          take_off(message, seqNumber);
          takeOffCalled = 0;
        }
        else if(emergencyCalled==1) 
        {
          emergency(message, seqNumber);
          emergencyCalled = 0;
        }
        else if(calibHorCalled==1) 
        {
          set_trim(message, seqNumber);
          calibHorCalled = 0;
        }
        else if(calibMagnCalled==1) 
        {
          //sendCalibMagn(seqNumber);
          calibMagnCalled = 0;
        }
        else
        {
          reset_com(message);
        }
        seqNumber++;
      }
    }
    pthread_mutex_unlock(&mutex_control);    
    pthread_cond_timedwait(&cond, &verrou, &ts); 
    pthread_mutex_unlock(&verrou);      
  } 
}


int executeMission_(float x_obj, float y_obj, float z_obj, float angle_obj)
{
	/*if(!canStartMission()) {
		printf("controlTask : can't start mission\n");
		return -1;
	}*/
	printf("controlTask : executeMission called and running\n");
	pthread_mutex_lock(&mutex_control);
	x_cons = x_obj;
	y_cons = y_obj;
	z_cons = z_obj;
	angle_cons = angle_obj;
	control_state = STATE_MISSION;
	pthread_mutex_unlock(&mutex_control);
	return 0;
}


void executeManual_()
{		
	printf("controlTask : executeManual called\n");
	pthread_mutex_lock(&mutex_control);
	takeOffCalled = 0;
	landCalled = 0;
	moveCalled = 0;
	emergencyCalled = 0;
	calibHorCalled = 0
;	calibMagnCalled = 0;
	move_done = 1;
	control_state = STATE_MANUAL;
	pthread_mutex_unlock(&mutex_control);
}


void enableControl_(int enable) 
{
	printf("controlTask : enableControl called with enable=%d\n",enable);
	pthread_mutex_lock(&mutex_control);
	if(enable==CONTROL_ENABLED || enable==CONTROL_DISABLED) {
		control_enable = enable;
	}
	control_state = STATE_MANUAL;
	takeOffCalled = 0;
	landCalled = 0;
	moveCalled = 0;
	emergencyCalled = 0;
	calibHorCalled = 0;
	calibMagnCalled = 0;
	initNavDataCalled = 0;
	move_done = 0;
	pthread_mutex_unlock(&mutex_control);
}


void initNavData_()
{
	printf("controlTask : initNavData called\n");
	pthread_mutex_lock(&mutex_control);
	initNavDataCalled = 1; 
	pthread_mutex_unlock(&mutex_control);
}


void takeOff_() 
{
	printf("controlTask : takeOff called\n");
	pthread_mutex_lock(&mutex_control);
	takeOffCalled = 1;
	pthread_mutex_unlock(&mutex_control);
}


void land_() 
{
	printf("controlTask : land called\n");
	pthread_mutex_lock(&mutex_control);
	landCalled = 1;
	pthread_mutex_unlock(&mutex_control);
}


void move_(float pitch, float roll, float angular_speed, float vertical_speed) 
{
	printf("controlTask : move called\n");
	pthread_mutex_lock(&mutex_control);
	pitch_move = pitch;
	roll_move = roll;
	angular_speed_move = angular_speed;
	vertical_speed_move = vertical_speed;
	moveCalled = 1;
	pthread_mutex_unlock(&mutex_control);
}


void calibHor_() 
{
	printf("controlTask : calibHor called\n");
	pthread_mutex_lock(&mutex_control);
	calibHorCalled = 1;
	pthread_mutex_unlock(&mutex_control);
}


void calibMagn_()
{
	printf("controlTask : calibMagn called\n");
	pthread_mutex_lock(&mutex_control);
	calibMagnCalled = 1;
	pthread_mutex_unlock(&mutex_control);
}


void emergency_()
{
	printf("controlTask : emergency called\n");
	pthread_mutex_lock(&mutex_control);
	emergencyCalled = 1;
	pthread_mutex_unlock(&mutex_control);
}


/*****************************/
/**         PRIVATE         **/
/*****************************/


void checkEndOfMission_()
{
	/*if( fabs(x_cons-getX()) < PRECISION_X && fabs(y_cons-getY()) < PRECISION_Y && fabs(z_cons-getZ()) < PRECISION_Z && fabs(diff_angle(angle_cons, getAngle())) < PRECISION_ANGLE ) {
		move_done = 1;
		pthread_mutex_unlock(&mutex_control);
		executeManual();
		pthread_mutex_lock(&mutex_control);
		//sendFrame(MISSION_FRAME, 0, 0, 0, MISSION_FINISHED);
	}*/
}