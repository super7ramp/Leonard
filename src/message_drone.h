#ifndef __MESAGE_DRONE_H
#define __MESAGE_DRONE_H

#include "at-commands.h"
#include "sender.h"

typedef enum
{
	GAUCHE,
	DROITE,
	AVANT,
	ARRIERE,
	MONTER,
	DESCENDRE
}direction;

char *set_trim(char *message, int sequence);
char *take_off(char *message, int sequence);
char *landing(char *message, int sequence);
char *set_roll(char *message, int sequence, direction dir, float power);
char *set_pitch(char *message, int sequence, direction dir, float power);
char *set_gaz(char *message, int sequence, direction dir, float power);
char *set_yaw(char *message, int sequence, direction dir, float power);
	


#endif

