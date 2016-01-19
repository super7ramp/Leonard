#include "diagnostic.h"

static int beaconCheckTab[NUMBER_BEACONS];

void initBeaconCheckTab(void)
{
	uint8_t count=0;
	for(count=0; count<NUMBER_BEACONS; count++)
	{
		beaconCheckTab[count]=0;
	}
}

void displayCheckResult(void)
{
	uint8_t count=0;
	char checked=' ';
	for(count=0; count<NUMBER_BEACONS; count++)
	{
		if(beaconCheckTab[count]==1)
			checked='X';
		else
			checked=' ';
		printf("Beacon %c : [%c]\r\n", count+65, checked);
	}
}

uint8_t checkDetectedBeacon(void)
{
	uint8_t count=0;
	uint8_t allBeaconsDetected=1;
	for(count=0; count<NUMBER_BEACONS; count++)
	{
		if(getBeaconRssi(count)<0)
			beaconCheckTab[count]=1;
		if(beaconCheckTab[count]==0)
			allBeaconsDetected=0;
	}
	return allBeaconsDetected;
}

void endHandler(int arg) 
{
	uint8_t count;
	for(count=0; count<NUMBER_BEACONS; count++)
	{
		printf("\r\n");
	}
    printf("Fin du programme. Balises non trouvées : ");
    for(count=0; count<NUMBER_BEACONS; count++)
    {
    	if(beaconCheckTab[count]==0)
    	{
    		printf("%c ", count+65);
    	}
    }


    printf("\r\n");
    closeBluetoothCom();
    exit(0);
}


int main(void)
{
  	uint8_t test_passed=0;

  	initBluetoothCom();
  	initBeaconCheckTab();
  	printf("Please hold and move the drone all around the room.\r\n");
  	signal(SIGINT, endHandler);

  	while(test_passed==0)
  	{
  		extract_data();
  		test_passed=checkDetectedBeacon();
  		displayCheckResult();
  		if(!test_passed)
			printf("\033[%dA", NUMBER_BEACONS);
  	}
  	printf("All beacons are active !\r\n");
	closeBluetoothCom();
	return 0;
}