#include <time.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "controlTask.h"        //Pour le thread de la machine d'état activer toutes les 30ms.
#include "control_com.h"        //Pour le thread de la communication WiFi.
#include "regulation.h"  
#include "bluetooth_com.h"       


int main(int argc, char *argv[]) 
{
  pthread_t threadCom ;
  pthread_t threadControl;
  pthread_t threadBluetooth;
  printf("Lancement des threads---------------------------- \n");

  printf("\nStart\n\n") ;

  if(pthread_create(&threadCom, NULL, thread_com, NULL) == -1) 
  {
    perror("pthread_create");
    return 1;
  }
  /*if(pthread_create(&threadControl, NULL, controlTask, NULL) == -1) 
  {
    perror("pthread_create");
    return 1;
  }*/
  
  if(pthread_create(&threadBluetooth, NULL, thread_Bluetooth, NULL) == -1)
  {
    perror("pthread_create");
    return 1;
  }
  if (pthread_join(threadCom, NULL))
  {
    perror("pthread_join");
    return 1;
  }
  /*if (pthread_join(threadControl, NULL)) 
  {
    perror("pthread_join");
    return 1;
  }
  /*
  if (pthread_join(threadBluetooth, NULL)) 
  {
    perror("pthread_join");
    return 1;
  }*/

  printf("\nEnd\n\n");

  return 0 ;  
}
