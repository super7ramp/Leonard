#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include "sender.h"
#include "receiver.h"


#define NB_MESS_ENV_DEFAUT 10
#define LG_MESS_DEFAUT 30


int main(int argc, char ** argv) 
{
	int c;
	extern char *optarg;
	extern int optind;

	int source = -1; /* 0=puits, 1=source */
	int lg_message = LG_MESS_DEFAUT;
	char * message;

	/* Le destinataire (si source) est le dernier argument */
	char * nom_machine = argv[argc-1];

	printf("hello\n");

	/* Récupérons les options */
	while ((c = getopt(argc, argv, "ps:l:")) != -1) {
		switch (c) {

		case 'p':
			if (source == 1) {
				printf("Usage: com [-p|-s] [host] \n");
				exit(1);
			}
			source = 0;
			break;

		case 's':
			if (source == 0) {
				printf("Usage: com [-p|-s] [host] \n");
				exit(1);
			}
			source = 1;
			break;

		case 'l':
			lg_message = atoi(optarg);
			if (lg_message < 0 || lg_message >= 100000) {
				printf("La longueur d'un message ne peut être négative ni supérieure à 99999…\n");
				exit(1);
			}
			break;

		default:
			printf("Usage: com [-p|-s] [host] \n");
			exit(1);
			break;
		}
	}

	if (source == -1) {
		printf("Usage: com [-p|-s] [host] \n");
		exit(1) ;
	}

	message = malloc(sizeof(char)*lg_message);

	if (source == 1) {
	
		/* On convertit le port dans l'ordre network dans l'appel */
		initSender(nom_machine);
		emettre(lg_message, message, "0 0");
	}
	else {		
		initReceiver();
		recevoir(lg_message, message);
		while(1);
	}

	free(message);

	return 0;
}
