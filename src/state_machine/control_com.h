#ifndef CONTROL_COM
#define CONTROL_COM

#include <stdio.h>
#include <unistd.h>
#include <math.h>

#include <time.h>
#include <pthread.h>

#include "controlTask.h"
#include "var_coord.h"
#include "../com/parameters.h"
#include "../com/tcp_sender.h"
#include "../com/tcp_receiver.h"
#include "../com/message_drone.h"



struct coordinates_ dest;

void* thread_com(void* arg); 


#endif
