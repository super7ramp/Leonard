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

char beaconsLocation[NUMBER_BEACONS][10] = {
	"0 0",
	"0 5",
	"0 10",
	"8 10",
	"8 5",
	"8 0"
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
		
		pthread_mutex_lock(&messageMutex);
		emettre(lg_message, msgSend, "-1 -1");
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
	*n = 5;
	
	char * adr = malloc(12*sizeof(char));
	adr = ADR_DIST;
	
	

	
	msgSend = malloc(sizeof(char)*lg_message);
	msgRcv = malloc(sizeof(char)*lg_message);
	
	pthread_t tid[2];
	pthread_create(&tid[0], NULL, receiverThread, NULL);
	
	// initialisation socket sender.
	// initialisation ici car on a besoin d'un receiver à l'écoute pour lancer le sender, donc pour le test en localhost on le fait après le receiver
	printf("before %s\n", adr);
	initSender(adr);
	printf("%s\n", adr);
	
	pthread_create(&tid[1], NULL, coordinatesThread, n);
	
	while(1) {

		printf("Veuillez choisir l'endroit où le drone doit aller (de 0 à 7)\n");
		printf("Pour fermer le programme tapez -1\n");
		scanf("%d", &choix);
		getchar();
		printf("%d\n", choix);
		
		if (choix >= 0 && choix <= 7) {
			pthread_mutex_lock(&messageMutex);
			emettre(lg_message, msgSend, beaconsLocation[choix]);
			pthread_mutex_unlock(&messageMutex);
		}
		else if (choix == -1) {
			pthread_cancel(tid[0]);
			pthread_cancel(tid[1]);
			closeSender();
			closeReceiver();
			break;
		}
		else {
			printf("Le choix est incorrect\n");
		}
	}
	
	
	// pthread_exit(NULL);
	
	return 0;
}







