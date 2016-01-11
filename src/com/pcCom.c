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

char beaconsLocation[NUMBER_BEACONS][20];


void initBeaconsLocation(char beacon[NUMBER_BEACONS][20], int size) {
	sprintf(beacon[0], "0.00  0.00 ");
	sprintf(beacon[1], "0.00  %2.2f ", (float) H/2);
	sprintf(beacon[2], "0.00  %2.2f ", (float) H);
	sprintf(beacon[3], "%2.2f  %2.2f ", (float) W, (float) H);
	sprintf(beacon[4], "%2.2f  %2.2f ", (float) W, (float) H/2);
	sprintf(beacon[5], "%2.2f  0.00 ", (float) W);
	sprintf(beacon[6], "%2.2f  %2.2f ", (float) W/2, (float) H/4);
	sprintf(beacon[7], "%2.2f  %2.2f ", (float) W/2, (float) 3*H/4);
	
	int i;
	for (i=0; i<8; i ++)
		printf(" %d : %s\n", i, beacon[i]);
}


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
		emettre(lg_message, msgSend, "11 ");
		pthread_mutex_unlock(&messageMutex);
	}
	
	return NULL;
}



int main (int argc, char** argv)
{
	int choix;
	int lg_message = LG_MESS_DEFAUT;
	int *n;
	char * msg = malloc(sizeof(char)*lg_message);
	
	initBeaconsLocation(beaconsLocation, (int) NUMBER_BEACONS);
	
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

		printf("Que souhaitez vous faire ?\n");
		printf("0 -> Calibration (le drone doit être posé à plat)\n");
		printf("1 -> Calibration magnétique\n");
		printf("2 -> landing\n");
		printf("3 -> take off\n");
		printf("4 -> move roll \n");
		printf("5 -> move pitch\n");
		printf("6 -> move pitch roll\n");
		printf("7 -> emergency\n");
		printf("8 -> anti emergency\n");
		printf("9 -> start mission\n");
		printf("10 -> stop mission\n");
		printf("Pour fermer le programme tapez -1\n");
		scanf("%d", &choix);
		getchar();
		printf("%d\n", choix);
		
		sprintf(msg, "%d ", choix);
			
		if (choix == 9) {
			printf("\n\nChoissisez où envoyer le drone (de 0 à 7)\n");
			printf("0 -> %s\n", beaconsLocation[0]);
			printf("1 -> %s\n", beaconsLocation[1]);
			printf("2 -> %s\n", beaconsLocation[2]);
			printf("3 -> %s\n", beaconsLocation[3]);
			printf("4 -> %s\n", beaconsLocation[4]);
			printf("5 -> %s\n", beaconsLocation[5]);
			printf("6 -> %s\n", beaconsLocation[6]);
			printf("7 -> %s\n", beaconsLocation[7]);
			scanf("%d", &choix);
			strcat(msg, beaconsLocation[choix]);
			printf("######## msg : %s\n", msg);
			pthread_mutex_lock(&messageMutex);
			emettre(lg_message, msgSend, msg);
			pthread_mutex_unlock(&messageMutex);
		}
		else if (choix >= 0 && choix <= 10) {
			pthread_mutex_lock(&messageMutex);
			emettre(lg_message, msgSend, msg);
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







