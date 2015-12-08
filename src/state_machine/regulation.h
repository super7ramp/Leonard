#ifndef _REGULATION_H
#define _REGULATION_H

#include "pthread.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

//#include "../navdata_controller.h"

static pthread_mutex_t mutex_regulation = PTHREAD_MUTEX_INITIALIZER;

//struct navdata_demo_t data;

bool newCoordXY;
bool newCoordZ;
bool newAngle;
bool newSpeed; 



void* thread_nvadata(void* arg);

float GetPitch();

float GetRoll();

float GetYaw();

float GetAngle();

void Get_localization(float* x_local, float* y_local);

void Get_nvdata(float* theta, float* phi, float* psi, int* altitude, float* vx, float* vy, float* vz, int* vbat_flying_percentage);


#endif