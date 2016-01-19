#include "tcp_sender.h"

int id_socketS = -1;
int portS = 1234;


void afficher_messageS(char *message, int lg) {
	int i;
	for (i=0;i<lg;i++)
		printf("%c", message[i]);
}




void afficher_envoi (int lg_message, char * message) {

	pthread_mutex_lock(&displayMutex);
	printf("\033[%dA", 15);
	printf("  Send : [");
	afficher_messageS(message, lg_message);
	printf("]");
	printf("\033[%dB\n", 14);
	pthread_mutex_unlock(&displayMutex);
}


int initSender( char * nom_station) {

	int type_sock ;
	
 	type_sock = SOCK_STREAM;
	 
	struct sockaddr_in adr_distant; // adresse du socket distant
	int lg_adr_distant = sizeof(adr_distant);
	struct hostent * hote;

	int retour;

	if ((id_socketS = socket(AF_INET, type_sock,0)) == -1) {
		fprintf(stderr, "com: Échec de création du socket\n");
		exit(1);
	}

	/* adressage */
	memset((char *)&adr_distant, 0, lg_adr_distant); //reset
	adr_distant.sin_family = AF_INET;
	adr_distant.sin_port = portS;

	if ((hote = gethostbyname(nom_station)) == NULL) {
		fprintf(stderr, "com: Erreur gethostbyname\n") ;
		exit(1); 
	}

	memcpy((char *)&(adr_distant.sin_addr.s_addr),hote->h_addr,hote->h_length); 

	/* connect() */
	retour = connect(id_socketS, (struct sockaddr *) &adr_distant, (socklen_t) lg_adr_distant);
	if (retour == -1) {
		fprintf(stderr, "com: Erreur connect()\n");
		exit(1);
	}
	
	return 0;
}


int emettre(int lg_message, char * message, char * contenu) 
{
	int retour;

	/* send() */
	strcpy(message, contenu); 
		
	retour = write(id_socketS, message, lg_message) ;
	if (retour == -1) {
		fprintf(stderr, "send: Erreur envoi\n");
		exit(1);
	}
	afficher_envoi(retour, message); // retour = longueur message envoyé
  
	return 0; // tout s'est bien passé

}



int closeSender()
{
	/* shutdown() */
	
	if (shutdown(id_socketS,1) == -1) {
		fprintf(stderr, "send: Erreur shutdown\n");
		exit(1);
	}
	else 
		printf("shutdown sender\n");
	

	/* close() */
	if (close(id_socketS) == -1) {
		fprintf(stderr, "send: Échec de destruction du socket\n");
		exit(1);
	}
	else 
		printf("close sender\n");
	
	printf("Sender : fin\n");
	return 0;

}
