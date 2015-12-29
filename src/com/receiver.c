#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>


	int id_socketR = -1;
	int id_sock_bis;
	int portR = 1234;
	struct sockaddr_in adr_local; // adresse du socket distant
	int lg_adr_local;

void afficher_messageR(char *message, int lg) {
	int i;
	for (i=0;i<lg;i++)
		printf("%c", message[i]);
}


void afficher_reception (int lg_message, char * message) 
{
	printf("PUITS : Reception (%d) [", lg_message);
	afficher_messageR(message, lg_message);
	printf("]\n");
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
	return 0;
}


/* fonction appelée dans reception() */
int recevoir(int lg_message, char * message) {
	int retour;
	int num_reception;

	if ((id_sock_bis = accept(id_socketR,(struct sockaddr *) &adr_local, (socklen_t *) &lg_adr_local))== -1) {
		fprintf(stderr, "recv: Erreur accept()\n"); 
		exit(1);
	}

	/* reception */
	num_reception = 1;
	retour = 1;

	while(retour > 0) {

		retour = recv(id_sock_bis, message, lg_message, 0);
		
		if (retour == -1) {
			fprintf(stderr, "Echec de la réception\n");
			exit(1);
		}

		if (retour > 0) 
			afficher_reception(retour, message);

		num_reception++; 
	}
	
	return 0;
}


int closeReceiver() {

	/* si tcp shutdown() */
	if (shutdown(id_socketR,0) == -1) {
		fprintf(stderr, "recv: Erreur shutdown\n");
		exit(1);
	}


	/* close() */
	if (close(id_socketR) == -1) {
		fprintf(stderr, "recv: Échec de destruction du socket\n");
		exit(1);
	}
	
	return 0;
}

