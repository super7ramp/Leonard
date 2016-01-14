#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <stdint.h>
#include "../common.h"
#define ADDR_LEN		6




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
}
t_beacon_parameters;

typedef struct
{
    t_beacon_parameters beaconInfo;
    int8_t rssi;
    long long TTL;
}t_beacon_info;

#endif
