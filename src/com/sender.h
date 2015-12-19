#ifndef SENDER_H
#define SENDER_H

void construire_message(char *message, char motif, int lg);
void afficher_messageS(char *message, int lg);
void afficher_envoi (int num_envoi, int lg_message, char * message);
int initSender( char * nom_station);
int emettre(int lg_message, char * message, int nb_message);
int closeSender();

#endif
