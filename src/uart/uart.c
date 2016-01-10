#include "uart.h"

int fd;
  
void initBluetoothCom()
{
  fd=open_port();
  
  //fcntl(fd, F_SETFL|O_NONBLOCK, 0);
  fcntl(fd, F_SETFL, 0); 
  //fcntl(fd, F_SETFL|O_NDELAY, 0);
  serial_config(fd);
}


int open_port(void)
{
    fd = open("/dev/ttyO3", O_RDWR | O_NOCTTY);
    if (fd == -1)
    {
         perror("open_port: Unable to open /dev/ttyO3.");
    }
    
    printf("Port configured\n");
    return (fd);
}

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
  options.c_cflag |= CS8;  // Set 8 bits data size
  options.c_cflag &= ~CRTSCTS;  // Disable hardware flow control
  options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);  // Set raw input (unbuffered, no echo)
  options.c_iflag &= ~(IXON | IXOFF | IXANY);  // Disable software flow control
  options.c_oflag &= ~OPOST;  // Set raw output
  options.c_cc[VMIN]=0;
  options.c_cc[VTIME]=1;
  tcsetattr(fd, TCSAFLUSH, &options);
}

void close_port(int fd) 
{
  close(fd);
}



void read_port(char *rawResponse, int *size)
{
  int spot = 0;
  char buf = '\0';
  int n=0;
  
  /* Whole response*/

  memset(rawResponse, '\0', sizeof rawResponse);
  buf = '\0';
  spot = 0;
  do {
    n = read(fd, &buf, 1 );
    if (n>0 && buf!='\n' && buf!='\r' && buf!=0)
      {
	strncpy(rawResponse+spot, &buf, n);
	spot += n;
      }
  } while(buf!='\0' && buf != '\r' && buf != '\n' && n > 0);
  
  //Si information reçue, alors traitement (mise à jour tab)
  if(spot>0)
    {
      *size=spot;
    }
}



