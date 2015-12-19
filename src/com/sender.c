#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>



int id_socketS = -1;
int portS = 1234;


void construire_message(char *message, char motif, int lg) {
	int i;
	for (i=0;i<lg;i++)
		message[i] = motif;
}

void afficher_messageS(char *message, int lg) {
	int i;
	for (i=0;i<lg;i++)
		printf("%c", message[i]);
}




void afficher_envoi (int num_envoi, int lg_message, char * message) {
	printf("SOURCE : Envoi n°%d (%d) [", num_envoi, lg_message);
	printf("%5d", num_envoi); // On code le numéro sur 5 caractères ASCII
	afficher_messageS(message, lg_message);
	printf("]\n");
}


int initSender( char * nom_station) {

	int type_sock ;
	
 	type_sock = SOCK_STREAM;
	 
	struct sockaddr_in adr_distant; // adresse du socket distant
	int lg_adr_distant = sizeof(adr_distant);
	struct hostent * hote;

	int retour;

	if ((id_socketS = socket(AF_INET, type_sock,0)) == -1) {
		fprintf(stderr, "tsock: Échec de création du socket\n");
		exit(1);
	}

	/* adressage */
	memset((char *)&adr_distant, 0, lg_adr_distant); //reset
	adr_distant.sin_family = AF_INET;
	adr_distant.sin_port = portS;

	if ((hote = gethostbyname(nom_station)) == NULL) {
		fprintf(stderr, "tsock: Erreur gethostbyname\n") ;
		exit(1); 
	}

	memcpy((char *)&(adr_distant.sin_addr.s_addr),hote->h_addr,hote->h_length); 

	/* connect() */
	retour = connect(id_socketS, (struct sockaddr *) &adr_distant, (socklen_t) lg_adr_distant);
	if (retour == -1) {
		fprintf(stderr, "tsock: Erreur connect()\n");
		exit(1);
	}
	
	return 0;
}


int emettre(int lg_message, char * message, int nb_message) 
{
	int i;
	int retour;

	/* send() */
	for (i = 1 ; i <= nb_message ; i++) {
		construire_message(message, 'a'+(i-1)%26, lg_message); 
		
		retour = write(id_socketS, message, lg_message) ;
		if (retour == -1) {
			fprintf(stderr, "tsock: Erreur envoi\n");
			exit(1);
		}
		afficher_envoi(i, retour, message); // retour = longueur message envoyé
	}


	return 0; // tout s'est bien passé

}



int closeSender()
{
	/* shutdown() */
	
		if (shutdown(id_socketS,1) == -1) {
			fprintf(stderr, "tsock: Erreur shutdown\n");
			exit(1);
		}
	

	/* close() */
	if (close(id_socketS) == -1) {
		fprintf(stderr, "tsock: Échec de destruction du socket\n");
		exit(1);
	}

	printf("SOURCE : fin\n");
	return 0;

}

