/* message_drone.h -- High-level functions to control the drone 
 * Copyright (C) 2015 Adrien Barre, Antoine Belvire, Valentin Douais, Alexis Lothoré, Lucille Saade
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#ifndef __MESSAGE_DRONE_H
#define __MESSAGE_DRONE_H

#include "at-commands.h"
#include "sender.h"
#include <pthread.h>

#define DEST_IP_AT     "127.0.0.1" //< localhost
#define DEST_PORT_AT   5556        //< AT commands are sent to this port

typedef enum
{
    LEFT,
    RIGHT,
    FRONT,
    BACK,
    UP,
    DOWN
} direction;

int initialize_at_com();
int terminate_at_com();
char *set_config(char *message, const char *name, const char *value);
char *set_ackcontrol(char *message);
char *set_emergency(char *message);
char *anti_emergency(char *message);
char *set_trim(char *message);
char *take_off(char *message);
char *landing(char *message);
char *set_roll(char *message, direction dir, float power);
char *set_pitch(char *message, direction dir, float power);
char *set_gaz(char *message, direction dir, float power);
char *set_yaw(char *message, direction dir, float power);
char *reset_com(char *message);
char *calibrate_magneto(char *message);

#endif
