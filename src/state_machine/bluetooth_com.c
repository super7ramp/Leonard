#include "bluetooth_com.h"
void *thread_Bluetooth(void *arg)
{
    initLocationComputation();

	while(1)
	{
		// Blocking function, cannot go faster than 500/8 ms
		computeLocation();
	}
}

void read_data_bluetooth(float* _x, float* _y)
{
	t_location pos=getCurrentLocation();
    *_x = pos.x;
	*_y = pos.y;
}
