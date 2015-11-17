#ifndef COMMON_H
#define COMMON_H

typedef enum
{
    ARDRONE_CALIBRATION_DEVICE_MAGNETOMETER = 0,
    ARDRONE_CALIBRATION_DEVICE_NUMBER,
} ardrone_calibration_device_t;

typedef struct pcmd
{
   int progressive;		//[flag]	
   float lrTilt;		//[roll]
   float fbTilt;		//[pitch]
   float verticalSpeed;	//[gaz]
   float angularSpeed;	//[yaw]
} pcmd_t;

typedef struct pcmd_mag
{
   	int progressive;		//[flag]	
   	float lrTilt;		//[roll]
   	float fbTilt;		//[pitch]
   	float verticalSpeed;	//[gaz]
   	float angularSpeed;	//[yaw]
	float magPsi;
	float magPsiAccuracy;
} pcmd_mag_t;
#endif
