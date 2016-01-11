#ifndef BLUETOOTH_COM_H
#define BLUETOOTH_COM_H

#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> //nécessaire pour le structure time
#include <time.h>
#include <pthread.h>
#include "../uart/localisation.h"
#include "driver_uart.h"
#include "var_coord.h"

#define CONTROLTASK_PERIOD_BLUETOOTH_MS 1000 //wait one second (period)

void *thread_Bluetooth(void *arg);
void read_data_bluetooth(float *x, float *y);
void data_to_coordinates();

#endif
