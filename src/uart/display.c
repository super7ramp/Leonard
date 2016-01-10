#include "display.h"
#include "parser.h"

void printLocationFullDebug(t_location pos)
{
  printPositionOnMap(pos);
  printf("Visible beacons : ");
  printVisibleBeacons();
  printf("X : %.2f - Y : %.2f\r\n", pos.x, pos.y);
  printTab();
  printf("\033[%dA", (int)(H*ZOOM)+6);
}

void printPositionOnMap(t_location pos)
{
  int i,j;
  for (j=0; j<H*ZOOM; j++)
    {
      for(i=0; i<W*ZOOM; i++)
	{
	  if((int)(pos.x*ZOOM)==i && (int)(pos.y*ZOOM)==(int)(H*ZOOM)-j)
	    printf(" x ");
	  else if(j==0||j==(int)(H*ZOOM)-1)
	    printf("==");
	  else if(i==0||i==(int)(W*ZOOM)-1)
	    printf("|");
	  else
	    printf("   ");
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
	    
