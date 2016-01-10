#ifndef LOCALISATION_H
#define LOCALISATION_H

#include <stdio.h>   
#include <stdlib.h>
#include <string.h>  /* String function definitions */
#include <stdint.h>
#include "parser.h"
#include "parameters.h"
#include "pthread.h"

#define NB_POS_HISTORY	120

/*
 * MEAN_FACTOR*3 cannot exceed NB_POS_HISTORY
 */
#define MEAN_FACTOR		30 

/*
 * High level initialization, have to be called in the application
 */
void initLocationComputation();

/*
 * High level application, has to be put in infinite loop
 */
void computeLocation();

/*
 * Wait and read incoming bluetooth data
 */
void detectBeacons();

/*
 * Set history of computed positions to 0;0 for each record
 */
void initPosTab();


/*
 * Checks if provided index is within tab range (if not, it may correspond to an error code)
 */
uint8_t IsIndexValid(uint8_t index);

/*
 * Checks if RSSI is negative and in range concording with BT receptor sensibility
 */
uint8_t IsRssiValid(int8_t rssi);

/*
 * Checks that computed position is in range of fixed W and H
 */
uint8_t IsPositionInTheRoom(t_location currentPos);
/*
 * Compute a position from to closest beacon, with their respective positions and RSSI
 */
void ComputeWeightedPositionFrom2Beacons(t_location* result, t_beacon_info beacon1, t_beacon_info beacon2);

/*
 * Compute a position from to closest beacon, with their respective positions and RSSI
 */
void ComputeWeightedPositionFrom3Beacons(t_location* result, t_beacon_info beacon1, t_beacon_info beacon2, t_beacon_info beacon3);

/*
 * Get number of visible number, checking each beacon, depending wther his RSSI his null or not
 */
int8_t getVisibleBeaconsNumber(int8_t* index1, int8_t* index2, int8_t* index3);

/* 
 * Function which check for detected beacon on serial line and compute current position from datas
 */
uint8_t updateCurrentLocation();

/* 
 * Function which check for detected beacon on serial line and compute current position from datas (this version use RSSIs)
 */
uint8_t updateCurrentWeightedLocation();

/*
 * Get the index of the beacon with highest RSSI, allowing to exclude some already-considered beacons
 */
int8_t getIndexOfClosestBeacon(int8_t ind1, int8_t ind2);

/*
 * Update position history, shifting all the tab and putting the last position at first index
 */
void updatePosTab(t_location current);

/*
 * Returns the current filtered position
 */
t_location getCurrentLocation(void);

#endif

