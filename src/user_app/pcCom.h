#ifndef PCCOM_H
#define PCCOM_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include "sender.h"
#include "receiver.h"
#include "../common.h"

#define LG_MESS_DEFAUT	30
#define ADR_DIST	"127.0.0.1"
//#define ADR_DIST "192.168.1.1"

#endif

