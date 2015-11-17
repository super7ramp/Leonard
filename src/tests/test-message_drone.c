#include <stdio.h>
#include <CUnit/CUnit.h>
#include "../message_drone.h"

int main()
{
	char message [512];
	int n = 0;// sequence number
	
	printf("[Test SET_TRIM]\n");
	printf("%s\n", set_trim(message,n++));

	printf("\n[Test TAKE_OFF]\n");
	printf("%s\n", take_off(message,n++));

	printf("\n[Test LANDING]\n");
	printf("%s\n", landing(message,n++));

	printf("\n[Test SET_ROLL (gauche 10)]\n");
	printf("%s\n", set_roll(message,n++, GAUCHE, 0.1));

	printf("\n[Test SET_ROLL (droite 100)]\n");
	printf("%s\n", set_roll(message,n++, DROITE, 1.0));

	printf("\n[Test SET_PITCH (avant 10)]\n");
	printf("%s\n", set_pitch(message,n++, AVANT, 0.1));

	printf("\n[Test SET_GAZ (monter 30)]\n");
	printf("%s\n", set_gaz(message,n++, MONTER, 0.3));

	printf("\n[Test SET_YAW (gauche 100)]\n");
	printf("%s\n", set_yaw(message,n++, GAUCHE, 1.0));

	return 0;
}
