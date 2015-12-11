#include <stdio.h>   /* Standard input/output definitions */
#include <stdlib.h> 
#include <string.h>  /* String function definitions */
#include <stdint.h>
#include <inttypes.h>
#include <sys/time.h>
#include "parser.h"
#include "parameters.h"



/*{{{id}, {beaconLocation}, {detectedLocation}} , rssi, ttl}
*/
t_beacon_info beaconTab[NUMBER_BEACONS]={ 
	{{{0x46, 0x09, 0xad, 0x80, 0x07, 0x00}, {0, 0}, {2, 2}},0,0}, //A
	{{{0x4b, 0x09, 0xad, 0x80, 0x07, 0x00}, {0, 5}, {2, 5}},0,0}, //B
	{{{0x4f, 0x09, 0xad, 0x80, 0x07, 0x00}, {0, 10}, {2, 8}},0,0}, //C
	{{{0x4e, 0x09, 0xad, 0x80, 0x07, 0x00}, {8, 10}, {6, 8}},0,0}, //D
	{{{0x4a, 0x09, 0xad, 0x80, 0x07, 0x00}, {8, 5}, {6, 5}},0,0}, //E
	{{{0x55, 0x09, 0xad, 0x80, 0x07, 0x00}, {8, 0}, {6, 2}},0,0}  //F
	};


t_data extract_data(char * data)
{
	t_data ret;
	char aux[10];
	char addr[TAB_ADDR_LEN];
	int8_t rssi, cpt_addr = 0;
	int n = 0, cpt_res = 0;
	
	memset(aux, '\0', sizeof(aux));
	memset(addr, '\0', sizeof(addr));
	
	for (n=0; n <= strlen(data); n++, cpt_res++)
	{
		if (data[n] != ' ' && data[n] != '\r' && data[n] != '\n') 
		{
			aux[cpt_res] = data[n];
			//printf("data : %s, %s\n", data, aux);
			
		}
		else if(data[n] == ' ') 
		{
			if (atoi(aux) < 256) {
				strcat(addr, aux);
				//printf("addr : %s\n", addr);
				memset(aux, '\0', sizeof(aux));
				cpt_res = -1;
				cpt_addr += 1;
			
			}
			else
				exit -1;
		}
		
		else if (data[n] == '\r') 
		{
			rssi = atoi(aux);
			//printf("rssi : %d \n", rssi); 
			if (rssi >= 0) {
				exit -1;
			}
		}
	}
	
	ret.rssi = rssi;
	
	//printf("addr : %s\n", addr);
	
	convertToAddress(ret.address, addr);
	updateBeaconTab(ret.address, ret.rssi);
	
	return ret;
}



void convertToAddress(address_t res, char * address) {
	char * ptr;
	char * aux = malloc(sizeof(char) * 2);
	int8_t n;
	
	// Copie octet par octet l'adresse de la balise puis le convertit
	for(n = 0; n < strlen(address); n = n+2) {
		memcpy(aux, &address[n], 2);
		(res[n/2]) = (uint8_t) strtol(aux, &ptr, 16);
		printf("res : %u, n : %d \n", res[n/2], n/2);
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
            printf("found %d\n", i);
        } 
        else
            i++;
    }
    if(found)
        return i;
    else
        return -1;
}


int compareAddresses(address_t addrA, address_t addrB)
{
	int result=1;
	uint8_t i;
	
	for(i=0; i<ADDR_LEN; i++)
	{
   		//printf("beacon %u vs %u\n",addrA[i], addrB[i]);
		if(addrA[i]!=addrB[i]) {
			
			result=0;
			break;
		}
	}
	return result;
}


void updateBeaconTab(address_t addr, int8_t rssi)
{
    int8_t index=findBeaconInTab(addr);
    if(index!=-1)
    {
        refreshBeaconTTL(index);
        beaconTab[index].rssi=rssi;
    }
    else {
    	printf("ADDRESS ERROR \n");
    }
}


void UpdateTTLBeacons() {
  
	uint8_t i;
	struct timeval time;
	gettimeofday(&time, NULL);
	
	long long currentTime = time.tv_sec*1000 + time.tv_usec/1000;
  
	for(i = 0; i<NUMBER_BEACONS; i++) {
		
	  	if(currentTime - beaconTab[i].TTL >= 1500) {
	  		beaconTab[i].TTL = 0;
	  	}
	}
  
}


void refreshBeaconTTL(uint8_t index) {

	struct timeval time;
	gettimeofday(&time, NULL);
    beaconTab[index].TTL= time.tv_sec*1000 + time.tv_usec/1000;   
}


/****************************************
*               GETTER                  *
*****************************************/

int8_t getBeaconRssi(uint8_t index)
{
    return beaconTab[index].rssi;
}

double getBeaconTTL(uint8_t index)
{
    return beaconTab[index].TTL;
}

const t_beacon_info* getBeaconTab(void)
{
    return (const t_beacon_info*) beaconTab;
}

