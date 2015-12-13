#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include "message_drone.h"

#define DECOLLAGE 1
#define ATTERISSAGE 0
/*
 * Function done by Sheldon group
 */

FILE *result;
void parseSerialRead(char *buffer);
int checkAnswer(char *response);
char rawResponse[512];
int n=0;
int TTL=20;
int fd;
int commande=ATTERISSAGE;
  
  int sizeRawResponse;
  int vol = 0;
  char message [512];

int open_port(void);

void serial_config(int fd)
{
	struct termios options;
	tcgetattr(fd, &options);
	cfsetispeed(&options, B115200);
	cfsetospeed(&options, B115200);
	options.c_cflag |= (CLOCAL | CREAD);  // Enable local mode and the receiver
	options.c_cflag &= ~PARENB;  // Disable parity
	options.c_cflag &= ~CSTOPB;  // One stop bit
	options.c_cflag &= ~CSIZE;  // Clear data size bits
	options.c_cflag |= CS8;	 // Set 8 bits data size
	options.c_cflag &= ~CRTSCTS;	// Disable hardware flow control
	options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);  // Set raw input (unbuffered, no echo)
	options.c_iflag &= ~(IXON | IXOFF | IXANY);  // Disable software flow control
	options.c_oflag &= ~OPOST;  // Set raw output
	tcsetattr(fd, TCSAFLUSH, &options);
}


/*
 * 'open_port()' - Open serial port 1.
 *
 * Returns the file descriptor on success or -1 on error.
 */

int open_port(void)
{
    int fd; /* File descriptor for the port */

	    /////////////
        // Changer le nom du port
	    ////////

    fd = open("/dev/ttyO3", O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1)
    {
        /*
         * Could not open the port.
         */

        perror("open_port: Unable to open /dev/ttyO3. Is the cable plugged ?");
    }
    else
      printf("Port opened\n");
    
    //fcntl(fd, F_SETFL|O_NONBLOCK, 0);
    fcntl(fd, F_SETFL, 0);
    serial_config(fd);
    
    printf("Port configured\n");
    return (fd);
}


void read_port(void *arg)
{
  int spot = 0;
  char buf = '\0';
  
  /* Whole response*/

  printf("Read port thread started\n");
  while(1)
    {
      memset(rawResponse, '\0', sizeof rawResponse);
      buf = '\0';
      spot = 0;
      do {
	n = read( fd, &buf, 1 );
	if (n>0 && buf!='\n' && buf!='\r' && buf!=0)
	  {
	    strncpy(&rawResponse[spot], &buf, n);
	    spot += n;
	  }
      } while(buf!='\0' && buf != '\r' && buf != '\n' && n > 0);

      //Traitement
      if(spot>0 && spot>=14)
	{
	  //Ugly way to detect if detected beacon is beacon A or beacon B
	  if(rawResponse[13]=='6')
	    {
	      commande=DECOLLAGE;
	      printf("Beacon A\n");
	    }
	  else if (rawResponse[13]=='b')
	    {
	      commande=ATTERISSAGE;
	      printf("Beacon B\n");
	    }
	  else
	    printf ("Unrecognized beacon : %c\n", rawResponse[13]);
	}
    }
}

void close_port(int fd) {
	close(fd);
}

void setCommands(void *arg)
{
  while(1)
    {
      if(commande==DECOLLAGE)
	{
	  printf("Decollage !\n");
	  take_off(message);
	  
	}
      else if (commande ==ATTERISSAGE)
	{
	  printf("Atterissage !\n");
	  landing(message);
	}
      else
	{
	  //printf("Erreur : commande inconnue\n");
	}
      usleep(10000);
    }
}

int main()
{
 initialize_at_com();
 set_trim(message);
 sleep(1);
  
 pthread_t threadReadSerial, threadSendCommands;
 fd=open_port();

 if(pthread_create(&threadSendCommands, NULL, (void *)setCommands, NULL) == -1)
  {
    perror("pthread_create");
    return 1;
  }

 
 if(pthread_create(&threadReadSerial, NULL, (void *)read_port, NULL) == -1)
  {
    perror("pthread_create");
    return 1;
  }

  if (pthread_join(threadReadSerial, NULL))
  {
    perror("pthread_join");
    return 1;
  }

  if (pthread_join(threadSendCommands, NULL))
  {
    perror("pthread_join");
    return 1;
  } 

  while(1)
    {
      
    }
  terminate_at_com();
 return 0;
}

