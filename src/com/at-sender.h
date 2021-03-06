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

#define MAX_BUF_LEN 1024

typedef struct
{
    struct sockaddr_in *serv_addr;
    int socket_id;
} socket_info_t;

socket_info_t initialize_socket(const char *dest_ip, int dest_port);
int close_socket(socket_info_t socket);
int send_message(char *message, socket_info_t socket);

#endif

