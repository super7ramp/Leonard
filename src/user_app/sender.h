#ifndef SENDER_H
#define SENDER_H


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#include "../com/parameters.h"

void construire_message(char *message, char *contenu);
void afficher_messageS(char *message, int lg);
void afficher_envoi (int lg_message, char * message);
int initSender(char * nom_station);
int emettre(int lg_message, char * message, char *contenu);
int closeSender();

#endif
