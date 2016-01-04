#ifndef LOCALISATION_H
#define LOCALISATION_H

#include <stdio.h>   
#include <stdlib.h>
#include "parameters.h"


void UpdateCurrentLocation();
void UpdateCurrentWeightedLocation();
void ComputeWeightedPositionFrom2Beacons(t_location* result, t_beacon_info beacon1, t_beacon_info beacon2);
void ComputeWeightedPositionFrom3Beacons(t_location* result, t_beacon_info beacon1, t_beacon_info beacon2, t_beacon_info beacon3);

void checkBeaconInfoConsistency(int8_t r, int8_t a, int8_t b, int8_t c);
// return the closest beacon different from beacon in1 and beacon in2 if in1, in2!=-1
int8_t getIndexOfCloserBeacon(int8_t ind1, int8_t ind2);
// return the number of currently visible beacons
int8_t getVisibleBeaconsNumber(void);
//Check that detected index is in range of beacon Tab
uint8_t IsIndexValid(uint8_t index);
// GETTER
t_location getCurrentLocation(void);


#endif

