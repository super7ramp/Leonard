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
		landing(message, n++);
		sleep(1);
	}
    close(socket_id);
	return 0;
}
	
