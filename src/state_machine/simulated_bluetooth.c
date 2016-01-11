#include "simulated_bluetooth_com.h"

void *thread_Bluetooth(void *arg)
{
    int i;
    for(i = 0; i < 5; i++)
    {
        // Wait for user input
        getc(stdin);
	computeLocation();
    }
}

void read_data_bluetooth(float* _x, float* _y)
{    
    coord_t positions[5];

    positions[4].x = 3.25; positions[4].y = 11.0; // destination
    positions[3].x = 2.17; positions[3].y = 9.9;
    positions[2].x = 2.17; positions[2].y = 8.8;
    positions[1].x = 3.25; positions[1].y = 7.7;
    positions[0].x = 4.33; positions[0].y = 6.6; // start point

    static int i = 0;
    if(i >= 0 && i < 5)
    {
        *_x = positions[i].x;
        *_y = positions[i].y;
    }
    else
    {
        *_x = positions[i].x;
        *_y = positions[i].y;
    }
}
