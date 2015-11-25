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

/** @brief Send a message through the specified socket
 *  @param message The buffer where is stored the message to send
 *  @param socket_id Socket identifier
 *  @return int 0 if the sendto() succeeds, -1 otherwise
 */
int send_message(char *message, socket_info_t socket)
{   
    if (sendto(socket.socket_id, message, MIN(strlen(message), MAX_BUF_LEN), 0, (struct sockaddr *) socket.serv_addr, (socklen_t) sizeof(struct sockaddr_in)) == -1)
    {
        fprintf(stderr, "[%s:%d] Error: sendto() failed\n", __FILE__, __LINE__);
        return -1;
    }

    return 0;
}

/** @brief Initialize an UDP socket (for clients)
 *  @param dest_ip The destination ip
 *  @param dest_port The destination port
 *  @return socket_info_t structure
 */
socket_info_t initialize_socket(const char *dest_ip, int dest_port)
{
    socket_info_t info;
    
    if ((info.socket_id = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        fprintf(stderr, "[%s:%d] Error: Socket creation failed\n", __FILE__, __LINE__);
    }

    // Addresses
    //info.serv_addr = calloc(1, sizeof(struct sockaddr_in));
    info.serv_addr = calloc(1, sizeof(struct sockaddr_in));
    info.serv_addr->sin_family = AF_INET;
    info.serv_addr->sin_port = htons(dest_port);  //num port dest

    if (inet_aton(dest_ip, &(info.serv_addr->sin_addr)) == 0)   //addr ip dest
    {
        fprintf(stderr, "[%s:%d] Error: inet_aton() failed\n", __FILE__, __LINE__);
    }

    return info;
}

/** @brief Close the specified socket
 *  @param socket_id The socket to close
 *  @return 0 on success
 */
int close_socket(socket_info_t socket)
{
    if (close(socket.socket_id) == -1)
    {
        fprintf(stderr, "[%s:%d] Error: close_socket() failed\n", __FILE__, __LINE__);
        return 1;
    }
    
    if(socket.serv_addr)
        free(socket.serv_addr);

    return 0;
}
