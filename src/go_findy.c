/* go_findy.c -- Complex movement demonstration program
 * Copyright (C) 2015 Adrien Barre, Antoine Belvire, Valentin Douais, Alexis Lothoré, Lucille Saade
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include <stdio.h>
#include <unistd.h>
#include "message_drone.h"

// drone take off, follow a straight line and land 
int main ()
{
    char message [512];
    int n = 0;
    int tps = 0;

    if (initialize_socket(DEST_IP_AT, DEST_PORT_AT) != 0)
    {
        printf("[FAILED] Socket initialization failed\n");
    }
    else
    {
        sleep(1);
        anti_emergency(message, n++);
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
        while(tps < 30)
        {
                set_pitch(message, n++, BACK, 0.25);
                usleep(50000);
                tps++;
        }
        tps = 0;
        while(tps < 10)
        {
                set_pitch(message, n++, FRONT, 0.1);
                usleep(50000);
                tps++;
        }
        tps = 0;
        while(tps < 30)
        {
                set_pitch(message, n++, BACK, 0.0);
                usleep(50000);
                tps++;
        }
        tps = 0;
/*              while(tps < 60)
        {
                take_off(message, n++);
                usleep(50000);
                tps++;
        }
        tps = 0;*/
/*              while(tps < 20)
        {
                set_yaw(message, n++, RIGHT, 0.25);
                usleep(50000);
                tps++;
        }
        tps = 0;
*/              while(tps < 100)
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
