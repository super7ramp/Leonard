#ifndef COMMON_H
#define COMMON_H

typedef enum
{
    ARDRONE_CALIBRATION_DEVICE_MAGNETOMETER = 0,
    ARDRONE_CALIBRATION_DEVICE_NUMBER,
} ardrone_calibration_device_t;

typedef struct pcmd
{
   int progressive;
   float lrTilt;
   float fbTilt;
   float verticalSpeed;
   float angularSpeed;
   float magPsi;
} pcmd_t;

#endif
