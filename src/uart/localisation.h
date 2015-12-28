#ifndef LOCALISATION_H
#define LOCALISATION_H

#include <stdio.h>   
#include <stdlib.h>
#include "parameters.h"


void UpdateCurrentLocation();

// return the closest beacon different from beacon in1 and beacon in2 if in1, in2!=-1
uint8_t getIndexOfCloserBeacon(int8_t ind1, int8_t ind2);
// return the number of currently visible beacons
uint8_t getVisibleBeaconsNumber(void);
//Check that detected index is in range of beacon Tab
uint8_t IsIndexValid(uint8_t index);
// GETTER
t_location getCurrentLocation(void);


#endif

