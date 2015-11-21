/* findy_toff_land.c -- A simple takeoff/land demonstration program
 * Copyright (C) 2015 Adrien Barre, Antoine Belvire, Valentin Douais, Alexis Lothoré, Lucille Saade
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include <stdio.h>
#include <unistd.h>
#include "message_drone.h"

int main ()
{
    char message [512];
    int n = 1;
    int tps = 1;

    if (initialize_socket() != 0)
    {
        printf("[FAILED] Socket initialization failed\n");
    }
    else
    {
        sleep(1);
        set_trim(message, n++);
        usleep(500000);
        while(tps < 100)
	{
            take_off(message, n++);
            usleep(50000);
            tps++;
        }
        tps = 0;
        while(tps < 100)
        {
            reset_com(message);
            usleep(50000);
            tps++;
        }
        tps = 0;
        landing(message, n++);
        sleep(1);
    }
    close_socket();
    return 0;
}
