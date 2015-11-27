/*Pour cross-compiler : 
arm-linux-gnueabi-gcc-4.6 -march=armv7-a -I lib/libpcap/include/ src/navdata_controller.c src/sender.c src/message_drone.c src/at-commands.c src/tests/test_navdata.c -o t_nav.elf -L lib/libpcap/lib -lpthread -lpcap

*/

#include <stdio.h>
#include "../navdata_controller.h"

void *reset_watchdog()
{
    char buff[512];
    
    set_trim(buff);

    while(1)
    {
        usleep(50000);
        reset_com(buff);
    }
    
    pthread_exit(NULL);
}

int main ()
{
    // AT communication initialization
 	initialize_at_com();

 	// Launch watchdog reset thread
 	pthread_t reset_watchdog_tid;
 	pthread_create(&reset_watchdog_tid, NULL, (void *) reset_watchdog, NULL);

    // Launch navdata
  	Navdata navdata;
	initNavdata();

	while(1)
	{
		printf("theta : %f\n", navdata.demo.theta);
		printf("phi : %f\n", navdata.demo.phi);
		printf("psi : %f\n", navdata.demo.psi);
		//printf("\e[A\e[A\e[A");
		sleep(1);
	}

    pthread_cancel(reset_watchdog_tid);
    terminate_at_com();

	return 0;
}
