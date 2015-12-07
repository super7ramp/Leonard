#include <stdio.h>   /* Standard input/output definitions */
#include <stdlib.h> 
#include <string.h>  /* String function definitions */
#include "parser.h"
#include "parameters.h"


int main() 
{
	t_data s;
	
	s = extract_data("4609ad800700 6\r\n");
	
	printf("rssi beacon 1 : %d\n", getBeaconRssi(0)); 
	return 0;
}
