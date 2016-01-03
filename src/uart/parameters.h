#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <stdint.h>
#include <time.h>

#define ADDR_LEN		6
#define NUMBER_BEACONS 	8 
#define TTL_INIT        3

//Room width
#define W               8        
#define H               10

#define MINIMAL_SERIAL_READ_LENGTH 14

#define BLE_NANO_SENSI		(-100)

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
    double TTL;
}t_beacon_info;

#endif
