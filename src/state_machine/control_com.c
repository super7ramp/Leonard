#include "control_com.h"

#define MAX_SUB_STR_LENGTH  32
#define MAX_SEND_BUF_LENGTH 32
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

// Extract a substring from a string
int str_sub(const char *in, char *out, unsigned int start, unsigned int end)
{
    // Return -1 if in or out is not allocated
    if(!in || !out)
        return -1;

    size_t input_length = strlen(in);
    size_t output_length = (end - start + 1);

    // Return -2 if the given size parameters are invalid
    // The output_length + 1 check is for the \0 character
    if(start > end || start >= input_length || (output_length + 1) > MAX_SUB_STR_LENGTH)
        return -2;

    memcpy(out, &in[start], MIN(output_length, input_length - start + 1));
    out[output_length+1] = '\0';

    return 0;
}

// Ugly hack because we don't have time anymore: get the IP adress of the first valid device connected to the drone
char *getPcIPAdress()
{
    FILE *out;
    char *buf = calloc(32, sizeof(char));
    out = popen("echo -n $(arp -a | grep -v incomplete | grep -oE '[0-9]*\\.[0-9]*\\.[0-9]*\\.[0-9]*' | head -n 1)", "r");
    fgets(buf, 32, out);
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
    char msg[LG_MESS_DEFAUT];
    char s[MAX_SUB_STR_LENGTH];
    char send_buf[MAX_SEND_BUF_LENGTH];

    while(1)
    {

        recevoir(lg_message, msg);
        //récupération des donnée envoyé par le connectin Wifi
        //recept_orders_send_by_the_user
        //envoie de l'ordre reçu;

        if(str_sub(msg,s,0,1) < 0)
            order_recept = 11;
        else
            order_recept = atoi(s);

        //printf("Message reçu: %s\n", msg);
        printf("Valeur de order_recept = %d\n\n", order_recept);
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
                    str_sub(msg, s, 3, 7);
                    dest.x = atof(s);
                    str_sub(msg, s, 9, 13);
                    dest.y = atof(s);
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
                    sprintf(send_buf, "%f", Main_Nav.magneto.heading_fusion_unwrapped);
                    emettre(lg_message, msg, send_buf);
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
