#ifndef RECEIVER_H
#define RECEIVER_H

void afficher_messageR(char *message, int lg);
void afficher_reception (int lg_message, char * message);
int initReceiver();
int recevoir(int lg_message, char * message);
int closeReceiver();
void  setUser(int u);

#endif

