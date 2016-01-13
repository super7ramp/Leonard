/**
 * \file controlTask.h
 *
 * \brief Control the drone, send a frame each 30ms.
 *
 * \author Thomas Hoet
 *
 * \date 3 Dec 2014
 */
 
#ifndef CONTROLTASK_H
#define CONTROLTASK_H

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>

#include "../com/message_drone.h"
#include "KCG/system_state_machine.h"
#include "regulation.h"
#include "var_coord.h"
#include "../navdata/navdata_controller.h"
#include "../shortest_path.h"
#include "../map/map_reader.h"
#include "../map/map_common.h"
#include "../movement/movement.h"

/**
 * \brief State of the control task : manual (drone controled by the user).
 */
#define STATE_MANUAL 0

/**
 * \brief State of the control task : mission (the drone control itself).
 */
#define STATE_MISSION 1

/**
 * \brief The control taks is running.
 */
#define CONTROL_ENABLED 0
#define CONTROL_ENABLED_SCADE 1

/**
 * \brief The control taks is not running.
 */
#define CONTROL_DISABLED 1
#define CONTROL_DISABLED_SCADE 0
/**
 * \brief Precision to determine the end of the mission (m).
 */
#define PRECISION_X (float)0.5	

/**
 * \brief Precision to determine the end of the mission (m).
 */
#define PRECISION_Y (float)0.5	

/**
 * \brief Precision to determine the end of the mission (m).
 */ 
#define PRECISION_Z (float)0.2	

/**
 * \brief Precision to determine the end of the mission (m).
 */
#define PRECISION_ANGLE (float)10.0

/**
 * \brief Amplitude of the movement (right/left/forward/backward).
 */
#define MOVE_AMPLITUDE 0.4

/**
 * \brief Amplitude of the movement (vertical and angular speed).
 */
#define SPEED_AMPLITUDE 0.6

#define PI (float)3.141592653589793

/**
 * \brief Period of the control task (ms).
 */
#define CONTROLTASK_PERIOD_CONTROLE_MS 30

/**
 * \definition of the name of the map
 */
#define NAME_MAP_DEMO "demo_map"

/**
 * \brief Control task. This task manages le movement of the drone.
 * \param[in]	arg
 */
void *controlTask(void *arg);


/**
 * \brief Set the state of the task to manual : the drone is controled by the user.
 */
void executeManual();

/**
 * \brief Enable or disable the control task on the drone.
 * \param[in]	enable CONTROL_ENABLED or CONTROL_DISABLED
 */
void enableControl(int enable);

/**
 * \brief The drone takes off.
 */
void takeOff();

/**
 * \brief The drone lands.
 */
void land();

/**
 * \brief The drone move in any direction.
 */
void move_PitchRoll(direction pitch_dir, direction roll_dir, float p_power, float r_power);

/**
 * \brief The drone move left or right.
 */
void move_Pitch(direction pitch_dir, float p_power);

/**
 * \brief The drone move front or back.
 */
void move_Roll(direction roll_dir, float r_power);

/**
 * \brief The drone move front or back.
 */
void move_Yaw(direction yaw_dir, float y_power);

/**
 * \brief start mission for guide person with drone
 */
 void start_mission(float x_map, float y_map);

 /**
 * \brief end mission for guide person with drone
 */
 void stop_mission();

/**
 * \brief Calibrate the horizontal plane of the drone (must be landed).
 */
void calibHor();

/**
 * \brief Calibrate the magnetometer of the drone (must be flying).
 */
void calibMagn();

/**
 * \brief Go in emergency mode (green leds to red leds).
 */
void emergency_();

/**
 * \brief Leave the emergency mode (red leds to green leds).
 */
void anti_emergency_();
/**
 * PRIVATE
 */

void SWITCH_DRONE_COMMANDE(int order);
 

Navdata return_navdata();
//structure for coordinates
struct coordinates_ destination;

//structure for different direction
direction gofindygo;

//Input and Outpu for SCADE
inC_system_state_machine inC;
outC_system_state_machine outC;

//Données de navigation
Navdata Main_Nav;

//declaration of graph
graph_t *graph;

float nav_prec, nav_suiv;

/**
 * \brief Mutex to protect the control task data.
 */
static pthread_mutex_t mutex_control = PTHREAD_MUTEX_INITIALIZER;


int control_enable;
int control_state;
int seqNumber;
float x_cons;
float y_cons;
float z_cons;
float angle_cons;

//FLAGS
int takeOffCalled;
int initNavDataCalled;
int landCalled;
int moveCalled;
int emergencyCalled;
int calibHorCalled;
int calibMagnCalled;
int rollpitchCalled;
int rollCalled;
int pitchCalled;
int yawCalled;
int own_position;
//END FLAGS

direction pitch_move;
direction roll_move;
direction yaw_move;
float pitch_power;
float roll_power;
float yaw_power;
float angular_speed_move;
float vertical_speed_move;
float power;

#endif
