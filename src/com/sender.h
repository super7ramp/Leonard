#ifndef SENDER_H
#define SENDER_H

void construire_message(char *message, char *contenu);
void afficher_messageS(char *message, int lg);
void afficher_envoi (int lg_message, char * message);
int initSender(char * nom_station);
int emettre(int lg_message, char * message,char *contenu);
int closeSender();

#endif
