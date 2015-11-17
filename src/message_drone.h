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

typedef enum
{
    LEFT,
    RIGHT,
    FRONT,
    BACK,
    UP,
    DOWN
} direction;

char *emergency(char *message, int sequence);
char *anti_emergency(char *message, int sequence);
char *set_trim(char *message, int sequence);
char *take_off(char *message, int sequence);
char *landing(char *message, int sequence);
char *set_roll(char *message, int sequence, direction dir, float power);
char *set_pitch(char *message, int sequence, direction dir, float power);
char *set_gaz(char *message, int sequence, direction dir, float power);
char *set_yaw(char *message, int sequence, direction dir, float power);
char *reset_com(char *message);

#endif
