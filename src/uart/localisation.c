#include "localisation.h"

pthread_mutex_t m_current_location;

/*
 *History of last computed positions
 */
t_location posTab[NB_POS_HISTORY];

/*
 *Current position
 */
t_location currentPos={0.0,0.0};

void initLocationComputation()
{
  initPosTab();
  initBluetoothCom();
}

void computeLocation()
{
  int i=0;
  t_location sum={0.0, 0.0};

  //Read bluetooth data (blocking function)
  detectBeacons();

  //Compute position from stored data
  uint8_t numberOfBeacons=updateCurrentWeightedLocation();
  
  if(numberOfBeacons>3)
    numberOfBeacons=3;

  if (numberOfBeacons<=0)
    numberOfBeacons=1;

  pthread_mutex_lock(&m_current_location);
  for (i=0; i<numberOfBeacons*MEAN_FACTOR; i++)
  {
    sum.x+=posTab[i].x;
    sum.y+=posTab[i].y;
  }
  pthread_mutex_unlock(&m_current_location);
  currentPos.x=sum.x/numberOfBeacons/MEAN_FACTOR;
  currentPos.y=sum.y/numberOfBeacons/MEAN_FACTOR;
}

void detectBeacons()
{
  extract_data();
}

void initPosTab(void)
{
  pthread_mutex_init(&m_current_location, NULL);
  int i=0;
  pthread_mutex_lock(&m_current_location);
  for(i=0; i<NB_POS_HISTORY; i++)
  {
    posTab[i].x=0.0;
    posTab[i].y=0.0;
  }
  currentPos.x=0.0;
  currentPos.y=0.0;
  pthread_mutex_unlock(&m_current_location);
}

uint8_t IsIndexValid(uint8_t index)
{
  return (index<NUMBER_BEACONS);
}

uint8_t IsRssiValid(int8_t rssi)
{
  return(rssi<0 && rssi >= BLE_NANO_SENSI);
}	

uint8_t IsPositionInTheRoom(t_location computedPos)
{
  return (computedPos.x >= 0.0 && computedPos.y >= 0.0 && computedPos.x <= W && computedPos.y <= H);
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

int8_t getVisibleBeaconsNumber(int8_t *index1, int8_t* index2, int8_t* index3)
{
  int8_t count=0;
  *index1=getIndexOfClosestBeacon(-1,-1);
  if(*index1!=-1)
  {
    *index2=getIndexOfClosestBeacon(*index1, -1);
    if(*index2!=-1)
    {
      *index3=getIndexOfClosestBeacon(*index1, *index2);
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

uint8_t updateCurrentLocation()
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
      currentPos.x = beaconTab[index1].beaconInfo.beaconLocation.x;
      currentPos.y = beaconTab[index1].beaconInfo.beaconLocation.y;
      break;
    case 2: 
      currentPos.x = (beaconTab[index1].beaconInfo.beaconLocation.x + beaconTab[index2].beaconInfo.beaconLocation.x)/2;
      currentPos.y = (beaconTab[index1].beaconInfo.beaconLocation.y + beaconTab[index2].beaconInfo.beaconLocation.y)/2;
      break;
    default:
      currentPos.x = (beaconTab[index1].beaconInfo.beaconLocation.x + beaconTab[index2].beaconInfo.beaconLocation.x + beaconTab[index3].beaconInfo.beaconLocation.x)/3;
      currentPos.y = (beaconTab[index1].beaconInfo.beaconLocation.y + beaconTab[index2].beaconInfo.beaconLocation.y + beaconTab[index3].beaconInfo.beaconLocation.y)/3;
      break;
  }
  /*
   * We have to make sure that the computed position is not out of the considered room
   */
  if(IsPositionInTheRoom(currentPos))
    updatePosTab(currentPos);

  return numberOfVisibleBeacons;
}

uint8_t updateCurrentWeightedLocation()
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
      currentPos.x = beaconTab[index1].beaconInfo.beaconLocation.x;
      currentPos.y = beaconTab[index1].beaconInfo.beaconLocation.y;
      break;
    case 2: 
      ComputeWeightedPositionFrom2Beacons(&currentPos, beaconTab[index1], beaconTab[index2]);
      break;
    default:
      ComputeWeightedPositionFrom3Beacons(&currentPos, beaconTab[index1], beaconTab[index2], beaconTab[index3]);
      break;
  }


  updatePosTab(currentPos);
  if(IsPositionInTheRoom(currentPos))
  {
    printf("Position OK :                 %f-%f in     [0.00;%f]-[0.00;%f]\r\n", currentPos.x, currentPos.y, W, H);
  }
  else
    printf("Error : pos out of the room : %f-%f out of [0.00;%f]-[0.00;%f]\r\n", currentPos.x, currentPos.y, W, H);

  return numberOfVisibleBeacons;
}

int8_t getIndexOfClosestBeacon(int8_t ind1, int8_t ind2)
{
    const t_beacon_info* beaconTab=getBeaconTab();
    int8_t index = -1, i;
    int8_t highestRssi = BLE_NANO_SENSI;
    
    for (i=0; i<NUMBER_BEACONS; i++)   
    {
    	if (beaconTab[i].TTL != 0) 
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
    }
    return index;
}


void updatePosTab(t_location current)
{
  int i=0;
  pthread_mutex_lock(&m_current_location);
  for (i=0; i<NB_POS_HISTORY-1; i++)
  {
    posTab[NB_POS_HISTORY-i-1]=posTab[NB_POS_HISTORY-i-2];
  }
  posTab[0].x=current.x;
  posTab[0].y=current.y;
  pthread_mutex_unlock(&m_current_location);
}

t_location getCurrentLocation(void)
{
  return currentPos;
}


