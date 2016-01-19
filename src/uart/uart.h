#ifndef UART_H
#define UART_H
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */


/*
 * Function which prepare Bluetooth opening serial port
 */
void initBluetoothCom();

/*
 * Function to call on a proper program end
 */
void close_port(int fd);

/*
 * Function which open the TTY03 serial port
 */
int open_port(void);


/*
 * Function which configure the already opened serial port
 */
void serial_config(int fd);


/* 
 * blocking function which read every character from serial until "\r\n"
 */
void read_port();

/*
 * Call this function to end BT com.
 */
void closeBluetoothCom(void);

#endif
