/* message_drone.c -- High level functions to control the drone
 * Copyright (C) 2015 Adrien Barre, Antoine Belvire, Valentin Douais, Alexis Lothoré, Lucille Saade
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include <stdio.h>
#include "message_drone.h"

char *emergency(char *message, int sequence)
{
    at_ref(message, sequence, 290717952);
    if (send_message(message) != 0)
        printf("[FAILED] Message sending failed\n");
    return message;
}

char *anti_emergency(char *message, int sequence)
{
    at_ref(message, sequence, 290717696);
    if (send_message(message) != 0)
        printf("[FAILED] Message sending failed\n");
    return message;
}

char *set_trim(char *message, int sequence)
{
    at_ftrim(message, sequence);
    if (send_message(message) != 0)
        printf("[FAILED] Message sending failed\n");
    return message;
}

char *take_off(char *message, int sequence)
{
    at_ref(message, sequence, 290718208);
    if (send_message(message) != 0)
        printf("[FAILED] Message sending failed\n");
    return message;
}

char *landing(char *message, int sequence)
{
    at_ref(message, sequence, 290717696);
    if (send_message(message) != 0)
        printf("[FAILED] Message sending failed\n");
    return message;
}

char *set_roll(char *message, int sequence, direction dir, float power)
{
    pcmd_t command;

    switch(dir)
    {
        case LEFT:
            command.progressive=1;
            command.lrTilt=-(power);
            command.fbTilt=0;
            command.verticalSpeed=0;
            command.angularSpeed=0;

            at_pcmd(message, sequence, command);
            if (send_message(message) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        case RIGHT:
            command.progressive=1;
            command.lrTilt=power;
            command.fbTilt=0;
            command.verticalSpeed=0;
            command.angularSpeed=0;

            at_pcmd(message, sequence, command);
            if (send_message(message) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        default:
            printf("Error enum direction\n");
        break;
    }

    return message;
}

char *set_pitch(char *message, int sequence, direction dir, float power)
{
    pcmd_t command;

    switch(dir)
    {
        case FRONT:
            command.progressive=1;
            command.lrTilt=0;
            command.fbTilt=-(power);
            command.verticalSpeed=0;
            command.angularSpeed=0;

            at_pcmd(message, sequence, command);
            if (send_message(message) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        case BACK:
            command.progressive=1;
            command.lrTilt=0;
            command.fbTilt=power;
            command.verticalSpeed=0;
            command.angularSpeed=0;

            at_pcmd(message, sequence, command);
            if (send_message(message) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        default:
            printf("Error enum direction\n");
            break;
    }
    return message;
}

char *set_gaz(char *message, int sequence, direction dir, float power)
{
    pcmd_t command;

    switch(dir)
    {
        case DOWN:
            command.progressive=1;
            command.lrTilt=0;
            command.fbTilt=0;
            command.verticalSpeed=-(power);
            command.angularSpeed=0;

            at_pcmd(message, sequence, command);
            if (send_message(message) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        case RIGHT:
            command.progressive=1;
            command.lrTilt=0;
            command.fbTilt=0;
            command.verticalSpeed=power;
            command.angularSpeed=0;

            at_pcmd(message, sequence, command);
            if (send_message(message) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        default:
            printf("Error enum direction\n");
        break;
    }
    return message;
}

char *set_yaw(char *message, int sequence, direction dir, float power)
{
    pcmd_t command;

    switch(dir)
    {
        case LEFT:
            command.progressive=0;
            command.lrTilt=0;
            command.fbTilt=0;
            command.verticalSpeed=0;
            command.angularSpeed=-(power);

            at_pcmd(message, sequence, command);
            if (send_message(message) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        case RIGHT:
            command.progressive=0;
            command.lrTilt=0;
            command.fbTilt=0;
            command.verticalSpeed=0;
            command.angularSpeed=power;

            at_pcmd(message, sequence, command);
            if (send_message(message) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        default:
            printf("Error enum direction\n");
        break;
    }
    return message;
}

char *reset_com(char *message)
{
    at_comwdg(message);
    if (send_message(message) != 0)
        printf("[FAILED] Message sending failed\n");

    return message;
}
