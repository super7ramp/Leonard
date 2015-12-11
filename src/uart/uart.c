#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
/*
 * Function done by Sheldon group
 */

FILE *result;
void parseSerialRead(char *buffer);
int checkAnswer(char *response);


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
    
    fcntl(fd, F_SETFL, 0);
   	serial_config(fd);
    
    return (fd);
}


int read_port(int fd) {

    int n = 0,
        spot = 0;
    char buf = '\0',
        response[512];
   

    while(1) {

        /* Whole response*/
        memset(response, '\0', sizeof response);
        buf = '\0';
        spot = 0;
    
        do {
            n = read( fd, &buf, 1 );
            //sprintf( &(response[spot]), "%c", buf );
            //response[spot] = buf;
            strncpy(&response[spot], &buf, n);
            printf("%c", buf);
            spot += n;
        } while( buf != '\r' && buf != '\n' && buf !=' ' && n > 0);
	
	if(n>0)
	    fprintf(result, "%s\n", response);
	
        
    }
}

int close_port(int fd) {
	close(fd);
}


int main() {
   result=fopen("resultat.txt", "w");
 	
   int fd = open_port();
    read_port(fd);
}

