#include <stdio.h>
#include <unistd.h>
#include "message_drone.h"

int main ()
{
    char message [512];
    int n = 1;
    int tps = 1;

    if (initialize_socket() != 0)
    {
        printf("[FAILED] Socket initialization failed\n");
    }
    else
    {
        sleep(1);
        set_trim(message, n++);
        usleep(500000);
////////////// take off //////////////////////////
        while(tps < 167)                        //100 avec 50ms
        {
                take_off(message, n++);
                usleep(30000);
                tps++;
        }
        tps = 0;
////////////// WAIT ////////////////////
        while(tps < 133)                        //80
        {
                reset_com(message);
                usleep(30000);
                tps++;
        }
        tps = 0;
////////////// GO ////////////////////
        while(tps < 58)                         //35
        {
                set_pitch(message, n++, FRONT, 0.25);
                usleep(30000);
                tps++;
        }
        tps = 0;
        while(tps < 17)                         //10
        {
                set_pitch(message, n++, BACK, 0.25);
                usleep(30000);
                tps++;
        }
        tps = 0;
        while(tps < 17)
        {
                set_pitch(message, n++, FRONT, 0.0);
                usleep(30000);
                tps++;
        }
        tps = 0;
////////////// WAIT ////////////////////
        while(tps < 25)
        {
                reset_com(message);
                usleep(30000);
                tps++;
        }
        tps = 0;
////////////// ROTATE ////////////////////
        while(tps < 110)                        //140
        {
                set_yaw(message, n++, LEFT, 0.4);
                usleep(30000);
                tps++;
        }
        tps = 0;
        set_yaw(message, n++, RIGHT, 0.0);
        usleep(30000);
////////////// WAIT ////////////////////
        while(tps < 80)
        {
                reset_com(message);
                usleep(30000);
                tps++;
        }
        tps = 0;
////////////// RETURN ////////////////////
        while(tps < 58)
        {
                set_pitch(message, n++, FRONT, 0.25);
                usleep(30000);
                tps++;
        }
        tps = 0;
        while(tps < 17)
        {
                set_pitch(message, n++, BACK, 0.25);
                usleep(30000);
                tps++;
        }
        tps = 0;
        while(tps < 17)
        {
                set_pitch(message, n++, FRONT, 0.0);
                usleep(30000);
                tps++;
        }
        tps = 0;
////////////// WAIT ////////////////////
        while(tps < 167)
        {
                reset_com(message);
                usleep(30000);
                tps++;
        }
        tps = 0;
////////////// LAND ////////////////////
        landing(message, n++);
        sleep(1);
    }
    close_socket();
    return 0;
}
