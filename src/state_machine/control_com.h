#ifndef CONTROL_COM
#define CONTROL_COM

#include <stdio.h>
#include <unistd.h>
#include <math.h>

#include <time.h>
#include <pthread.h>

#include "controlTask.h"
#include "var_coord.h"

#define DONE 	 0
#define NOTDONE  1

struct coordinates_ destination;

void* thread_com(void* arg); 


#endif