#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <stdint.h>

#define ADDR_LEN		6
#define NUMBER_BEACONS  6
#define TTL_INIT        3

//Room width
#define W               8        
#define H               10

typedef uint8_t Address_t[ADDR_LEN]; /* 48-bit address, LSB format. */
typedef Address_t address_t;

typedef struct
{
    float x;
    float y;
}
t_location;

typedef struct
{
    address_t id;
    t_location beaconLocation;         //Exact coordinates of the beacon
    t_location detectedLocation;       //Coordinates seen by the drone when beacon is detected
}
t_beacon_parameters;

typedef struct
{
    t_beacon_parameters beaconInfo;
    int8_t rssi;
    uint8_t TTL;
}t_beacon_info;

#endif
