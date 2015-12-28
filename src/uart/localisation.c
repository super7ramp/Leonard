#include <stdio.h>   /* Standard input/output definitions */
#include <stdlib.h> 
#include <string.h>  /* String function definitions */
#include <stdint.h>
#include "parser.h"
#include "parameters.h"
#include "localisation.h"

t_location currentPos={0,0};

uint8_t IsIndexValid(uint8_t index)
{
  return (index>=0 && index<NUMBER_BEACONS);
}

void UpdateCurrentLocation()
{
  uint8_t numberOfVisibleBeacons=getVisibleBeaconsNumber();
  uint8_t index1=getIndexOfCloserBeacon(-1, -1);
  uint8_t index2=getIndexOfCloserBeacon(index1, -1);
  uint8_t index3=getIndexOfCloserBeacon(index1, index2);
  const t_beacon_info* beaconTab=getBeaconTab();

  switch(numberOfVisibleBeacons)
    {
    case 0:
      //printf("No beacon visible\r\n");
      break;
    case 1:
      if(IsIndexValid(index1))
	{
	  //printf("Closest beacon : %c\r\n", index1+65);
	  currentPos.x = beaconTab[index1].beaconInfo.detectedLocation.x;
	  currentPos.y = beaconTab[index1].beaconInfo.detectedLocation.y;
	}
      break;
    case 2: 
      if(IsIndexValid(index1) && IsIndexValid(index2))
	{
	  //printf("Closest beacons : %c %c\r\n", index1+65, index2+65);
	  currentPos.x = (beaconTab[index1].beaconInfo.detectedLocation.x + beaconTab[index2].beaconInfo.detectedLocation.x)/2;
	  currentPos.y = (beaconTab[index1].beaconInfo.detectedLocation.y + beaconTab[index2].beaconInfo.detectedLocation.y)/2;
	}
      break;
    default:
      if(IsIndexValid(index1) && IsIndexValid(index2) && IsIndexValid(index3))
	{
	  //printf("Closest beacons : %c %c %c\r\n", index1+65, index2+65, index3+65);
	  currentPos.x = (beaconTab[index1].beaconInfo.detectedLocation.x + beaconTab[index2].beaconInfo.detectedLocation.x + beaconTab[index3].beaconInfo.detectedLocation.x)/3;
	  currentPos.y = (beaconTab[index1].beaconInfo.detectedLocation.y + beaconTab[index2].beaconInfo.detectedLocation.y + beaconTab[index3].beaconInfo.detectedLocation.y)/3;
	}
      break;
    }
  printf("X : %.2f - Y : %.2f\r\n", currentPos.x, currentPos.y);
}

uint8_t getIndexOfCloserBeacon(int8_t ind1, int8_t ind2)
{
    const t_beacon_info* beaconTab=getBeaconTab();
    uint8_t index = -1, i;
    int8_t highestRssi = -100;
    
    for (i=0; i<NUMBER_BEACONS; i++)   
    {
    	if (beaconTab[i].TTL != 0) {
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
    }
    return index;
}

uint8_t getVisibleBeaconsNumber(void)
{
  uint8_t count=0;
  uint8_t loopCount=0;
  const t_beacon_info* beaconTab=getBeaconTab();
  for(loopCount=0; loopCount<NUMBER_BEACONS; loopCount++)
    {
      if (beaconTab[loopCount].rssi!=0)
	count++;
    }
  return count;
}

t_location getCurrentLocation(void)
{
    return currentPos;
}
