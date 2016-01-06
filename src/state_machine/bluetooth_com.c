#include "bluetooth_com.h"

void *thread_Bluetooth(void *arg)
{
	position.x = 0.0;
	position.y = 0.0;
	data_point = 0;

	//mutex permettant de faire s'éxécuter le thread toute les CONTROLTASK_PERIODE_BLUETOOTH_MS
	//pthread_mutex_t verrou_bluetooth;
	//pthread_cond_t cond;  
  	//pthread_cond_init(&cond, NULL); 
  	//pthread_mutex_init(&verrou_bluetooth, NULL);


	//struct timeval tp;
  	//struct timespec ts;

        initLocationComputation();

	while(1)
	{
		/*gettimeofday(&tp, NULL);
		ts.tv_sec = tp.tv_sec;
    		ts.tv_nsec = tp.tv_usec * 1000;
    		//application de la nouvelle période d'éxécution du thread_envoi_ordre
    		ts.tv_nsec += CONTROLTASK_PERIOD_BLUETOOTH_MS * 1000000;
    		ts.tv_sec += ts.tv_nsec / 1000000000L;
    		ts.tv_nsec = ts.tv_nsec % 1000000000L;

    		pthread_mutex_lock(&verrou_bluetooth);
    		pthread_mutex_lock(&mutex_bluetooth);*/

		computeLocation();
		received_uart(data_point);
		data_to_coordinates();

		/*pthread_mutex_unlock(&mutex_bluetooth);
    		pthread_cond_timedwait(&cond, &verrou_bluetooth, &ts);
   		pthread_mutex_unlock(&verrou_bluetooth);*/ 
	}
}

void read_data_bluetooth(float* _x, float* _y)
{
	pthread_mutex_lock(&mutex_bluetooth);
	*_x = position.x;
	*_y = position.y;
	pthread_mutex_unlock(&mutex_bluetooth);
}

void data_to_coordinates()
{
	position.x = (float)data_point[0];
	position.y = (float)data_point[1];
}
