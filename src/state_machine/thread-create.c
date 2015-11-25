#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "controlTask.h"
#include "control_com.h"

  struct timeval tp;
  struct timespec ts;

int main(int argc, char *argv[]) 
{
  pthread_t threadCom ;
  pthread_t threadControl ;

  printf("\nStart\n\n") ;

  if(pthread_create(&threadCom, NULL, thread_com, NULL) == -1) 
  {
    perror("pthread_create");
    return 1;
  }
  if(pthread_create(&threadControl, NULL, controlTask, NULL) == -1)
  {
    perror("pthread_create");
    return 1;
  }
  if (pthread_join(threadCom, NULL))
  {
    perror("pthread_join");
    return 1;
  }

  if (pthread_join(threadControl, NULL)) 
  {
    perror("pthread_join");
    return 1;
  }

  printf("\nEnd\n\n");

  return 0 ;  
}