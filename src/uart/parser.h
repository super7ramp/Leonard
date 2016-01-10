#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <stdint.h>
#include <sys/time.h>
#include "uart.h"
#include "parameters.h"

#define MINIMAL_SERIAL_READ_LENGTH 	(14)
#define TTL_MAX_MS 					(3000)
#define BLE_NANO_SENSI				(-105.0)


/*
 * Function which call for read on uart and extract beacon data to put them in beacon tab
 */
void extract_data();

/*
 * Returns a beacon index (between 0 & NUMBEr_BEACONS), searching it by his adress
 */
int8_t compareAddresses(address_t addrA, address_t addrB);

/*
 * Update the stored RSSI of a recently detected beacon
 */ 
void updateDetectedBeaconRssi(address_t addr, int8_t rssi);

/*
 * Update the stored TTl of a recently detected beacon, putting current timestamp
 */
void refreshBeaconTTL(uint8_t index);

/*
 * Check that beacons in table have beed detected a least once during a fixed period of time, else consider them not visible anymore and delete them from table
 */
void checkBeaconsTTL();

/*
 * Return RSSI of beacon selected by his index
 */
int8_t getBeaconRssi(uint8_t index);

/*
 * Return TTL of a beacon selected by his index
 */
long long getBeaconTTL(uint8_t index);

/*
 * Print beacon Table with current RSSI
 */ 
void printBeaconsTab();

/*
 * Print list of beacon which have RSSI different from 0
 */
void printVisibleBeacons(void);

/*
 * Function which return the beaconTab structure
 */
const t_beacon_info* getBeaconTab(void);

#endif
