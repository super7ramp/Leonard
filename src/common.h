/* common.h -- Common definitions
 * Copyright (C) 2015 Adrien Barre, Antoine Belvire, Valentin Douais, Alexis Lothoré, Lucille Saade
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#ifndef COMMON_H
#define COMMON_H

#define NUMBER_BEACONS 	8 

//Room width
#define W               (7.80)        
#define H               (12.0)




typedef enum
{
    ARDRONE_CALIBRATION_DEVICE_MAGNETOMETER = 0,
    ARDRONE_CALIBRATION_DEVICE_NUMBER,
} ardrone_calibration_device_t;

typedef struct pcmd
{
   int progressive;     //[flag]
   float lrTilt;        //[roll]
   float fbTilt;        //[pitch]
   float verticalSpeed; //[gaz]
   float angularSpeed;  //[yaw]
} pcmd_t;

typedef struct pcmd_mag
{
    int progressive;        //[flag]
    float lrTilt;           //[roll]
    float fbTilt;           //[pitch]
    float verticalSpeed;    //[gaz]
    float angularSpeed;     //[yaw]
    float magPsi;
    float magPsiAccuracy;
} pcmd_mag_t;

#endif
