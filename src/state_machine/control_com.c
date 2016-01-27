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

    size_t copied_length = MIN(output_length, input_length - start + 1);
    memcpy(out, &in[start], copied_length);
    out[copied_length] = '\0';

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
    char *destIP = NULL;
    int order_recept;
    ORDER = NOTDONE;
    int i = 0;
    int lg_message =  LG_MESS_DEFAUT;
    char msg[LG_MESS_DEFAUT];
    char s[MAX_SUB_STR_LENGTH];
    char send_buf[MAX_SEND_BUF_LENGTH];

    float sending_B_Px = 0.0;
    float sending_B_Py = 0.0;

    while(1)
    {
        initReceiver();
        sleep(1);

        destIP = getPcIPAdress();
        initSender(destIP);
        free(destIP);
        destIP = NULL;

        int eof = 0;
        order_recept = 0;

        // If the client disconnects, eof (end-of-file) will switch to 1
        while(!eof)
        {
            //printf("avant recevoir\n");
            eof = recevoir(lg_message, msg);
            //printf("après recevoir\n");

            if(str_sub(msg,s,0,1) < 0)
                order_recept = 11;
            else
                order_recept = atoi(s);

            //printf("Message reçu: %s\n", msg);
            //printf("Valeur de order_recept = %d\n\n", order_recept);
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
                        //printf("décollage\n");
                        while(i<500)
                        {
                            takeOff();
                            i++;
                        }
                        i=0;
                        break;

                    case 4:
                        while(i<100)
                        {
                            move_Roll(LEFT, 0.1);
                            usleep(20000);
                            i++;
                        }
                        move_Roll(RIGHT, 0.0);
                        i=0;
                        break;

                    case 5:
                        i = 0;
                        while(i<100)
                        {
                            move_Pitch(FRONT, 0.1);
                            usleep(20000);
                            i++;
                        }
                        move_Pitch(BACK, 0.0);
                        i=0;
                        break;

                    case 6:
                        i = 0;
                        while(i<100)
                        {
                            move_PitchRoll(FRONT, LEFT, 0.1, 0.1);
                            i++;
                        }
                        move_PitchRoll(BACK, RIGHT, 0.0, 0.0);
                        i=0;
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
                        //Main_Nav = return_navdata();
                        read_data_bluetooth(&sending_B_Px,&sending_B_Py);
                        //send_navdata_to_the_user_via_socket
                        sprintf(send_buf, "%f, %f", sending_B_Px, sending_B_Py);
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
            else if(order_recept == 11)
            {
                //Main_Nav = return_navdata();
                read_data_bluetooth(&sending_B_Px,&sending_B_Py);
                //send_navdata_to_the_user_via_socket
                sprintf(send_buf, "%f, %f", sending_B_Px, sending_B_Py);
                emettre(lg_message, msg, send_buf);
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
             */
        }

        // We got disconnected
        closeSender();
        closeReceiver();
        sleep(1);
    }
}
