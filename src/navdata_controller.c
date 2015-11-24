#include <stdio.h>
#include "navdata_controller.h"

void action_on_packet_reception(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    // This a callback function
   int size = header->len;

   struct iphdr* iph = (iphdr*)(packet + sizeof(ethhdr));
   unsigned short iphdrlen = iph->ihl * 4;

   // Filter protocol
   if(iph->protocol != 17)
       return;

   // Get the destination IP address and filter
   sockaddr_in dest;
   memset(&dest, 0, sizeof(dest));
   dest.sin_addr.s_addr = iph->daddr;
   if(dest.sin_addr.s_addr != inet_addr(NAV_IP))
       return;

   // Get the UDP header
   udphdr* udph = (udphdr*)(packet + iphdrlen + sizeof(ethhdr));

   // Filter out ports
   if(ntohs(udph->dest) != NAV_PORT)
       return;

   // Get the data from the sniffed packet
   int header_size = sizeof(ethhdr) + iphdrlen + sizeof(udph) + 4; //@FIXME: why the +4 ???
   const unsigned char* data = packet + header_size;

   M_decode(data, size - header_size);
}

void setup_pcap ()
{
	char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    printf("Device: %s\n", IFACE);

    // Open device
    handle = pcap_open_live(IFACE, BUFSIZ, 1, 0, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "Couldn't open device %s: %s\n", IFACE, errbuf);
        return 2;
    }

    printf("pcap initialized\n");

    pcap_loop(handle, -1, &action_on_packet_reception, NULL);

    printf("pcap session finished");

}

void M_decode(const u_char *data, int size)
{
	navdata_t* navdata = (navdata_t *)data;
	if(navdata->magic != NAVDATA_HEADER)
	{
		printf("wrong navdata header");
		return;
	}

	int pos = sizeof(navdata_t);
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
	//p_available = true;
}

// TODO: i'm not sure of what we have to do here
// Normally we don't need a spoofer (but it is ready to use, just in case), just open a udp socket on localhost port 5554
// I don't really understand what Alexandre do in this function
// !!!! I modified the prototype of initialize_socket() 
void initNavdata ()
{
    char data[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //open new UDP socket for navdata
    if(initialize_socket(DEST_IP_NAV, DEST_PORT_NAV) != 0)
    {
    	printf("[FAILED] Socket initialization failed\n");
    }
    else
    {
    	if(send_message(data) != 0)
    	{
    		printf("[FAILED] Send packet failed\n");
    	}
    }
}