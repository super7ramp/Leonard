/* Pour cross-compiler : 
arm-linux-gnueabi-gcc-4.6 -march=armv7-a -I lib/libpcap/include/ src/navdata_controller.c src/sender.c src/message_drone.c src/at-commands.c src/tests/test_navdata.c -o t_nav.elf -L lib/libpcap/lib -lpthread -lpcap
*/

#include <stdio.h>
#include "../navdata_controller.h"

void *autopilot()
{
    char buff[512];
    int t = 0;

    // Tell the drone that it is on a an horizontal plane
    set_trim(buff);

    // Keep connection alive for 2s
    while(t < 40)
    {
        reset_com(buff);
        usleep(50000);
        t++;
    }

    // Takeoff (5s)
    t = 0;
    while(t < 100)
	{
        take_off(buff);
        usleep(50000);
        t++;
    }

    // Magnetometer calibration
    t = 0;
    calibrate_magneto(buff);

    // Keep connection alive for another 5s then land (hopefully)
    while(t < 100)
    {
        usleep(50000);
        reset_com(buff);
        t++;
    }

    landing(buff);

    pthread_exit(NULL);
}

int main ()
{
    // AT communication initialization
    initialize_at_com();

    // Launch watchdog reset thread
    pthread_t autopilot_tid;
    pthread_create(&autopilot_tid, NULL, (void *) autopilot, NULL);

    // Launch navdata
    Navdata navdata;
    initNavdata();

    while(1)
    {
        if (isControllerReady())
        {
            navdata = getNavdata();

            // Checking header
            printf("[Checking header]\n");
            printf("magic : %x\n", navdata.header.magic);
            printf("sequence : %d\n", navdata.header.sequence);

            // Checking demo
            printf("[Checking demo]\n");
            printf("size : %d\n", navdata.demo.size);
            printf("bat : %d\n", navdata.demo.vbat_flying_percentage);
            printf("theta : %f\n", navdata.demo.theta);
            printf("phi : %f\n", navdata.demo.phi);
            printf("psi : %f\n", navdata.demo.psi);
            printf("vx : %f\n", navdata.demo.vx);
            printf("vy : %f\n", navdata.demo.vy);
            printf("vz : %f\n", navdata.demo.vz);

            // Checking Magneto
            printf("[Checking magneto]\n");
            printf("size: %d\n", navdata.magneto.size);
            printf("magneto_radius: %f\n", navdata.magneto.magneto_radius);
            printf("isCalibrated: %d\n", navdata.magneto.magneto_calibration_ok);
            printf("state: %d\n", navdata.magneto.magneto_state);
            printf("erro_mean: %f\n", navdata.magneto.error_mean);
            printf("erro_var: %f\n", navdata.magneto.error_var);
            printf("mx: %d\n", navdata.magneto.mx);
            printf("my: %d\n", navdata.magneto.my);
            printf("mz: %d\n", navdata.magneto.mz);
            printf("magneto_rectified: [%f,%f,%f]\n", navdata.magneto.magneto_rectified.v[0], navdata.magneto.magneto_rectified.v[1], navdata.magneto.magneto_rectified.v[2]);
            printf("magneto_offset: [%f,%f,%f]\n", navdata.magneto.magneto_rectified.v[0], navdata.magneto.magneto_rectified.v[1], navdata.magneto.magneto_rectified.v[2]);
            printf("heading_unwrapped: %f\n", navdata.magneto.heading_unwrapped);
            printf("heading_gyro_unwrapped: %f\n", navdata.magneto.heading_gyro_unwrapped);
            printf("heading_fusion_unwrapped: %f\n", navdata.magneto.heading_fusion_unwrapped);
        }
        sleep(1);

        // That was not my idea
        printf("\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A\e[A");

    }

    pthread_cancel(autopilot_tid);
    terminate_at_com();

    return 0;
}
