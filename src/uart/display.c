#include "display.h"
#include "parser.h"

void printLocationFullDebug(t_location pos)
{
  printPositionOnMap(pos);
  printf("Visible beacons : ");
  printVisibleBeacons();
  printf("X : %.2f - Y : %.2f\r\n", pos.x, pos.y);
  //printBeaconsTab();
  printf("\033[%dA", (int)(H*ZOOM_Y)+2);
}

void printPositionOnMap(t_location pos)
{
  int i,j;
  int h=(int)H, w=(int)W;

  for (j=0; j<h*ZOOM_Y; j++)
    {
      for(i=0; i<w*ZOOM_X; i++)
      {
        if((int)(pos.x*ZOOM_X)==i && (int)(pos.y*ZOOM_Y)==(int)(h*ZOOM_Y)-j)
          printf("x");
        else if(j==0||j==(int)(h*ZOOM_Y)-1)
          printf("=");
        else if(i==0||i==(int)(w*ZOOM_X)-1)
          printf("|");
        else
          printf(" ");
      }
      printf("\r\n");
    }
}

void printBasicInformation(t_location pos)
{
  printf("Visible beacons : ");
  printVisibleBeacons();
  printf("X : %.2f - Y : %.2f\n", pos.x, pos.y);
  printf("\e[A\e[A");
}
	    
