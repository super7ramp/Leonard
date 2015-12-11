#include <stdio.h>   /* Standard input/output definitions */
#include <stdlib.h> 
#include <string.h>  /* String function definitions */
#include <sys/time.h>
#include <unistd.h>
#include "parser.h"
#include "parameters.h"
#include "localisation.h"


int main() 
{
	t_data s1, s2;
	
	s1 = extract_data("46 09 ad 80 07 00 -6\r\n");
	sleep(5);
	s2 = extract_data("4b 09 ad 80 07 00 -10\r\n");
	
	printf("rssi 1 beacon 1 : %d\n", getBeaconRssi(0)); 
	printf("ttl 1 : %f\n", getBeaconTTL(0));
	
	printf("rssi 2 beacon 1 : %d\n", getBeaconRssi(1)); 
	printf("ttl 2 : %f\n", getBeaconTTL(1));
	
	printf("différence : %f\n", getBeaconTTL(1)-getBeaconTTL(0));
	
	return 0;
}
