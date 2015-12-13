#ifndef LOCALISATION_H
#define LOCALISATION_H


void updateCurrentLocation();

// return the closest beacon different from beacon in1 and beacon in2 if in1, in2!=-1
uint8_t getIndexOfCloserBeacon(int8_t ind1, int8_t ind2);

// GETTER
t_location getCurrentLocation(void);

#endif

