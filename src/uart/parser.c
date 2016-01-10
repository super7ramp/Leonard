#include "parser.h"


/* Map :
 * 
 * C ========== D
 *             
 * |            |
 * |     H      |
 *             
 * B            E
 *             
 * |     G      |
 * |            |
 *             
 * A ========== F
 *
 */

/*{{{id}, {beaconLocation}} , rssi, ttl}
*/
t_beacon_info beaconTab[NUMBER_BEACONS]={ 
  {{{0x00, 0x07, 0x80, 0xad, 0x09, 0x46}, {0, 0}},0,0}, //A
  {{{0x00, 0x07, 0x80, 0xad, 0x09, 0x4b}, {0, H/2.0}},0,0}, //B
  {{{0x00, 0x07, 0x80, 0xad, 0x09, 0x4f}, {0, H}},0,0}, //C
  {{{0x00, 0x07, 0x80, 0xad, 0x09, 0x4e}, {W, H}},0,0}, //D
  {{{0x00, 0x07, 0x80, 0xad, 0x09, 0x4a}, {W, H/2.0}},0,0}, //E
  {{{0x00, 0x07, 0x80, 0xad, 0x09, 0x55}, {W, 0}},0,0},  //F
  {{{0x00, 0x07, 0x80, 0xad, 0x09, 0x92}, {W/2.0, H/4.0}}, 0, 0}, //G
  {{{0x00, 0x07, 0x80, 0xad, 0x09, 0x33}, {W/2.0, 3.0*H/4.0}}, 0, 0}
  };
  

void extract_data()
{
  address_t addr;
  int rssi=0;
  int result = 0;
  char buffer[256];
  int size=0;


  memset(buffer, 0, sizeof(buffer)/sizeof(char));
  read_port(buffer, &size);

  //strncpy(buffer, data, size);
  if(size>=MINIMAL_SERIAL_READ_LENGTH)
  {
    //printf("_%s_\t%d\r\n", buffer, size);
    result=sscanf(buffer, "%x %x %x %x %x %x %d\r\n", (unsigned int *)addr, (unsigned int *)(addr+1),  (unsigned int *)(addr+2),(unsigned int *)(addr+3), (unsigned int *)(addr+4), (unsigned int *)(addr+5), &rssi);
    //printf("%x %x %x %x %x %x %d\r\n", addr[0], addr[1], addr[2], addr[3], addr[4], addr[5], rssi);
    if (result !=EOF && rssi<0) //Si lecture OK
    {
      updateDetectedBeaconRssi(addr, rssi);
      checkBeaconsTTL();

    }
  }
}


int8_t findBeaconInTab(address_t addr)
{
    int found=0;
    uint8_t i=0;
    
    
    while(i<NUMBER_BEACONS && !found)
    {
        if(compareAddresses(addr, beaconTab[i].beaconInfo.id)) {
            found=1;
        } 
        else
            i++;
    }
    if(found)
        return i;
    else
        return(-1);
}


int8_t compareAddresses(address_t addrA, address_t addrB)
{
	int result=1;
	uint8_t i;
	for(i=0; i<ADDR_LEN; i++)
	{
	  if(addrA[i]!=addrB[i]) 
    {	    
	    result=0;
	    break;
	  }
	}
	return result;
}


void updateDetectedBeaconRssi(address_t addr, int8_t rssi)
{
  int8_t index=findBeaconInTab(addr);
  if(index!=-1)
    {
      refreshBeaconTTL(index);
      beaconTab[index].rssi=rssi;
    }
}


void checkBeaconsTTL() {
  
	uint8_t i;
	struct timeval time;
	gettimeofday(&time, NULL);
	
	long long currentTime = time.tv_sec*1000 + time.tv_usec/1000;
  
	for(i = 0; i<NUMBER_BEACONS; i++) {
		
	  	if(currentTime - beaconTab[i].TTL >= TTL_MAX_MS)
		  {
		    beaconTab[i].TTL = 0;
		    beaconTab[i].rssi=0;
		  }
	}	
}


void refreshBeaconTTL(uint8_t index) {

	struct timeval time;
	gettimeofday(&time, NULL);
	beaconTab[index].TTL= time.tv_sec*1000 + time.tv_usec/1000;   
}

void printBeaconsTab(void)
{
  int i=0;

  for(i=0; i<NUMBER_BEACONS; i++)
      printf("%c\t", i+65);

  printf("\r\n");

  for(i=0; i<NUMBER_BEACONS; i++)
    printf("%d\t", beaconTab[i].rssi);

  printf("\r\n");
}

void printVisibleBeacons(void)
{
  int i=0;
  int count=0;
  for(i=0; i<NUMBER_BEACONS; i++)
  {
    if(beaconTab[i].rssi)
    {
      printf("%c ", (char)i+65);
      count++;
    }
  }	
  for(i=0; i<NUMBER_BEACONS-count; i++)
	printf("  ");

  printf("\r\n");
}

int8_t getBeaconRssi(uint8_t index)
{
  return beaconTab[index].rssi;
}

long long getBeaconTTL(uint8_t index)
{
  return beaconTab[index].TTL;
}

const t_beacon_info* getBeaconTab(void)
{
  return (const t_beacon_info*) beaconTab;
}


