/* test-sender.c -- Test program for UDP client functions
 * Copyright (C) 2015 Adrien Barre, Antoine Belvire, Valentin Douais, Alexis Lothoré, Lucille Saade
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include <stdio.h>
#include "../sender.h"

#define IP_TEST     "127.0.0.1"
#define PORT_TEST1  5556
#define PORT_TEST2  5554

int main()
{
    printf("[Test sender]\n");

    socket_info_t sock1,sock2;

    sock1 = initialize_socket(IP_TEST, PORT_TEST1);
    sock2 = initialize_socket(IP_TEST, PORT_TEST2);

    if(sock1.socket_id == -1 || sock2.socket_id == -1)
    {
        printf("[FAILED] Socket initialization failed\n");
    }
    else
    {
        if (send_message("test1", sock1) != 0 ||
            send_message("test2", sock2) != 0) // test with a sniffer that what is sent is OK
        {
            printf("[FAILED] Message sending failed\n");
        }
        else
            printf("[SUCCESS] Messages were sent!\n");
    }

    close_socket(sock1);
    close_socket(sock2);

    return 0;
}
