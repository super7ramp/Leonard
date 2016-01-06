#ifndef UART_H
#define UART_H
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include "display.h"

void parseSerialRead(char *buffer);
int checkAnswer(char *response);
void serial_config(int fd);
int open_port(void);
void openSerialCom();
void read_port();
void close_port(int fd);
void initBluetoothCom();
void readBluetoothData();

#endif
