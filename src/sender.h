/* sender.h -- UDP Client
 * Copyright (C) 2015 Adrien Barre, Antoine Belvire, Valentin Douais, Alexis Lothoré, Lucille Saade
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#ifndef SENDER_H
#define SENDER_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DEST_IP_AT     "127.0.0.1" //localhost
#define DEST_PORT_AT   5556
#define MAX_BUF_LEN 1024

int initialize_socket(string dest_ip, int dest_port);
int close_socket();
int send_message(char *message);

#endif

