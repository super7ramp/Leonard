#include <stdio.h>
#include <unistd.h>
#include "message_drone.h"

extern int socket_id;

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
		while(tps < 167)
		{
			take_off(message, n++);
			usleep(30000);
			tps++;
		}
		tps = 0;
		while(tps < 133)
		{
			reset_com(message);
			usleep(30000);
	 		tps++;
		}
		tps = 0;
/*		while(tps < 30)
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
		tps = 0;*/
/*		while(tps < 60)
		{
			take_off(message, n++);
			usleep(50000);
	 		tps++;
		}
		tps = 0;*/
		while(tps < 150)
		{
			set_yaw(message, n++, LEFT, 0.4);
			usleep(30000);
			tps++;
		}
		tps = 0;
		set_yaw(message, n++, RIGHT, 0.0);
		usleep(30000);
		while(tps < 133)
		{
			reset_com(message);
			usleep(30000);
	 		tps++;
		}
		tps = 0;
		landing(message, n++);
		sleep(1);
	}
    close(socket_id);
	return 0;
}
	
