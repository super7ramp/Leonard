#include <stdio.h>
#include "message_drone.h"


char *set_trim(char *message, int sequence)
{
	//char message [512];
	
	at_ftrim(message, sequence);
	//send_message(message);
	return message;
}

char *take_off(char *message, int sequence)
{
	//char message [512];

	at_ref(message, sequence, 290718208);
	//send_message(message);
	return message;
}

char *landing(char *message, int sequence)
{
	//char message [512];
	
	at_ref(message, sequence, 290717696);
	//send_message(message);
	return message;
}

char *set_roll(char *message, int sequence, direction dir, float power)
{
	//char message [512];
	pcmd_t command;

	switch(dir)
	{
		case GAUCHE:
			command.progressive=1;
			command.lrTilt=-(power);
			command.fbTilt=0;
			command.verticalSpeed=0;
			command.angularSpeed=0;

			at_pcmd(message, sequence, command);
			//send_message(message);
			break;

		case DROITE:
			command.progressive=1;
			command.lrTilt=power;
			command.fbTilt=0;
			command.verticalSpeed=0;
			command.angularSpeed=0;

			at_pcmd(message, sequence, command);
			//send_message(message);
			break;

		default:
			printf("Error enum direction\n");
			break;
	}
	return message;
}

char *set_pitch(char *message, int sequence, direction dir, float power)
{
	//char message [512];
	pcmd_t command;

	switch(dir)
	{
		case AVANT:
			command.progressive=1;
			command.lrTilt=0;
			command.fbTilt=-(power);
			command.verticalSpeed=0;
			command.angularSpeed=0;

			at_pcmd(message, sequence, command);
			//send_message(message);
			break;

		case ARRIERE:
			command.progressive=1;
			command.lrTilt=0;
			command.fbTilt=power;
			command.verticalSpeed=0;
			command.angularSpeed=0;

			at_pcmd(message, sequence, command);
			//send_message(message);
			break;

		default:
			printf("Error enum direction\n");
			break;
	}
	return message;
}

char *set_gaz(char *message, int sequence, direction dir, float power)
{
	//char message [512];
	pcmd_t command;

	switch(dir)
	{
		case DESCENDRE:
			command.progressive=1;
			command.lrTilt=0;
			command.fbTilt=0;
			command.verticalSpeed=-(power);
			command.angularSpeed=0;

			at_pcmd(message, sequence, command);
			//send_message(message);
			break;

		case MONTER:
			command.progressive=1;
			command.lrTilt=0;
			command.fbTilt=0;
			command.verticalSpeed=power;
			command.angularSpeed=0;

			at_pcmd(message, sequence, command);
			//send_message(message);
			break;

		default:
			printf("Error enum direction\n");
			break;
	}
	return message;
}

char *set_yaw(char *message, int sequence, direction dir, float power)
{
	//char message [512];
	pcmd_t command;

	switch(dir)
	{
		case GAUCHE:
			command.progressive=1;
			command.lrTilt=0;
			command.fbTilt=0;
			command.verticalSpeed=0;
			command.angularSpeed=-(power);

			at_pcmd(message, sequence, command);
			//send_message(message);
			break;

		case DROITE:
			command.progressive=1;
			command.lrTilt=0;
			command.fbTilt=0;
			command.verticalSpeed=0;
			command.angularSpeed=power;

			at_pcmd(message, sequence, command);
			//send_message(message);
			break;

		default:
			printf("Error enum direction\n");
			break;
	}
	return message;
}
	
			

	
