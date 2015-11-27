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
#include "spoof_udp.h"

// FIXME do a clean mutex to access m_navdata
int m_available = 0;
Navdata m_navdata;

//Fonction qui intercepte les packets et appelle la fonction M_decode()
void action_on_packet_reception(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{

    //printf("Received packet!\n");
    
    // This a callback function
   int size = header->len;

   struct iphdr* iph = (struct iphdr*)(packet + sizeof(struct ethhdr));
   unsigned short iphdrlen = iph->ihl * 4;

   // Filter protocol
   if(iph->protocol != 17)
   {
       //printf("iph->protocol (%d) != 17\n", iph->protocol);
       return;
   }

   // Get the destination IP address and filter
   struct sockaddr_in dest;
   memset(&dest, 0, sizeof(dest));
   dest.sin_addr.s_addr = iph->daddr;
   if(dest.sin_addr.s_addr != inet_addr(FAKE_ADDR_SRC))
   {
       //printf("dest.sin_addr.s_addr (%d) != inet_addr(FAKE_ADDR_SRC) (%d)\n", dest.sin_addr.s_addr,  inet_addr(FAKE_ADDR_SRC));
       return;
   }

   // Get the UDP header
   struct udphdr* udph = (struct udphdr*)(packet + iphdrlen + sizeof(struct ethhdr));

   // Filter out ports
   if(ntohs(udph->dest) != PORT_FAKE_ADDR)
   {
       //printf("ntohs(udph->dest) (%d) != DEST_PORT_NAV\n", ntohs(udph->dest));
       return;
   }
    
   // Get the data from the sniffed packet
   int header_size = sizeof(struct ethhdr) + iphdrlen + sizeof(struct udphdr); // + 4; //@FIXME: why the +4 ???
   const unsigned char* data = packet + header_size;

    //printf("it's a valid packet\n");
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

  printf("pcap session finished\n");
  return 0;

}

//Analyse les packets 
void M_decode(const u_char *data, int size)
{
    //printf("Entering M_decode\n");

/*
    FILE* file = NULL;

    file = fopen("test.txt", "a");

    if (file != NULL)
    {
        // On peut lire et écrire dans le fichier
        unsigned int i;
        for(i = 0; i < sizeof(m_navdata.header); ++i)
        {
            fprintf(file, "%d: %x\n", i, (int) data[i]);
        }
        
        fclose(file);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }
*/

    m_navdata.header = *( (navdata_header *) data);
	
	if(m_navdata.header.magic != NAVDATA_HEADER)
	{
		printf("wrong navdata header: %x != %x\n", m_navdata.header.magic, NAVDATA_HEADER);
		return;
	}
	
	if(m_navdata.header.ardrone_state & navdata_bootstrap)
	{
	    printf("boostrap!!!\n");
	}

    //printf("Right navdata header!!!!\n");

    // We go at the end of the data to explore the navdata options
	int pos = sizeof(data);
	while(pos <= size)
	{
		const navdata_option_t* navoption = (const navdata_option_t*)(data+pos);

		if(navoption->tag == option_cks)
		{
			break;
		}
		else if(navoption->tag == option_demo)
		{
		    m_navdata.demo = *( (navdata_demo_t*) navoption );
		}
		else if(navoption->tag == option_vision_detect)
		{
		    m_navdata.vision = *( (vision_detect_t*) navoption );
		}

		pos += navoption->size;
		//printf("pos = %d\t size of navoption = %d\n", pos, navoption->size);
	}

	//use variable (of thread) to signal the availability to other thread
	//printf("setting m_available to 1\n");
	m_available = 1;
}

void initNavdata ()
{   
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


	if(spoof_udp(data, sizeof(data)))
	{
		printf("[FAILED] Spoof failed\n");
		// TODO: do something
	}

    // Wait for boostrap bit
    int i;
    for( i = 0 ;;)
    {
      while(!m_available)
        ;
      Navdata nav = set_p_available_false();

      printf("waiting for bootstrap %d\n",i);

      if(nav.header.ardrone_state & navdata_bootstrap)
        break;

      //printf("boucle for\n");

      if(++i > TIME_OUT)
      {
        printf("Timeout, bootstrap bit not received, exiting\n");
        exit(1);
      }
    }

    // If we are here, we have reached bootstrap mode and we need to send
    // the config message
    printf("Now in bootstrap mode\n");
    printf("set_config message: %s\n", set_config(message, "general:navdata_demo", "TRUE"));
    printf("Navdata demo set\n");

    // Now waiting for the ack of the config message
    for( i = 0 ;;)
    {
      while(!m_available)
        ;
      Navdata nav = set_p_available_false();

      printf("waiting for ack %d\n",i);
      printf("nav.header.ardrone_state & command_ack = %d\n", nav.header.ardrone_state & command_ack);
      printf("nav.header.ardrone_state = %x\n", nav.header.ardrone_state);
      printf("navdata_m.header.ardrone_state = %x\n", m_navdata.header.ardrone_state);

      if(nav.header.ardrone_state & command_ack)
        break;

      if(++i > TIME_OUT)
      {
        printf("Timeout, no ack for config message, exiting\n");
        exit(1);
      }
    }
    
    // If we are here, we are almost done
    // We need to send a ack (of the ack that the drone has just sent to us)
    printf("Ack received, sending ack\n");
    printf("ackcontrol message = %s\n", set_ackcontrol(message));
    printf("Ack sent\n");
    
    for( i = 0 ;;)
    {
      while(!m_available)
        ;
      Navdata nav = set_p_available_false();

      printf("waiting for cleared ack %d\n",i);
      printf("nav.header.ardrone_state & command_ack = %d\n", nav.header.ardrone_state & command_ack);
      printf("nav.header.ardrone_state = %x\n", nav.header.ardrone_state);
      printf("navdata_m.header.ardrone_state = %x\n", m_navdata.header.ardrone_state);

      if(!(nav.header.ardrone_state & command_ack))
        break;

      if(++i > TIME_OUT)
      {
        printf("Timeout, no message with cleared ack received, exiting\n");
        exit(1);
      }
    }
    
    // Wow, that's a success
    // Just configuring options now
    printf("Cleared ack received\n");
    int options = (0x01 << option_demo);// | (0x01 << option_vision_detect);
    char optionsString[32];
    sprintf(optionsString, "%d", options);
    printf("set_config message: %s\n", set_config(message, "general:navdata_options", optionsString));

    printf("Navdata initted!\n");
}

Navdata set_p_available_false ()
{
    m_available = 0;
    return m_navdata;
}

Navdata getNavdata()
{
    return m_navdata;
}
