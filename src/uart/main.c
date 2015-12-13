#include <stdio.h>   /* Standard input/output definitions */
#include <stdlib.h> 
#include <string.h>  /* String function definitions */
#include <sys/time.h>
#include <unistd.h>
#include "parser.h"
#include "parameters.h"
#include "localisation.h"


int test() 
{
	t_data s1, s2;
	
	//s1 = extract_data("46 09 ad 80 07 00 -6\r\n"); //OK
	//s2 = extract_data("4b 09 ad 80 07 00 -10\r\n"); //OK
	//s2 = extract_data("07 80 a7 b2 c7 a2 -50\r\n"); //OK
	//s2 = extract_data("07 80 a7 b2 c7 a2 51 54 58 -50\r\n"); //OK
	s2 = extract_data("07 80 a7 -50 c7 a2 -50\r\n");
	s2 = extract_data("07 80  c7 a2 -50\r\n");
	s2 = extract_data("07 80 a7 b2 c7 a2 -50\r\n");
	s2 = extract_data("07 80 a7 b2 c7 a2 -50\r\n");
	s2 = extract_data("07 80 a7 b2 -54 -54 -50\r\n");
	s2 = extract_data("7 80 a7 b2 c7 a2 -50\r\n");
	s2 = extract_data("7 80 ab2 c7 a2 55 -50\r\n");
	s2 = extract_data("7 a7 b2 253 a2 55-50\r\n");

	printf("rssi 1 beacon 1 : %d\n", getBeaconRssi(0)); 
	printf("ttl 1 : %f\n", getBeaconTTL(0));
	
	printf("rssi 2 beacon 1 : %d\n", getBeaconRssi(1)); 
	printf("ttl 2 : %f\n", getBeaconTTL(1));
	
	printf("différence : %f\n", getBeaconTTL(1)-getBeaconTTL(0));
	
	return 0;
}



int main() {
	
	t_data s1, s2, s3;
	
	s1 = extract_data("46 09 ad 80 07 00 -6\r\n");
	s2 = extract_data("4f 09 ad 80 07 00 -10\r\n");
	s3 = extract_data("4b 09 ad 80 07 00 -10\r\n");


	UpdateCurrentLocation();
	
	
	t_location loc = getCurrentLocation();
	
	printf("Location : %f %f \n", loc.x, loc.y);

	return 0;
}








