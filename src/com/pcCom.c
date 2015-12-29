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
#include "params.h"


pthread_mutex_t messageMutex = PTHREAD_MUTEX_INITIALIZER;
char * msgSend, * msgRcv;

t_location beaconsLocation[NUMBER_BEACONS] = {
	{0,0}
	{0,5}
	{0,10}
	{8,10}
	{8,5}
	{8,0}
	};


void * receiverThread(void* arg)
{
	int lg_message = LG_MESS_DEFAUT;
	
	initReceiver();
	
	recevoir(lg_message, msgRcv);
		
	return NULL;
}



void * coordinatesThread(void* arg)
{
	int lg_message = LG_MESS_DEFAUT;
	int n = *((int*)arg);
	
	while (1) {
		sleep(n);
		//initSender();
	
		pthread_mutex_lock(&messageMutex);
		//emettre(lg_message, msgSend, "-1 -1");
		pthread_mutex_unlock(&messageMutex);
	}
	
	return NULL;
}



int main (int argc, char** argv)
{
	int choix;
	int lg_message = LG_MESS_DEFAUT;
	int *n;
	n = malloc(sizeof(int));
	*n = 1;
	
	msgSend = malloc(sizeof(char)*lg_message);
	msgRcv = malloc(sizeof(char)*lg_message);
	
	pthread_t tid[2];
	pthread_create(&tid[0], NULL, receiverThread, NULL);
	pthread_create(&tid[1], NULL, coordinatesThread, n);
	
	while(1) {

		printf("Veuillez choisir l'endroit où le drone doit aller (de 0 à 7)\n");
		printf("Pour fermer le programme tapez -1\n");
		scanf("%d\n", &choix);
		
		printf("%d\n", choix);
	}
	
	
	// pthread_cancel(tid[i]);
	// pthread_exit(NULL);
	
	return 0;
}







