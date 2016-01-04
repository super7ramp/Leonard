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
      break;
    case 1:
      if(IsIndexValid(index1))
	{
	  currentPos.x = beaconTab[index1].beaconInfo.beaconLocation.x;
	  currentPos.y = beaconTab[index1].beaconInfo.beaconLocation.y;
	}
      break;
    case 2: 
      if(IsIndexValid(index1) && IsIndexValid(index2))
	{
	  currentPos.x = (beaconTab[index1].beaconInfo.beaconLocation.x + beaconTab[index2].beaconInfo.beaconLocation.x)/2;
	  currentPos.y = (beaconTab[index1].beaconInfo.beaconLocation.y + beaconTab[index2].beaconInfo.beaconLocation.y)/2;
	}
      break;
    default:
      if(IsIndexValid(index1) && IsIndexValid(index2) && IsIndexValid(index3))
	{
	  currentPos.x = (beaconTab[index1].beaconInfo.beaconLocation.x + beaconTab[index2].beaconInfo.beaconLocation.x + beaconTab[index3].beaconInfo.beaconLocation.x)/3;
	  currentPos.y = (beaconTab[index1].beaconInfo.beaconLocation.y + beaconTab[index2].beaconInfo.beaconLocation.y + beaconTab[index3].beaconInfo.beaconLocation.y)/3;
	}
      break;
    }
  //printf("X : %.2f - Y : %.2f\r", currentPos.x, currentPos.y);
}

void ComputeWeightedPositionFrom2Beacons(t_location* result, t_beacon_info beacon1, t_beacon_info beacon2)
{
  float rssi1_norm=(BLE_NANO_SENSI-beacon1.rssi)/(BLE_NANO_SENSI);
  float rssi2_norm=(BLE_NANO_SENSI-beacon2.rssi)/(BLE_NANO_SENSI);

  result->x=(beacon1.beaconInfo.beaconLocation.x*rssi1_norm+beacon2.beaconInfo.beaconLocation.x*rssi2_norm)/(rssi1_norm+rssi2_norm);
  result->y=(beacon1.beaconInfo.beaconLocation.y*rssi1_norm+beacon2.beaconInfo.beaconLocation.y*rssi2_norm)/(rssi1_norm+rssi2_norm);
}

void ComputeWeightedPositionFrom3Beacons(t_location* result, t_beacon_info beacon1, t_beacon_info beacon2, t_beacon_info beacon3)
{
  float rssi1_norm=(BLE_NANO_SENSI-beacon1.rssi)/(BLE_NANO_SENSI);
  float rssi2_norm=(BLE_NANO_SENSI-beacon2.rssi)/(BLE_NANO_SENSI);
  float rssi3_norm=(BLE_NANO_SENSI-beacon3.rssi)/(BLE_NANO_SENSI);

  result->x=(beacon1.beaconInfo.beaconLocation.x*rssi1_norm+beacon2.beaconInfo.beaconLocation.x*rssi2_norm+beacon3.beaconInfo.beaconLocation.x*rssi3_norm)/(rssi1_norm+rssi2_norm+rssi3_norm);
  result->y=(beacon1.beaconInfo.beaconLocation.y*rssi1_norm+beacon2.beaconInfo.beaconLocation.y*rssi2_norm+beacon3.beaconInfo.beaconLocation.y*rssi3_norm)/(rssi1_norm+rssi2_norm+rssi3_norm);
}

void checkBeaconInfoConsistency(int8_t r, int8_t a, int8_t b, int8_t c)
{
  if((r==0 && (a!=-1||b!=-1||c!=-1))||
     (r==1 && (a==-1 && b==-1 && c==-1))||
     (r==1 && ((a!=-1 && b!=-1)||(a!=-1 && c!=-1)||(b!=-1 && c!=-1)))||
     (r==2 && (a==-1 && b==-1 && c==-1))||
     (r==2 && ((a==1 && b==1)||(a==1 && c==1)||(b==1 && c==1)))|| 
     (r==3 && (a==-1||b==-1||c==-1)))
    printf("Alert info beacon !!!");
}

void UpdateCurrentWeightedLocation()
{
  int8_t numberOfVisibleBeacons=getVisibleBeaconsNumber();
  int8_t index1=getIndexOfCloserBeacon(-1, -1);
  int8_t index2=getIndexOfCloserBeacon(index1, -1);
  int8_t index3=getIndexOfCloserBeacon(index1, index2);
  const t_beacon_info* beaconTab=getBeaconTab();
  
  checkBeaconInfoConsistency(numberOfVisibleBeacons, index1, index2, index3);
  switch(numberOfVisibleBeacons)
    {
    case 0:
      break;
    case 1:
      if(IsIndexValid(index1))
	{
	  currentPos.x = beaconTab[index1].beaconInfo.beaconLocation.x;
	  currentPos.y = beaconTab[index1].beaconInfo.beaconLocation.y;
	}
      break;
    case 2: 
      if(IsIndexValid(index1) && IsIndexValid(index2))
	{
	  ComputeWeightedPositionFrom2Beacons(&currentPos, beaconTab[index1], beaconTab[index2]);
	}
      break;
    default:
      if(IsIndexValid(index1) && IsIndexValid(index2) && IsIndexValid(index3))
	{
	  ComputeWeightedPositionFrom3Beacons(&currentPos, beaconTab[index1], beaconTab[index2], beaconTab[index3]);
	}
      break;
    }
  //printf("X : %.2f - Y : %.2f\r", currentPos.x, currentPos.y);
}

int8_t getIndexOfCloserBeacon(int8_t ind1, int8_t ind2)
{
    const t_beacon_info* beaconTab=getBeaconTab();
    int8_t index = -1, i;
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

int8_t getVisibleBeaconsNumber(void)
{
  int8_t count=0;
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
