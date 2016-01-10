#include "localisation.h"
#include "display.h"
int main()
{
	initLocationComputation();
	while(1)
	{
		computeLocation();
		printLocationFullDebug(getCurrentLocation());
	}
	return 0;
}
