#include <stdio.h>
#include "navdata_controller.h"
#include <pthread.h>
#include "pcap/pcap.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <stdlib.h>

static socket_info_t navdata_socket;
int m_available = 0;
Navdata m_navdata;

//Fonction qui intercepte les packets et appelle la fonction M_decode()
void action_on_packet_reception(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    // This a callback function
   int size = header->len;

   struct iphdr* iph = (struct iphdr*)(packet + sizeof(struct ethhdr));
   unsigned short iphdrlen = iph->ihl * 4;

   // Filter protocol
   if(iph->protocol != 17)
       return;

   // Get the destination IP address and filter
   struct sockaddr_in dest;
   memset(&dest, 0, sizeof(dest));
   dest.sin_addr.s_addr = iph->daddr;
   if(dest.sin_addr.s_addr != inet_addr(DEST_IP_NAV))
       return;

   // Get the UDP header
   struct udphdr* udph = (struct udphdr*)(packet + iphdrlen + sizeof(struct ethhdr));

   // Filter out ports
   if(ntohs(udph->dest) != DEST_PORT_NAV)
       return;

   // Get the data from the sniffed packet
   int header_size = sizeof(struct ethhdr) + iphdrlen + sizeof(struct udphdr) + 4; //@FIXME: why the +4 ???
   const unsigned char* data = packet + header_size;

   M_decode(data, size - header_size);
}

//Fonction bloquante à lancer dans un autre thread qui lancera l'appel à la fonction action_on_packet_reception()
void *setup_pcap ()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

  printf("Device: %s\n", IFACE);

  // Open device
  handle = pcap_open_live(IFACE, BUFSIZ, 1, 0, errbuf);
  if (handle == NULL)
  {
      fprintf(stderr, "Couldn't open device %s: %s\n", IFACE, errbuf);
      return 0;
  }

  printf("pcap initialized\n");

  pcap_loop(handle, -1, &action_on_packet_reception, NULL);

  printf("pcap session finished");
  return 0;

}

//Analyse les packets 
void M_decode(const u_char *data, int size)
{
	navdata_header* navdata = (navdata_header *)data;
	if(navdata->magic != NAVDATA_HEADER)
	{
		printf("wrong navdata header");
		return;
	}

	int pos = sizeof(navdata_header);
	while(pos <= size)
	{
		navdata_option_t* navoption = (navdata_option_t*)(data+pos);

		if(navoption->tag == option_cks)
		{
			break;
		}
		else if(navoption->tag == option_demo)
		{
			navdata_demo_t* navdemo = (navdata_demo_t*)navoption;
		}
		else if(navoption->tag == option_vision_detect)
		{
			vision_detect* visdetect = (vision_detect*)navoption;
		}

		pos += navoption->size;
	}

	//use variable (of thread) to signal the availability to other thread
	m_available = 1;
}

// TODO: i'm not sure of what we have to do here
// Normally we don't need a spoofer (but it is ready to use, just in case), just open a udp socket on localhost port 5554
// I don't really understand what Alexandre do in this function
// !!!! I modified the prototype of initialize_socket() 
void initNavdata ()
{   
    // Navdata socket initialization
    navdata_socket = initialize_socket(DEST_IP_NAV, DEST_PORT_NAV);
    
    if (navdata_socket.socket_id < 0)
    {
        printf("[FAILED] Socket initialization failed\n");
        exit(1);
    }

    // pcap thread initialization
    pthread_t setup_pcap_thread;
    
    if (pthread_create(&setup_pcap_thread, NULL, setup_pcap, NULL)) 
    {
      perror("pthread_create");
      exit(1);
    }
    
    // Sending first message
    char data[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char message[512];


	if(send_message(data, navdata_socket) != 0)
	{
		printf("[FAILED] Send packet failed\n");
		// TODO: do something
	}
	
    //wait to boostrap bit
    int i;
    for( i = 0 ;;)
    {
      while(!m_available)
        ;
      Navdata nav = set_p_available_false();

      printf("waiting for bootstrap %d\n",i);

      if(nav.header.ardrone_state & navdata_bootstrap)
        break;

      if(++i > TIME_OUT)
        exit(1);
    }

    printf("in bootstrap mode");

    //!!!TODO (et modif de toute la partie at-command et send_message : mise en place mutex pour num sequence)
    set_config(message, "general:navdata_demo", "TRUE");

    printf("navdata demo set");

    //waiting ack
    for( i = 0 ;;)
    {
      while(!m_available)
        ;
      Navdata nav = set_p_available_false();

      printf("waiting for ack %d\n",i);

      if(nav.header.ardrone_state & command_ack)
        break;

      if(++i > TIME_OUT)
        exit(1);
    }

    //!!!!!!TODO idem as set_config
    set_ackcontrol(message);

    printf("ack sent");
}

Navdata set_p_available_false ()
{
  m_available = 0;
  return m_navdata;
}
