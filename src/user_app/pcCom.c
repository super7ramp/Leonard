#include "pcCom.h"


pthread_mutex_t messageMutex = PTHREAD_MUTEX_INITIALIZER;
char * msgSend, * msgRcv;

char beaconsLocation[NUMBER_BEACONS][20];


void initBeaconsLocation(char beacon[NUMBER_BEACONS][20], int size) {

    // This is hard coded
    // We could reuse functions in the shortest_path folder (map_common.h for example)
    // But this means we have to compile them in both architectures (x86 and arm), which
    // is not handled yet
    float margin = 1.1;
    sprintf(beacon[0], "%.2f  %.2f ", margin, margin);
    sprintf(beacon[1], "%.2f  %.2f ", margin, (float) H/2);
    sprintf(beacon[2], "%.2f  %.2f ", margin, (float) H - margin);
    sprintf(beacon[3], "%.2f  %.2f ", (float) W - margin, (float) H - margin);
    sprintf(beacon[4], "%.2f  %.2f ", (float) W - margin, (float) H/2);
    sprintf(beacon[5], "%.2f  %.2f ", (float) W - margin, margin);
    sprintf(beacon[6], "%.2f  %.2f ", (float) W/2, (float) H/4 - margin);
    sprintf(beacon[7], "%.2f  %.2f ", (float) W/2, (float) 3*H/4 - margin);

    /*int i;
    for (i=0; i<8; i ++)
        printf(" %d : %s\n", i, beacon[i]);
    */
}


void * receiverThread(void* arg)
{
	int lg_message = LG_MESS_DEFAUT;
	
	initReceiver();
	setUser(1);
	while(1)
		recevoir(lg_message, msgRcv);
	return NULL;
}



void * coordinatesThread(void* arg)
{
	int lg_message = LG_MESS_DEFAUT;
	int n = *((int*)arg);
	
	while (1) {
		sleep(1);
		
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
	
	pthread_mutex_t displayMutex = PTHREAD_MUTEX_INITIALIZER;
	initBeaconsLocation(beaconsLocation, (int) NUMBER_BEACONS);
	
	n = malloc(sizeof(int));
	//*n = 500000;
	*n = 1;
	
	char * adr = malloc(12*sizeof(char));
	adr = ADR_DIST;
	
	msgSend = malloc(sizeof(char)*lg_message);
	msgRcv = malloc(sizeof(char)*lg_message);
	
	pthread_t tid[2];
	pthread_create(&tid[0], NULL, receiverThread, NULL);
	
	// initialisation socket sender.
	// initialisation ici car on a besoin d'un receiver à l'écoute pour lancer le sender, donc pour le test en localhost on le fait après le receiver
	//printf("before %s\n", adr);
	usleep(30000);
	initSender(adr);
	//printf("%s\n", adr);
	
	pthread_create(&tid[1], NULL, coordinatesThread, n);
	
	pthread_mutex_lock(&displayMutex);
	printf("\n  Drone position : \n");
	printf("  Send : \n\n");
	pthread_mutex_unlock(&displayMutex);
	
	while(1) {

		pthread_mutex_lock(&displayMutex);
		printf("What do you want to do ?\n");
		printf("0 -> Calibration (drone must lay flat on the floor)\n");
		printf("1 -> Magnetic calibration\n");
		printf("2 -> landing\n");
		printf("3 -> take off\n");
		printf("4 -> move roll \n");
		printf("5 -> move pitch\n");
		printf("6 -> move pitch roll\n");
		printf("7 -> emergency\n");
		printf("8 -> anti emergency\n");
		printf("9 -> start mission\n");
		printf("10 -> stop mission\n");
		printf("-1 to close the programm\n");
		
		pthread_mutex_unlock(&displayMutex);
		
		scanf("%d", &choix);
		getchar();	
	
		pthread_mutex_lock(&displayMutex);
		printf("\033[%dA", 2);
		printf("\033[%dM", 1);	
		printf("\033[%dJ", 2);
		pthread_mutex_unlock(&displayMutex);	
		
		if (choix >= 0 && choix < 10) {
			sprintf(msg, " %d ", choix);
		}
		else {
			sprintf(msg, "%d ", choix);
		}
		
			
		if (choix == 9) {
		
			pthread_mutex_lock(&displayMutex);
			printf("\033[%dA", 12);
			printf("\033[%dM", 12);
		
			printf("Choose your beacon (from 0 to 7)\n");
			printf("0 -> %s\n", beaconsLocation[0]);
			printf("1 -> %s\n", beaconsLocation[1]);
			printf("2 -> %s\n", beaconsLocation[2]);
			printf("3 -> %s\n", beaconsLocation[3]);
			printf("4 -> %s\n", beaconsLocation[4]);
			printf("5 -> %s\n", beaconsLocation[5]);
			printf("6 -> %s\n", beaconsLocation[6]);
			printf("7 -> %s\n", beaconsLocation[7]);
			printf("\n\n");
			pthread_mutex_unlock(&displayMutex);
			
			scanf("%d", &choix);
			strcat(msg, beaconsLocation[choix]);
			//printf("######## msg : %s\n", msg);
			
			if (choix >= 0 && choix <=7) {
				pthread_mutex_lock(&messageMutex);
				emettre(lg_message, msgSend, msg);
				pthread_mutex_unlock(&messageMutex);
			
			}
			else {
				pthread_mutex_lock(&displayMutex);
				printf("incorrect choice\n");	
				pthread_mutex_unlock(&displayMutex);
			}
				pthread_mutex_lock(&displayMutex);
				printf("\033[%dA", 12);
				printf("\033[%dM", 12);
				printf("\033[%dJ", 2);
				pthread_mutex_unlock(&displayMutex);
		
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
			pthread_mutex_lock(&displayMutex);
			printf("incorrect choice\n");	
			pthread_mutex_unlock(&displayMutex);
		}
	}
	
	
	// pthread_exit(NULL);
	
	return 0;
}






