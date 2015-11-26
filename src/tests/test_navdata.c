/*Pour cross-compiler : 
arm-linux-gnueabi-gcc-4.6 -march=armv7-a -I lib/libpcap/include/ src/navdata_controller.c src/sender.c src/message_drone.c src/at-commands.c src/tests/test_navdata.c -o t_nav.elf -L lib/libpcap/lib -lpthread -lpcap

*/

#include <stdio.h>
#include "../navdata_controller.h"

int main ()
{
  	Navdata navdata;
  	initialize_at_com(); //first thing to do
	initNavdata();

	while(1)
	{
		printf("theta : %f\n",navdata.demo.theta);
		printf("phi : %f\n",navdata.demo.phi);
		printf("psi : %f\n",navdata.demo.psi);
		//printf("\e[A\e[A\e[A");
		sleep(1);
	}

    terminate_at_com();

	return 0;
}
