#include "control_com.h"

char *str_sub (const char *s, unsigned int start, unsigned int end)
{
   char *new_s = NULL;

   if (s != NULL && start < end)
   {
/* (1)*/
      new_s = malloc (sizeof (*new_s) * (end - start + 2));
      if (new_s != NULL)
      {
         int i;

/* (2) */
         for (i = start; i <= end; i++)
         {
/* (3) */
            new_s[i-start] = s[i];
         }
         new_s[i-start] = '\0';
      }
      else
      {
         fprintf (stderr, "Memoire insuffisante\n");
         exit (EXIT_FAILURE);
      }
   }
   return new_s;
}



void* thread_com(void* arg)
{
	//init socket
	initReceiver();
	
	int order_recept;
	ORDER = NOTDONE;
	int i = 0;
	int lg_message =  LG_MESS_DEFAUT;
	order_recept = 0;
	dest.x = 1.083333333;
	dest.y = 1.1;
	char * msg = malloc(sizeof(char)*lg_message);
	
	while(1)
	{
	
		recevoir(lg_message, msg);
		//récupération des donnée envoyé par le connectin Wifi
		//recept_orders_send_by_the_user
		//envoie de l'ordre reçu;

		order_recept = atoi(str_sub(msg,0,1));
		printf("\n\n\n\nValeur de order_recept%d\n\n\n", order_recept);
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
					printf("VAleur de move_Roll(%d,%f)\n",atoi(str_sub(msg,2,2)), atof(str_sub(msg,4,6)) );
					move_Roll(atoi(str_sub(msg,2,2)), atof(str_sub(msg,4,6)));
					
					//move_Roll(0, 0.0);
					break;

				case 5:
					printf("VAleur de move_Roll(%d,%f)\n",atoi(str_sub(msg,2,2)), atof(str_sub(msg,4,6)) );
					move_Pitch(atoi(str_sub(msg,2,2)), atoi(str_sub(msg,4,6)));
					
					//move_Pitch(1, 0.0);
					break;

				case 6:
					printf("VAleur de move_Roll(%d,%f)\n",atoi(str_sub(msg,2,2)), atof(str_sub(msg,4,4)), atof(str_sub(msg,6,8)), atof(str_sub(msg,10,12)) );
					move_PitchRoll(atoi(str_sub(msg,2,2)), atoi(str_sub(msg,4,4)), atof(str_sub(msg,6,8)), atof(str_sub(msg,10,12)));
					
					//move_PitchRoll(1, 0, 0.0, 0.0);
					break;

				case 7:
					emergency_();
					break;

				case 8:
					anti_emergency_();
					break; 

				case 9:
					dest.x = atof(str_sub(msg,3,7));
					dest.y = atof(str_sub(msg,9,13));
					printf("start_mission => communication\n");
					start_mission(dest.x, dest.y);
					ORDER = DONE;
					break;

				case 10:
					stop_mission();
					break;

				case 11 :
					//Main_Nav = return_navdata();
					//send_navdata_to_the_user_via_socket
					break;

				default:
					break;
			}
		}
		else if(order_recept==10)
		{
			stop_mission();
		}
/*		 Code pour la simulation de recepton de donnée Wifi	
		if(i<1000){
			//printf("decolle\n");
			order_recept = 3; //takeOff
		}
		else if(i>1000 && i<1800){
			order_recept = 11; //reset_com
			if(i==1010)
				order_recept = 1;
		}
		else if(i==1801){
			order_recept = 2; //land
		}
		else if(i==1802){
			order_recept = 9; //start_mission
		}
		else if(i>1802){
			order_recept = 11; //attérisage
		}
		//printf("order_recept = %d  et i = %d et batterie =  \n", order_recept,i);
		i++;
		//printf("Debut de la pause de 20ms dans thread_com\n");
		usleep(10000);
		//printf("Fin de la pause de 20ms dans le thread_com\n");*/
	}  
}
