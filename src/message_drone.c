/* message_drone.c -- High level functions to control the drone
 * Copyright (C) 2015 Adrien Barre, Antoine Belvire, Valentin Douais, Alexis Lothoré, Lucille Saade
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 */
#include <stdio.h>
#include "message_drone.h"

static socket_info_t at_socket;
int cpt_seq = 0;
pthread_mutex_t m_atcommand = PTHREAD_MUTEX_INITIALIZER;

/** @brief Initialize AT communication
 *  @return -1 on failure
 */
int initialize_at_com()
{
    at_socket = initialize_socket(DEST_IP_AT, DEST_PORT_AT);
    return at_socket.socket_id;
}

/** @brief Terminate AT communication
 *  @return 0 on success
 */
int terminate_at_com()
{
    return close_socket(at_socket);
}

char *set_config(char *message, const char *name, const char *value)
{
    pthread_mutex_lock(&m_atcommand);
    cpt_seq++;
    at_config(message, cpt_seq, name, value);
    if (send_message(message, at_socket) != 0)
        printf("[FAILED] Message sending failed\n");
    return message;
    pthread_mutex_unlock(&m_atcommand);
}

char *set_ackcontrol(char *message)
{
    pthread_mutex_lock(&m_atcommand);
    cpt_seq++;
    at_ackcontrol(message, cpt_seq);
    if (send_message(message, at_socket) != 0)
        printf("[FAILED] Message sending failed\n");
    return message;
    pthread_mutex_unlock(&m_atcommand);
}

char *set_emergency(char *message)
{
    pthread_mutex_lock(&m_atcommand);
    cpt_seq++;
    at_ref(message, cpt_seq, 290717952);
    if (send_message(message, at_socket) != 0)
        printf("[FAILED] Message sending failed\n");
    return message;
    pthread_mutex_unlock(&m_atcommand);
}

char *anti_emergency(char *message)
{
    pthread_mutex_lock(&m_atcommand);
    cpt_seq++;
    at_ref(message, cpt_seq, 290717696);
    if (send_message(message, at_socket) != 0)
        printf("[FAILED] Message sending failed\n");
    return message;
    pthread_mutex_unlock(&m_atcommand);
}

char *set_trim(char *message)
{
    pthread_mutex_lock(&m_atcommand);
    cpt_seq++;
    at_ftrim(message, cpt_seq);
    if (send_message(message, at_socket) != 0)
        printf("[FAILED] Message sending failed\n");
    return message;
    pthread_mutex_unlock(&m_atcommand);
}

char *take_off(char *message)
{
    pthread_mutex_lock(&m_atcommand);
    cpt_seq++;
    at_ref(message, cpt_seq, 290718208);
    if (send_message(message, at_socket) != 0)
        printf("[FAILED] Message sending failed\n");
    return message;
    pthread_mutex_unlock(&m_atcommand);
}

char *landing(char *message)
{
    pthread_mutex_lock(&m_atcommand);
    cpt_seq++;
    at_ref(message, cpt_seq, 290717696);
    if (send_message(message, at_socket) != 0)
        printf("[FAILED] Message sending failed\n");
    return message;
    pthread_mutex_unlock(&m_atcommand);
}

char *set_roll(char *message, direction dir, float power)
{
    pthread_mutex_lock(&m_atcommand);
    cpt_seq++;
    pcmd_t command;

    switch(dir)
    {
        case LEFT:
            command.progressive=1;
            command.lrTilt=-(power);
            command.fbTilt=0;
            command.verticalSpeed=0;
            command.angularSpeed=0;

            at_pcmd(message, cpt_seq, command);
            if (send_message(message, at_socket) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        case RIGHT:
            command.progressive=1;
            command.lrTilt=power;
            command.fbTilt=0;
            command.verticalSpeed=0;
            command.angularSpeed=0;

            at_pcmd(message, cpt_seq, command);
            if (send_message(message, at_socket) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        default:
            printf("Error enum direction\n");
        break;
    }

    return message;
    pthread_mutex_unlock(&m_atcommand);
}

char *set_pitch(char *message, direction dir, float power)
{
    pthread_mutex_lock(&m_atcommand);
    cpt_seq++;
    pcmd_t command;

    switch(dir)
    {
        case FRONT:
            command.progressive=1;
            command.lrTilt=0;
            command.fbTilt=-(power);
            command.verticalSpeed=0;
            command.angularSpeed=0;

            at_pcmd(message, cpt_seq, command);
            if (send_message(message, at_socket) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        case BACK:
            command.progressive=1;
            command.lrTilt=0;
            command.fbTilt=power;
            command.verticalSpeed=0;
            command.angularSpeed=0;

            at_pcmd(message, cpt_seq, command);
            if (send_message(message, at_socket) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        default:
            printf("Error enum direction\n");
            break;
    }
    return message;
    pthread_mutex_unlock(&m_atcommand);
}

char *set_gaz(char *message, direction dir, float power)
{
    pthread_mutex_lock(&m_atcommand);
    cpt_seq++;
    pcmd_t command;

    switch(dir)
    {
        case DOWN:
            command.progressive=1;
            command.lrTilt=0;
            command.fbTilt=0;
            command.verticalSpeed=-(power);
            command.angularSpeed=0;

            at_pcmd(message, cpt_seq, command);
            if (send_message(message, at_socket) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        case UP:
            command.progressive=1;
            command.lrTilt=0;
            command.fbTilt=0;
            command.verticalSpeed=power;
            command.angularSpeed=0;

            at_pcmd(message, cpt_seq, command);
            if (send_message(message, at_socket) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        default:
            printf("Error enum direction\n");
        break;
    }
    return message;
    pthread_mutex_unlock(&m_atcommand);
}

char *set_yaw(char *message, direction dir, float power)
{
    pthread_mutex_lock(&m_atcommand);
    cpt_seq++;
    pcmd_t command;

    switch(dir)
    {
        case LEFT:
            command.progressive=0;
            command.lrTilt=0;
            command.fbTilt=0;
            command.verticalSpeed=0;
            command.angularSpeed=-(power);

            at_pcmd(message, cpt_seq, command);
            if (send_message(message, at_socket) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        case RIGHT:
            command.progressive=0;
            command.lrTilt=0;
            command.fbTilt=0;
            command.verticalSpeed=0;
            command.angularSpeed=power;

            at_pcmd(message, cpt_seq, command);
            if (send_message(message, at_socket) != 0)
                printf("[FAILED] Message sending failed\n");
        break;

        default:
            printf("Error enum direction\n");
        break;
    }
    return message;
    pthread_mutex_unlock(&m_atcommand);
}

char *reset_com(char *message)
{
    pthread_mutex_lock(&m_atcommand);
    at_comwdg(message);
    if (send_message(message, at_socket) != 0)
        printf("[FAILED] Message sending failed\n");

    return message;
    pthread_mutex_unlock(&m_atcommand);
}
