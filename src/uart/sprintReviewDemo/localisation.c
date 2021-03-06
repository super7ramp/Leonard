#include <stdio.h>   /* Standard input/output definitions */
#include <stdlib.h> 
#include <string.h>  /* String function definitions */
#include <stdint.h>
#include "parser.h"
#include "parameters.h"
#include "localisation.h"

t_location currentPos={0,0};

void updateCurrentLocation()
{
    const t_beacon_info* beaconTab=getBeaconTab();
    uint8_t index1 = getIndexOfCloserBeacon(-1, -1);
    uint8_t index2 = getIndexOfCloserBeacon(index1, -1);
    uint8_t index3 = getIndexOfCloserBeacon(index1, index2);
    
    //If three beacon has been discovered
    if (index1!=-1 && index2!=-1 && index3!=-1) {
    	currentPos.x = (beaconTab[index1].beaconInfo.detectedLocation.x + beaconTab[index2].beaconInfo.detectedLocation.x + beaconTab[index3].beaconInfo.detectedLocation.x)/3;
        currentPos.y = (beaconTab[index1].beaconInfo.detectedLocation.y + beaconTab[index2].beaconInfo.detectedLocation.y + beaconTab[index3].beaconInfo.detectedLocation.y)/3;
    }
    else if (index1!=-1 && index2!=-1) {
    
    }
    else if (index1!=-1) {
    
    }
    

    //If there is at least one beacon visible, we update location
    /*if(beaconTab[index].rssi!=0)
    {
        currentPos.x=beaconTab[index].beaconInfo.detectedLocation.x;
        currentPos.y=beaconTab[index].beaconInfo.detectedLocation.y;
    }*/
    //Else, location remains unchanged
}

uint8_t getIndexOfCloserBeacon(int8_t ind1, int8_t ind2)
{
    const t_beacon_info* beaconTab=getBeaconTab();
    uint8_t index = 0, i;
    int8_t highestRssi=beaconTab[index].rssi;
    
    for (i=0; i<NUMBER_BEACONS; i++)   
    {
        if (ind1==-1 && ind2==-1 && beaconTab[i].rssi!=0 && (highestRssi==0||beaconTab[i].rssi>highestRssi))
        {
			index=i;
            highestRssi=beaconTab[i].rssi;
        }
        else if (ind1!=-1 && ind2==-1 && beaconTab[i].rssi!=0 && i!=ind1 && (highestRssi==0||beaconTab[i].rssi>highestRssi)) {
        	index=i;
            highestRssi=beaconTab[i].rssi;
        } 
        else if (ind1!=-1 && ind2!=-1 && beaconTab[i].rssi!=0 && i!=ind1 && i!=ind2 && (highestRssi==0||beaconTab[i].rssi>highestRssi)) {
         	index=i;
            highestRssi=beaconTab[i].rssi;
        }
    }
    return index;
}


t_location getCurrentLocation(void)
{
    return currentPos;
}
