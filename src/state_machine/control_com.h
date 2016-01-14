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
#include "../com/at-sender.h"
#include "../user_app/receiver.h"



struct coordinates_ dest;

void* thread_com(void* arg); 


#endif
