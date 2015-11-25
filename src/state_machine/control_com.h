#ifndef CONTROL_COM
#define CONTROL_COM

#include <stdio.h>
#include <unistd.h>
#include <math.h>

#include <time.h>
#include <pthread.h>

#include "controlTask.h"
#include "regulation.h"

void* thread_com(void* arg);

#endif