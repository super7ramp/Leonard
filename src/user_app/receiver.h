#ifndef RECEIVER_H
#define RECEIVER_H

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

void afficher_messageR(char *message, int lg);
void afficher_reception (int lg_message, char * message);
int initReceiver();
int recevoir(int lg_message, char * message);
int closeReceiver();
void  setUser(int u);

#endif
