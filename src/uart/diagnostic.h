#ifndef DIAGNOSTIC_H
#define DIAGNOSTIC_H

#include "uart.h"
#include "parser.h"
#include "parameters.h"
#include "signal.h"
#include "stdlib.h"

/*
 * @brief Init the found beacons to 0
 */
void initBeaconCheckTab(void);

/*
 * @brief Display, for each beacon, if the beacon has been seen at least once
 */
void displayCheckResult(void);

/*
 * @brief Check each beacon and put an end to the program if all beacons have been seen at least once
 */
uint8_t checkDetectedBeacon(void);

/*
 *@brief Capture Ctrl+C
 */
void endHandler(int arg); 





#endif
