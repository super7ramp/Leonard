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

    // Waiting; TODO: add and check navdata thread state
    sleep(3);
    
	while(1)
	{
	    
	    // TODO mutex
	    if (isNavdataAvailable())
	    {
	        navdata = getNavdata();
	    
            // Checking header
            printf("[Checking header]\n");
            printf("magic : %x\n", navdata.header.magic);
            printf("sequence : %d\n", navdata.header.sequence);
            //printf("options_tag: %d\n", navdata.header.options[0].tag);
            //printf("options_size: %d\n", navdata.header.options[0].size);
            //printf("options_data: %d\n", navdata.header.options[0].data[0]);
            
            // Checking demo
            printf("[Checking demo]\n");
            printf("size : %d\n", navdata.demo.size);
            printf("bat : %d\n", navdata.demo.vbat_flying_percentage);
	        printf("theta : %f\n", navdata.demo.theta);
	        printf("phi : %f\n", navdata.demo.phi);
	        printf("psi : %f\n", navdata.demo.psi);
	        printf("vx : %f\n", navdata.demo.vx);
	        printf("vy : %f\n", navdata.demo.vy);
	        printf("vz : %f\n", navdata.demo.vz);
	
	        //printf("\e[A\e[A\e[A");
	        sleep(1);
	    }
	    usleep(300000);
	}

    pthread_cancel(reset_watchdog_tid);
    terminate_at_com();

	return 0;
}
