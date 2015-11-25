#ifndef SENDER_H
#define SENDER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DEST_IP     "127.0.0.1" //localhost
#define DEST_PORT   5556
#define MAX_BUF_LEN 1024

int initialize_socket();
int send_message(char *message);

#endif

