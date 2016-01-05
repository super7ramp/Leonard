#include <stdio.h>   /* Standard input/output definitions */
#include <stdlib.h> 
#include <string.h>  /* String function definitions */
#include <stdint.h>
#include "parser.h"
#include "parameters.h"
#include "localisation.h"

t_location posTab[NB_POS_HISTORY];

uint8_t IsIndexValid(uint8_t index)
{
  return (index>=0 && index<NUMBER_BEACONS);
}

uint8_t IsRssiValid(int8_t rssi)
{
  return(rssi<0);
}	

void UpdateCurrentLocation()
{
  int8_t index1, index2, index3;
  uint8_t numberOfVisibleBeacons=getVisibleBeaconsNumber(&index1, &index2, &index3);
  const t_beacon_info* beaconTab=getBeaconTab();
  t_location currentPos={0,0};
  switch(numberOfVisibleBeacons)
    {
    case 0:
      break;
    case 1:
      //if(IsIndexValid(index1))
	//{
	  currentPos.x = beaconTab[index1].beaconInfo.beaconLocation.x;
	  currentPos.y = beaconTab[index1].beaconInfo.beaconLocation.y;
	//}
      break;
    case 2: 
      //if(IsIndexValid(index1) && IsIndexValid(index2))
	//{
	  currentPos.x = (beaconTab[index1].beaconInfo.beaconLocation.x + beaconTab[index2].beaconInfo.beaconLocation.x)/2;
	  currentPos.y = (beaconTab[index1].beaconInfo.beaconLocation.y + beaconTab[index2].beaconInfo.beaconLocation.y)/2;
	//}
      break;
    default:
      //if(IsIndexValid(index1) && IsIndexValid(index2) && IsIndexValid(index3))
	//{
	  currentPos.x = (beaconTab[index1].beaconInfo.beaconLocation.x + beaconTab[index2].beaconInfo.beaconLocation.x + beaconTab[index3].beaconInfo.beaconLocation.x)/3;
	  currentPos.y = (beaconTab[index1].beaconInfo.beaconLocation.y + beaconTab[index2].beaconInfo.beaconLocation.y + beaconTab[index3].beaconInfo.beaconLocation.y)/3;
	//}
      //break;
    }
  //printf("X : %.2f - Y : %.2f\r", currentPos.x, currentPos.y);
  updatePosTab(currentPos);
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

void UpdateCurrentWeightedLocation()
{
  int8_t index1, index2, index3;
  int8_t numberOfVisibleBeacons=getVisibleBeaconsNumber(&index1, &index2, &index3);
  const t_beacon_info* beaconTab=getBeaconTab();
  t_location currentPos={0, 0};

  switch(numberOfVisibleBeacons)
    {
    case 0:
      break;
    case 1:
      //if(IsIndexValid(index1))
	//{
	  currentPos.x = beaconTab[index1].beaconInfo.beaconLocation.x;
	  currentPos.y = beaconTab[index1].beaconInfo.beaconLocation.y;
	//}
      break;
    case 2: 
      //if(IsIndexValid(index1) && IsIndexValid(index2))
	//{
	  ComputeWeightedPositionFrom2Beacons(&currentPos, beaconTab[index1], beaconTab[index2]);
	//}
      break;
    default:
      //if(IsIndexValid(index1) && IsIndexValid(index2) && IsIndexValid(index3))
	//{
	  ComputeWeightedPositionFrom3Beacons(&currentPos, beaconTab[index1], beaconTab[index2], beaconTab[index3]);
	//}
      break;
    }
  //printf("X : %.2f - Y : %.2f\r", currentPos.x, currentPos.y);
 if(currentPos.x>0 && currentPos.y > 0 && currentPos.x<=W && currentPos.y<=H)
  updatePosTab(currentPos);
}

int8_t getIndexOfCloserBeacon(int8_t ind1, int8_t ind2)
{
    const t_beacon_info* beaconTab=getBeaconTab();
    int8_t index = -1, i;
    int8_t highestRssi = BLE_NANO_SENSI;
    
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

int8_t getVisibleBeaconsNumber(int8_t *index1, int8_t* index2, int8_t* index3)
{
  int8_t count=0;
  /*uint8_t loopCount=0;
  const t_beacon_info* beaconTab=getBeaconTab();
  for(loopCount=0; loopCount<NUMBER_BEACONS; loopCount++)
    {
      if (beaconTab[loopCount].rssi!=0)
	count++;
    }*/
  *index1=getIndexOfCloserBeacon(-1,-1);
  if(*index1!=-1)
  {
    *index2=getIndexOfCloserBeacon(*index1, -1);
    if(*index2!=-1)
    {
      *index3=getIndexOfCloserBeacon(*index1, *index2);
      if(*index3!=-1)
      {
        count=3;
      }
      else
      {
        count=2;
      }
    }
    else
    {
      count=1;
    }
  }
  else
  {
    count=0;
  }	
  return count;
}

void initPosTab(void)
{
  int i=0;
  for(i=0; i<NB_POS_HISTORY; i++)
  {
    posTab[i].x=0.0;
    posTab[i].y=0.0;
  }
}

void updatePosTab(t_location current)
{
  int i=0;
  for (i=0; i<NB_POS_HISTORY; i++)
  {
    posTab[NB_POS_HISTORY-i-1]=posTab[NB_POS_HISTORY-i-2];
  }
  posTab[0].x=current.x;
  posTab[0].y=current.y;
}

t_location getCurrentLocation(void)
{
  int i=0;
  t_location sum={0.0, 0.0};
  for (i=0; i<NB_POS_HISTORY; i++)
  {
    sum.x+=posTab[i].x;
    sum.y+=posTab[i].y;
  }
    return (t_location){sum.x/NB_POS_HISTORY, sum.y/NB_POS_HISTORY};
}
