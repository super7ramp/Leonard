#ifndef LOCALISATION_H
#define LOCALISATION_H


void updateCurrentLocation();

uint8_t getIndexOfCloserBeacon(int8_t in1, int8_t i2);

// GETTER
t_location getCurrentLocation(void);

#endif

