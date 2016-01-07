#ifndef CONTROL_COM
#define CONTROL_COM

#include <stdio.h>
#include <unistd.h>
#include <math.h>

#include <time.h>
#include <pthread.h>

#include "controlTask.h"
#include "var_coord.h"
#include "../com/params.h"
#include "../com/sender.h"
#include "../com/receiver.h"



struct coordinates_ destination;

void* thread_com(void* arg); 


#endif
