/* test-message_drone.c -- Test program for messages sent to drone
 * Copyright (C) 2015 Adrien Barre, Antoine Belvire, Valentin Douais, Alexis Lothoré, Lucille Saade
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include <stdio.h>
#include "../message_drone.h"

// Sniff the traffic to verify
int main()
{
    char message [512];
    
    initialize_at_com();
    
    printf("[Test SET_TRIM]\n");
    set_trim(message);

    printf("\n[Test TAKE_OFF]\n");
    take_off(message);

    printf("\n[Test LANDING]\n");
    landing(message);

    printf("\n[Test SET_ROLL (left 10)]\n");
    set_roll(message, LEFT, 0.1);

    printf("\n[Test SET_ROLL (right 100)]\n");
    set_roll(message, RIGHT, 1.0);

    printf("\n[Test SET_PITCH (front 10)]\n");
    set_pitch(message, FRONT, 0.1);

    printf("\n[Test SET_GAZ (up 30)]\n");
    set_gaz(message, UP, 0.3);

    printf("\n[Test SET_YAW (left 100)]\n");
    set_yaw(message, LEFT, 1.0);

    terminate_at_com();
    
    return 0;
}
