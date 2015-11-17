/* test-sender.c -- Test program for UDP client functions
 * Copyright (C) 2015 Adrien Barre, Antoine Belvire, Valentin Douais, Alexis Lothoré, Lucille Saade
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include <stdio.h>
#include "../sender.h"

int main()
{
    printf("[Test sender]\n");

    if (initialize_socket() != 0)
    {
        printf("[FAILED] Socket initialization failed\n");
    }
    else
    {
        if (send_message("test") != 0)
            printf("[FAILED] Message sending failed\n");
        else
            printf("[SUCCESS] Message was sent!\n");
    }
    
    close_socket();
    return 0;
}
