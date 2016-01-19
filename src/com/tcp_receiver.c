#include "tcp_receiver.h"


	int id_socketR = -1;
	int id_sock_bis;
	int portR = 1234;
	struct sockaddr_in adr_local; // adresse du socket distant
	int lg_adr_local;
	int user = 0;

void afficher_messageR(char *message, int lg) {
	int i;
	for (i=0;i<lg;i++)
		printf("%c", message[i]);
}


void afficher_reception (int lg_message, char * message) 
{
	pthread_mutex_lock(&displayMutex);
	printf("\033[%dA", 16);
	printf("  Drone position : ");
	afficher_messageR(message, lg_message);
	printf("\033[%dB\n", 15);
	pthread_mutex_unlock(&displayMutex);
}

int initReceiver() {
	int type_sock;

	type_sock = SOCK_STREAM;

	lg_adr_local = sizeof(adr_local);

	/* Création socket */
	if ((id_socketR = socket(AF_INET, type_sock,0)) == -1) {
		fprintf(stderr, "com: Échec de création du socket\n");
		exit(1);
	}

	/* construction @ socket */
	memset((char *)&adr_local, 0, lg_adr_local); //reset
	adr_local.sin_family = AF_INET;
	adr_local.sin_port = portR;
	adr_local.sin_addr.s_addr = INADDR_ANY;

	/* Bind() */
	if(bind(id_socketR,(struct sockaddr *) &adr_local, lg_adr_local) == -1) {
	 	fprintf(stderr, "com: Echec du bind\n");
	 	exit(1);
	}

	/* Récuperer l'adresse du socket local */
	if((getsockname(id_socketR, (struct sockaddr *) &adr_local, (socklen_t*) &lg_adr_local)) == -1) {
	 	fprintf(stderr, "com: Echec du getsockname\n");
	 	exit(1);
	}

	/* listen() et accept() */
	
		if (listen(id_socketR, 5) == -1) {
			fprintf(stderr, "com: Erreur listen()\n");
			exit(1);
		}


	if ((id_sock_bis = accept(id_socketR,(struct sockaddr *) &adr_local, (socklen_t *) &lg_adr_local))== -1) {
		fprintf(stderr, "recv: Erreur accept()\n"); 
		exit(1);
	}
	return 0;
}

/* fonction appelée dans reception() */
int recevoir(int lg_message, char * message) {
	int retour;
	int num_reception;
	
	/* reception */
	num_reception = 1;
	retour = 1;

	retour = read(id_sock_bis, message, lg_message);

	if (retour == -1) {
		fprintf(stderr, "Echec de la réception\n");
		perror("Error :");
		exit(1);
	}
	if (retour > 0 && user) 
		afficher_reception(retour, message);

	num_reception++; 
	
	return 0;
}


int closeReceiver() {

	/* si tcp shutdown() */
	if (shutdown(id_socketR,0) == -1) {
		fprintf(stderr, "recv: Erreur shutdown\n");
		exit(1);
	} 
	else 
		printf("shutdown receiver\n");

	/* close() */
	if (close(id_socketR) == -1) {
		fprintf(stderr, "recv: Échec de destruction du socket\n");
		exit(1);
	}
	else 
		printf("close receiver\n");
	
	
	printf("Receiver : fin\n");
	return 0;
}


void setUser(int u) {
	user = u;
}

