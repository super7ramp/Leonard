#include "regulation.h"



void* thread_nvadata(void* arg)
{
	//thread neccessaire a la récupération des nvadtata envoyé par le drone

	while(1)
	{
		//récupération des donnée nvadata

		//envoie de l'ordre reçu;
		takeOff_();
		printf("bonjoirs\n");
	}  
}

float GetX(void)
{
	pthread_mutex_lock(&mutex_regulation);
	float x_local = 21;  //remplacer 21 par le variable contenant la valeur de x retourné par nvdata
	pthread_mutex_unlock(&mutex_regulation);
	return x_local;
}


float GetY(void)
{
	pthread_mutex_lock(&mutex_regulation);
	float y_local = 31;  //remplacer 31 par le variable contenant la valeur de y retourné par nvdata
	pthread_mutex_unlock(&mutex_regulation);
	return y_local;
}


float GetZ(void)
{
	pthread_mutex_lock(&mutex_regulation);
	float z_local = 41;  //remplacer 41 par le variable contenant la valeur de z retourné par nvdata
	pthread_mutex_unlock(&mutex_regulation);
	return z_local;
}


float GetAngle(void)
{
	pthread_mutex_lock(&mutex_regulation);
	float angle_local = 51;  //remplacer 51 par le variable contenant la valeur de l'angle_boussole retourné par nvdata
	pthread_mutex_unlock(&mutex_regulation);
	return angle_local;
}

void Get_localization(float* x_local, float* y_local)
{
	pthread_mutex_lock(&mutex_regulation);
	*x_local = 10; //remplacer 10 par la variance contenant la valeur de x retourné par le module bluetooth 
	*y_local = 20; //remplacer 20 par la variance contenant la valeur de y retourné par le module bluetooth

	newCoordXY = true;
	newAngle = true;
	newSpeed = true;
	pthread_mutex_unlock(&mutex_regulation);
}

void Set_nvdata(float theta, float phi, float psi, int altitude, float vx, float vy, float vz, int vbat_flying_percentage)
{
	pthread_mutex_lock(&mutex_regulation);

	data.theta = theta;
	data.phi = phi;
	data.psi = psi;
	data.altitude = altitude;
	data.vx	= vx;
	data.vy = vy;
	data.vz = vz;
	data.vbat_flying_percentage = vbat_flying_percentage;

	newSpeed = true;
	newAngle = true;
	newCoordZ = true; 
	pthread_mutex_unlock(&mutex_regulation);
}