#include "pthread.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>



// @brief Minimal navigation data for all flights.
 
 typedef struct _navdata _navdata; 
 struct _navdata {
  int    vbat_flying_percentage; /*!< battery voltage filtered (mV) */

  float   theta;                  /*!< UAV's pitch in milli-degrees */
  float   phi;                    /*!< UAV's roll  in milli-degrees */
  float   psi;                    /*!< UAV's yaw   in milli-degrees */

  int     altitude;               /*!< UAV's altitude in centimeters */

  float   vx;                     /*!< UAV's estimated linear velocity */
  float   vy;                     /*!< UAV's estimated linear velocity */
  float   vz;                     /*!< UAV's estimated linear velocity */
};

static pthread_mutex_t mutex_regulation = PTHREAD_MUTEX_INITIALIZER;

bool newCoordXY;
bool newCoordZ;
bool newAngle;
bool newSpeed; 

_navdata data;

void* thread_nvadata(void* arg);

float GetX(void);
float GetY(void);
float GetZ(void);
float GetAngle(void);

void Get_localization(float* x_local, float* y_local);
void Get_nvdata(float* theta, float* phi, float* psi, int* altitude, float* vx, float* vy, float* vz, int* vbat_flying_percentage);


