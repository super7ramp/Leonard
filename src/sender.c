/* sender.c -- UDP Client
 * Copyright (C) 2015 Adrien Barre, Antoine Belvire, Valentin Douais, Alexis Lothoré, Lucille Saade
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include <stdio.h>
#include <stdlib.h>
#include "sender.h"

#define MIN(a,b) (((a)<(b))?(a):(b))

static struct sockaddr_in serv_addr;
static int socket_id;

int send_message(char *message)
{
    if (sendto(socket_id, message, MIN(strlen(message), MAX_BUF_LEN), 0, (struct sockaddr *)&serv_addr, (socklen_t) sizeof(serv_addr)) == -1)
    {
        fprintf(stderr, "[%s:%d] Error: sendto() failed\n", __FILE__, __LINE__);
        return 1;
    }

    return 0;
}

int initialize_socket()
{
    if ((socket_id = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        fprintf(stderr, "[%s:%d] Error: Socket creation failed\n", __FILE__, __LINE__);
	return 1;
    }

    // Addresses
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(DEST_PORT);

    if (inet_aton(DEST_IP, &serv_addr.sin_addr) == 0)
    {
        fprintf(stderr, "[%s:%d] Error: inet_aton() failed\n", __FILE__, __LINE__);
        return 2;
    }

    return 0;
}

int close_socket()
{
    if (close(socket_id) == -1)
    {
        fprintf(stderr, "[%s:%d] Error: close_socket() failed\n", __FILE__, __LINE__);
        return 1;
    }

    return 0;
}
