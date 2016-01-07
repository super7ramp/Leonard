#ifndef LOCALISATION_H
#define LOCALISATION_H

#include <stdio.h>   
#include <stdlib.h>
#include <string.h>  /* String function definitions */
#include <stdint.h>
#include "parser.h"
#include "parameters.h"

#define NB_POS_HISTORY	10

void UpdateCurrentLocation();
void UpdateCurrentWeightedLocation();
void ComputeWeightedPositionFrom2Beacons(t_location* result, t_beacon_info beacon1, t_beacon_info beacon2);
void ComputeWeightedPositionFrom3Beacons(t_location* result, t_beacon_info beacon1, t_beacon_info beacon2, t_beacon_info beacon3);

// return the closest beacon different from beacon in1 and beacon in2 if in1, in2!=-1
int8_t getIndexOfCloserBeacon(int8_t ind1, int8_t ind2);
// return the number of currently visible beacons
int8_t getVisibleBeaconsNumber(int8_t* index1, int8_t* index2, int8_t* index3);
//Check that detected index is in range of beacon Tab
uint8_t IsIndexValid(uint8_t index);

void initPosTab();

t_location getCurrentLocation(void);

void updatePosTab(t_location current);

t_location getCurrentLocation(void);

void initLocationComputation();

void computeLocation();


#endif

