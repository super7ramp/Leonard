#ifndef __SPOOF_UDP_H
#define __SPOOF_UDP_H

#include <stdio.h> //for printf
#include <string.h> //memset
#include <sys/socket.h>    //for socket ofcourse
#include <stdlib.h> //for exit(0);
#include <errno.h> //For errno - the error number
#include <netinet/udp.h>   //Provides declarations for udp header
#include <netinet/ip.h>    //Provides declarations for ip header
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdint.h>

#define FAKE_ADDR_SRC		"127.0.0.2"
#define PORT_FAKE_ADDR		5554
#define ADDR_DEST_LOCALHOST	"127.0.0.1"
#define PORT_LOCALHOST		5554

struct pseudo_header
{
	uint32_t source_address;
	uint32_t dest_address;
	uint8_t placeholder;
	uint8_t protocol;
	uint16_t udp_length;
};

int spoof_udp ();
unsigned short csum(unsigned short *ptr,int nbytes);

#endif

