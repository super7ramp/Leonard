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

// Ugly hack because we don't have time anymore: get the IP adress of the first valid device connected to the drone
char *getPcIPAdress()
{
    FILE *out;
    char *buf = calloc(32, sizeof(char));
    out = popen("echo -n $(arp -a | grep -v incomplete | grep -oE '[0-9]*\\.[0-9]*\\.[0-9]*\\.[0-9]*' | head -n 1)", "r");
    fgets(buf, 32, out);
    printf("Detected device: %s", buf);
    fclose(out);
    return buf;
}

void* thread_com(void* arg)
{
	//init socket
	initReceiver();
	sleep(1);

    char *destIP;
    destIP = getPcIPAdress();

	initSender(destIP);
    free(destIP);
	int order_recept;
	ORDER = NOTDONE;
	int i = 0;
	int lg_message =  LG_MESS_DEFAUT;
	order_recept = 0;
	dest.x = 1.083333333;
	dest.y = 1.1;
	char * msg = malloc(sizeof(char)*lg_message);
    char s[50] = "";

	while(1)
	{
        
		recevoir(lg_message, msg);
		//récupération des donnée envoyé par le connectin Wifi
		//recept_orders_send_by_the_user
		//envoie de l'ordre reçu;

		order_recept = atoi(str_sub(msg,0,1));
		//printf("Valeur de order_recept = %d\n", order_recept);
		if (ORDER == NOTDONE)
		{
			switch(order_recept){
				case 0: 
					calibHor();
					break;
				
				case 1:
					calibMagn();
					i=0;
					break;

				case 2:
					while(i<500)
					{
						land();						
						i++;
					}
					i=0;
					break;

				case 3:
					printf("décollage\n");
					while(i<500)
					{
						takeOff();						
						i++;
					}
					i=0;
					break;

				case 4:
					//printf("VAleur de move_Roll(%d,%f)\n",atoi(str_sub(msg,2,2)), atof(str_sub(msg,4,6)) );
					//move_Roll(atoi(str_sub(msg,2,2)), atof(str_sub(msg,4,6)));
					
					//move_Roll(0, 0.0);
					break;

				case 5:
					//printf("VAleur de move_Roll(%d,%f)\n",atoi(str_sub(msg,2,2)), atof(str_sub(msg,4,6)) );
					//move_Pitch(atoi(str_sub(msg,2,2)), atoi(str_sub(msg,4,6)));
					
					//move_Pitch(1, 0.0);
					break;

				case 6:
					//printf("VAleur de move_Roll(%d,%f)\n",atoi(str_sub(msg,2,2)), atof(str_sub(msg,4,4)), atof(str_sub(msg,6,8)), atof(str_sub(msg,10,12)) );
					//move_PitchRoll(atoi(str_sub(msg,2,2)), atoi(str_sub(msg,4,4)), atof(str_sub(msg,6,8)), atof(str_sub(msg,10,12)));
					
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
					printf("start_mission => communication with x=[%f] et y=[%f]\n", dest.x, dest.y);
					start_mission(dest.x, dest.y);
					ORDER = DONE;
					break;

				case 10:
					stop_mission();
					break;

				case 11 :
					Main_Nav = return_navdata();
					//send_navdata_to_the_user_via_socket
					sprintf(s, "%f", Main_Nav.magneto.heading_fusion_unwrapped);
					emettre(lg_message, msg, s);
					break;

				case 12 :
					break;

				default:
					break;
			}
			order_recept = 12;
		}
		else if(order_recept==10)
		{
			stop_mission();
			ORDER = NOTDONE;
		}
//		 Code pour la simulation de recepton de donnée Wifi
/*
		if(i<1000){
			//printf("decolle\n");
			order_recept = 3; //takeOff
		}
		else if(i>1000 && i<1800){
			order_recept = 11; //reset_com
			if(i==1010)
				order_recept = 1;
		}
                else if(i>1801 && i<1950){
                        order_recept = 7; // go up
                }
                else if(i==1951){
                        order_recept = 8;
                }
		//else if(i==1801){
		//	order_recept = 2; //land
		//}
		else if(i==1952){
			order_recept = 9; //start_mission
		}
		else if(i>1952){
			order_recept = 11; //attérisage
		}
		//printf("order_recept = %d  et i = %d et batterie =  \n", order_recept,i);
		i++;
		//printf("Debut de la pause de 20ms dans thread_com\n");
		usleep(20000);
		//printf("Fin de la pause de 20ms dans le thread_com\n");
	*/}  
}
