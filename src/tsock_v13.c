#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define NB_MESS_ENV_DEFAUT 10
#define LG_MESS_DEFAUT 30

void construire_message(char *message, char motif, int lg) {
	int i;
	for (i=0;i<lg;i++)
		message[i] = motif;
}

void afficher_message(char *message, int lg) {
	int i;
	for (i=0;i<lg;i++)
		printf("%c", message[i]);
}

void afficher_info_source (int lg_message, int port, int nb_envoi, int protocole, char * destinataire) {
	printf("SOURCE : lg_mseg_emis=%d, port =%d, nb_envois=%d, ", lg_message, ntohs(port), nb_envoi);
	if (protocole == 1) 
		printf("TP=TCP, ");
	else
		printf("TP=UDP, ");
	printf("dest=%s",destinataire);
	printf("\n");
}

void afficher_info_puits (int lg_message_lu, int port, int nb_reception, int protocole) {
	printf("PUITS : lg_mseg_lu=%d, port =%d, ", lg_message_lu, ntohs(port));
	if (nb_reception == -1)
		printf("nb_receptions= infini, ");
	else
		printf("nb_receptions=%d, ", nb_reception);
	if (protocole == 1) 
		printf("TP=TCP");
	else
		printf("TP=UDP");
	printf("\n");
}

void afficher_envoi (int num_envoi, int lg_message, char * message) {
	printf("SOURCE : Envoi n°%d (%d) [", num_envoi, lg_message);
	printf("%5d", num_envoi); // On code le numéro sur 5 caractères ASCII
	afficher_message(message, lg_message);
	printf("]\n");
}

void afficher_reception (int num_reception, int lg_message, char * message) 
{
	printf("PUITS : Reception n°%d (%d) [", num_reception, lg_message);
	printf("%5d", num_reception);
	afficher_message(message, lg_message);
	printf("]\n");
}

int emettre(int protocole, int port, char * nom_station, int lg_message, char * message, int nb_message) 
{
	int i;
	int type_sock ;

	if (protocole == 0)
	 	type_sock = SOCK_DGRAM;
	else
	 	type_sock = SOCK_STREAM;
	 
	int id_socket = -1;
	struct sockaddr_in adr_distant; // adresse du socket distant
	int lg_adr_distant = sizeof(adr_distant);
	struct hostent * hote;

	int retour;

	if ((id_socket = socket(AF_INET, type_sock,0)) == -1) {
		fprintf(stderr, "tsock: Échec de création du socket\n");
		exit(1);
	}

	/* adressage */
	memset((char *)&adr_distant, 0, lg_adr_distant); //reset
	adr_distant.sin_family = AF_INET;
	adr_distant.sin_port = port;

	if ((hote = gethostbyname(nom_station)) == NULL) {
		fprintf(stderr, "tsock: Erreur gethostbyname\n") ;
		exit(1); 
	}

	memcpy((char *)&(adr_distant.sin_addr.s_addr),hote->h_addr,hote->h_length); 

	/* connect() si on a tcp */
	if (protocole == 1) {
		retour = connect(id_socket, (struct sockaddr *) &adr_distant, (socklen_t) lg_adr_distant);
		if (retour == -1) {
			fprintf(stderr, "tsock: Erreur connect()\n");
			exit(1);
		}
	}

	/* send() */
	for (i = 1 ; i <= nb_message ; i++) {
		construire_message(message, 'a'+(i-1)%26, lg_message); 
		if (protocole == 1)
			retour = write(id_socket, message, lg_message) ;
		else
			retour = sendto(id_socket, message, lg_message, 0, (struct sockaddr *) &adr_distant, (socklen_t) lg_adr_distant);
		if (retour == -1) {
			fprintf(stderr, "tsock: Erreur envoi\n");
			exit(1);
		}
		afficher_envoi(i, retour, message); // retour = longueur message envoyé
	}

	/* shutdown() si tcp */
	if (protocole == 1) {
		if (shutdown(id_socket,1) == -1) {
			fprintf(stderr, "tsock: Erreur shutdown\n");
			exit(1);
		}
	}

	/* close() */
	if (close(id_socket) == -1) {
		fprintf(stderr, "tsock: Échec de destruction du socket\n");
		exit(1);
	}

	printf("SOURCE : fin\n");
	return 0; // tout s'est bien passé

}

/* fonction appelée dans reception() */
int recevoir(int protocole, int port, int lg_message, char * message, int nb_message) {
	int retour;
	int i;
	int num_reception;
	int type_sock;

	if (protocole == 0)
		type_sock = SOCK_DGRAM;
	else
		type_sock = SOCK_STREAM;

	int id_socket = -1;
	int id_sock_bis;
	struct sockaddr_in adr_local; // adresse du socket distant
	int lg_adr_local = sizeof(adr_local);

	/* Création socket */
	if ((id_socket = socket(AF_INET, type_sock,0)) == -1) {
		fprintf(stderr, "tsock: Échec de création du socket\n");
		exit(1);
	}

	/* construction @ socket */
	memset((char *)&adr_local, 0, lg_adr_local); //reset
	adr_local.sin_family = AF_INET;
	adr_local.sin_port = port;
	adr_local.sin_addr.s_addr = INADDR_ANY;

	/* Bind() */
	if(bind(id_socket,(struct sockaddr *) &adr_local, lg_adr_local) == -1) {
	 	fprintf(stderr, "tsock: Echec du bind\n");
	 	exit(1);
	}

	/* Récuperer l'adresse du socket local */
	if((getsockname(id_socket, (struct sockaddr *) &adr_local, (socklen_t*) &lg_adr_local)) == -1) {
	 	fprintf(stderr, "tsock: Echec du getsockname\n");
	 	exit(1);
	}

	/* si tcp -> listen() et accept() */
	if (protocole == 1) {
		if (listen(id_socket, 5) == -1) {
			fprintf(stderr, "tsock: Erreur listen()\n");
			exit(1);
		}
		if ((id_sock_bis = accept(id_socket,(struct sockaddr *) &adr_local, (socklen_t *) &lg_adr_local))== -1) {
			fprintf(stderr, "tsock: Erreur accept()\n"); 
			exit(1);
		}
	}

	/* reception */
	num_reception = 1;
	retour = 1;

	if (nb_message == -1) {
		while(retour > 0) {

			if (protocole == 1)
				retour = recv(id_sock_bis, message, lg_message, 0);
			else 
 				retour = recvfrom(id_socket, message, lg_message, 0, (struct sockaddr *) &adr_local, (socklen_t *) &lg_adr_local);
 
			if (retour == -1) {
				fprintf(stderr, "Echec de la réception\n");
				exit(1);
			}

			if (retour > 0) 
				afficher_reception(num_reception, retour, message);

			num_reception++; 
		}
	}
	else {
		for (i=0 ; i < nb_message ; i++) {

			if (protocole == 1) {
				retour = recv(id_sock_bis, message, lg_message, 0);
				afficher_reception(num_reception,retour,message); // retour = longueur du message recu
			}
			else {
				retour = recvfrom(id_socket, message, lg_message, 0, (struct sockaddr *) &adr_local, (socklen_t *) &lg_adr_local);
				afficher_reception(num_reception, lg_message, message);
			}

 			if (retour == -1) {
  			fprintf(stderr, "tsock: Echec de la réception\n");
				exit(1);
			}

			num_reception++; 
		}
	}

	/* si tcp shutdown() */
	if (protocole == 1) {
		if (shutdown(id_socket,0) == -1) {
			fprintf(stderr, "tsock: Erreur shutdown\n");
			exit(1);
		}
	}

	/* close() */
	if (close(id_socket) == -1) {
		fprintf(stderr, "tsock: Échec de destruction du socket\n");
		exit(1);
	}

	return 0;
}

int main (int argc, char **argv)
{
	int c;
	extern char *optarg;
	extern int optind;

	int nb_message = -1; /* Nb de messages à envoyer ou à recevoir, par défaut : 10 en émission, (-1) infini en réception */
	int source = -1; /* 0=puits, 1=source */
	int protocole = 1; /* 0=udp, 1=tcp, par défaut tcp car pas d'option pour tcp */
	int lg_message = LG_MESS_DEFAUT;
	char * message;

	/* Le destinataire (si source) et le ports sont les 2 derniers arguments */
	char * nom_machine = argv[argc-2];
	int port = atoi(argv[argc-1]); /* attention ordre hardware, à convertir après ! */ 

	/* Récupérons les options */
	while ((c = getopt(argc, argv, "upsn:l:")) != -1) {
		switch (c) {
		case 'u':
			protocole = 0;
			break;

		case 'p':
			if (source == 1) {
				printf("Usage: tsock [-u|-p|-s][-n ##] [host] port\n");
				exit(1);
			}
			source = 0;
			break;

		case 's':
			if (source == 0) {
				printf("Usage: tsock [-u|-p|-s][-n ##] [host] port\n");
				exit(1);
			}
			source = 1;
			break;

		case 'n':
			nb_message = atoi(optarg);
			if (nb_message >= 100000 || nb_message < -1) {
				printf("Le nombre de messages doit être compris entre -1 (réception infinie) et 99999\n");
				exit(1);
			} 
			break;

		case 'l':
			lg_message = atoi(optarg);
			if (lg_message < 0 || lg_message >= 100000) {
				printf("La longueur d'un message ne peut être négative ni supérieure à 99999…\n");
				exit(1);
			}
			break;

		default:
			printf("Usage: tsock [-u|-p|-s][-n ##] [host] port\n");
			exit(1);
			break;
		}
	}

	if (source == -1) {
		printf("Usage: tsock [-u|-p|-s][-n ##] [host] port\n");
		exit(1) ;
	}

	message = malloc(sizeof(char)*lg_message);

	if (source == 1) {

		/* Vérifie qu'on ait bien deux arguments à la fin (destinataire et port)
		   sinon, port et nom_machine contiennent des options ! */
		if (optind >= argc-1) {
			printf("Usage: tsock [options] [host] port\n");
			exit(1);
		}

		/* Vérifie la taille des paquets en udp */
		if (lg_message > 65507 && protocole == 0) {
			printf("La taille max d'un paquet UDP est de 65507o\n");
			exit(1);
		}

		/* Vérifie que le numéro de port ne soit pas supérieur 65535
		   (le port est normalement codé sur 16 bits, on aurait pu d'ailleurs
			 prendre un short au lieu d'un int) */
		if (port > 65535 || port < 0) {
			printf("Le numéro de port doit être positif et inférieur ou égal à 65535\n");
			exit(1);
		}

		if (nb_message == -1)
			nb_message = NB_MESS_ENV_DEFAUT;

		/* On convertit le port dans l'ordre network dans l'appel */
		afficher_info_source(lg_message, htons(port), nb_message, protocole, nom_machine);
		emettre(protocole, htons(port), nom_machine, lg_message, message, nb_message);
	}
	else {

		/* Vérifie qu'on ait bien un argument (port) */
		if (optind >= argc) {
			printf("Usage: tsock [options] [host] port\n");
			exit(1);
		}

		/* Vérifie que le numéro de port ne soit pas supérieur à 65535
		   Attention, on ne teste pas s'il s'agit d'un port réservé
			 La création de puits sur les ports réservés ne peut se faire
			 qu'en ayant les droits d'administrateur */
		if (port > 65535 || port < 0) {
			printf("Le numéro de port doit être positif et inférieur à 65535\n");
			exit(1);
		}

		afficher_info_puits (lg_message, htons(port), nb_message, protocole);
		recevoir(protocole, htons(port), lg_message, message, nb_message);
	}

	free(message);

	return 0;
}

