#include "display.h"
#include "parser.h"

void printPositionOnMap(t_location pos)
{
  int i,j;
  for (j=0; j<H; j++)
    {
      for(i=0; i<W; i++)
	{
	  if((int)(pos.x)==i && (int)(pos.y)==(int)(H)-1-j)
	    printf(" x ");
	  else if(j==0||j==(int)(H)-1)
	    printf("==");
	  else if(i==0||i==(int)(W)-1)
	    printf("|");
	  else
	    printf("   ");
	}
      printf("\r\n");
    }
  printf("Visible beacons : ");
  printVisibleBeacons();
  printf("X : %.2f - Y : %2.f\r\n", pos.x, pos.y);
  printf("\033[%dA", (int)H+2);
}
	    
