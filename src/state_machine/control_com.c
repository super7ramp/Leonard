#include "control_com.h"

void* thread_com(void* arg)
{
	//initialisation de la connection UDP entre le logiciel embarqué et l'IHM
	
	int order_recept;
	ORDER = NOTDONE;
	int i = 0;
	order_recept = 0;
	destination.x = 40.0;
	destination.y = 40.0;
	while(1)
	{
		//récupération des donnée envoyé par le connectin Wifi
		//printf("passage dans la boucle while(1) de thread_com\n");
		//envoie de l'ordre reçu;
		if (ORDER == NOTDONE)
		{
			switch(order_recept){
				case 0:
					calibHor();
					break;
				
				case 1:
					calibMagn();
					break;

				case 2:
					land();
					break;

				case 3:
					takeOff();
					break;

				case 4:
					move_Roll(0, 0.0);
					break;

				case 5:
					move_Pitch(1, 0.0);
					break;

				case 6:
					move_PitchRoll(1, 0, 0.0, 0.0);
					break;

				case 7:
					emergency_();
					break;

				case 8:
					anti_emergency_();
					break; 

				case 9: 
					printf("start_mission => communication\n");
					start_mission(destination.x, destination.y);
					ORDER = DONE;
					break;

				case 10:
					stop_mission();
					break;

				case 11 :
					break;

				default:
					break;
			}
			
			if(i<1000){
				order_recept = 3; //takeOff
			}
			else if(i>1000 && i<1800){
				order_recept = 11; //reset_com
				if(i==1010)
					order_recept = 1;
			}
			else if(i==1801){
				order_recept = 9; //start_mission
			}
			else if(i>1801){
				order_recept = 2; //attérisage
			}
			//printf("order_recept = %d  et i = %d et batterie =  \n", order_recept,i);
			i++;
			//printf("Debut de la pause de 20ms dans thread_com\n");
			usleep(10000);
			//printf("Fin de la pause de 20ms dans le thread_com\n");
			
		}
	}  
}
