#ifndef LOCALISATION_H
#define LOCALISATION_H

#include <stdio.h>   
#include <stdlib.h>
#include "parameters.h"


void UpdateCurrentLocation();

// return the closest beacon different from beacon in1 and beacon in2 if in1, in2!=-1
uint8_t getIndexOfCloserBeacon(int8_t ind1, int8_t ind2);

// GETTER
t_location getCurrentLocation(void);


#endif

