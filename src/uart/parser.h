#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <stdint.h>
#include"parameters.h"

#define TAB_ADDR_LEN ADDR_LEN*2+1


typedef struct
{
    address_t address;
    int8_t rssi;
}
t_data;


// extract data from one message received
t_data extract_data(char * data);
void convertToAddress(address_t * res, char * address);
int8_t findBeaconInTab(address_t addr);
int compareAddresses(address_t addrA, address_t addrB);
void updateBeaconTab(address_t addr, int8_t rssi);
int8_t getBeaconRssi(uint8_t index);
uint8_t getBeaconTTL(uint8_t index);
const t_beacon_info* getBeaconTab(void);
void refreshBeaconTTL(uint8_t index);
void decreaseAllTTLs(void);


// GETTER
int8_t getBeaconRssi(uint8_t index);
uint8_t getBeaconTTL(uint8_t index);
const t_beacon_info* getBeaconTab(void);


#endif
