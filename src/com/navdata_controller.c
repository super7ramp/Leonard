#include "navdata_controller.h"

/*----------------------------------------------------------------------------*/

/* Private */

pthread_mutex_t state_mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t navdata_mtx = PTHREAD_MUTEX_INITIALIZER;

typedef enum _controller_state_t
{
    OFF = 0,
    WAITING_BOOTSTRAP,
    WAITING_ACK,
    WAITING_ACK_CLEARED,
    READY
} controller_state_t;

void action_on_packet_reception(u_char *args, const struct pcap_pkthdr *header, const u_char *packet);
void *setup_pcap();
void decode(const u_char *data, int size);
Navdata set_p_available_false();

int m_available = 0;
controller_state_t controller_state = OFF;
Navdata m_navdata; // TODO: initialize with default values

/*----------------------------------------------------------------------------*/

/** @brief Callback function called when a packet is received */
void action_on_packet_reception(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
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
    int header_size = sizeof(struct ethhdr) + iphdrlen + sizeof(struct udphdr);
    const unsigned char* data = packet + header_size;

    decode(data, size - header_size);
}

/** @param Blocking function that launch the packet capture */
void *setup_pcap ()
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // Open device
    handle = pcap_open_live(IFACE, 65536, 1, 0, errbuf);
    if (handle == NULL)
    {
        fprintf(stderr, "[%s:%d] Couldn't open device %s: %s\n", __FILE__, __LINE__, IFACE, errbuf);
        return 0;
    }

    // This is blocking
    pcap_loop(handle, -1, &action_on_packet_reception, NULL);

    printf("pcap session finished\n");

    return NULL;
}

/** @brief Decode a received packet
  * @param data The data
  * @param size The size of the data
  */
void decode(const u_char *data, int size)
{
    pthread_mutex_lock(&navdata_mtx);
    m_navdata.header = *( (navdata_header *) data);

	if(m_navdata.header.magic != NAVDATA_HEADER)
	{
		//printf("Wrong navdata header: %x != %x\n", m_navdata.header.magic, NAVDATA_HEADER);
		pthread_mutex_unlock(&navdata_mtx);
		return;
	}

    // We go at the end of the data to explore the navdata options
	int pos = sizeof(navdata_header);
	while(pos <= size)
	{
		const navdata_option_t* navoption = (const navdata_option_t*)(data+pos);

		if(navoption->tag == option_cks)
		{
		    // "Checksum" tag
			break;
		}
		else if(navoption->tag == option_demo)
		{
		    // "Demo" navdata, see the navdata_demo_t structure
		    m_navdata.demo = *( (navdata_demo_t*) navoption );
		    //printf("demo\n");
		}
		else if(navoption->tag == option_magneto)
		{
		    // "Magneto" navdata, see navdata_magneto_t structure
		    m_navdata.magneto = *( (navdata_magneto_t*) navoption );
		}
		else
		{
		    // Non-used/Undefined navdata type 
		}

		pos += navoption->size;
	}

    pthread_mutex_unlock(&navdata_mtx);
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
		fprintf(stderr, "[FAILED] Spoof failed\n");
		// TODO: do something
	}

    // OFF -> WAITING_BOOTSTRAP
    pthread_mutex_lock(&state_mtx);
    controller_state = WAITING_BOOTSTRAP;
    pthread_mutex_unlock(&state_mtx);
    
    // Wait for the boostrap bit
    int i;
    for( i = 0 ;;)
    {
        while(!m_available)
        ;
        Navdata nav = set_p_available_false();

        //printf("waiting for bootstrap %d\n",i);

        if(nav.header.ardrone_state & navdata_bootstrap)
            break;

        if(++i > TIME_OUT)
        {
            printf("Timeout, bootstrap bit not received, exiting\n");
            exit(1);
        }
    }

    // Controller state: WAITING_BOOTSTRAP -> WAITING_ACK
    pthread_mutex_lock(&state_mtx);
    controller_state = WAITING_ACK;
    pthread_mutex_unlock(&state_mtx);

    // If we are here, we have reached the bootstrap mode and we need to send
    // the config message
    //printf("Now in bootstrap mode\n");
    printf("set_config message: %s\n", set_config(message, "general:navdata_demo", "TRUE"));
    //printf("Navdata demo set\n");

    // Now waiting for the ack of the config message
    for( i = 0 ;;)
    {
        while(!m_available)
        ;
        Navdata nav = set_p_available_false();

        //printf("waiting for ack %d\n",i);
        //printf("nav.header.ardrone_state & command_ack = %d\n", nav.header.ardrone_state & command_ack);
        //printf("nav.header.ardrone_state = %x\n", nav.header.ardrone_state);
        //printf("navdata_m.header.ardrone_state = %x\n", m_navdata.header.ardrone_state);

        if(nav.header.ardrone_state & command_ack)
            break;

        if(++i > TIME_OUT)
        {
            printf("Timeout, no ack for config message, exiting\n");
            exit(1);
        }
    }
    
    // Controller state: WAITING_BOOTSTRAP -> WAITING_ACK
    pthread_mutex_lock(&state_mtx);
    controller_state = WAITING_ACK_CLEARED;
    pthread_mutex_unlock(&state_mtx);
    
    // If we are here, we are almost done
    // We need to send a ack (of the ack that the drone has just sent to us)
    //printf("Ack received, sending ack\n");
    printf("ackcontrol message = %s\n", set_ackcontrol(message));
    //printf("Ack sent\n");
    
    for( i = 0 ;;)
    {
        while(!m_available)
        ;
        Navdata nav = set_p_available_false();

        //printf("waiting for cleared ack %d\n",i);
        //printf("nav.header.ardrone_state & command_ack = %d\n", nav.header.ardrone_state & command_ack);
        //printf("nav.header.ardrone_state = %x\n", nav.header.ardrone_state);
        //printf("navdata_m.header.ardrone_state = %x\n", m_navdata.header.ardrone_state);

        if(!(nav.header.ardrone_state & command_ack))
        break;

        if(++i > TIME_OUT)
        {
            printf("Timeout, no message with cleared ack received, exiting\n");
            exit(1);
        }
    }
    
    // Wow, that's a success
    // Just configuring options now, especially for magneto data
    // Note: not sure if it is necessary, option_demo should be the default and
    // include the option_magneto
    //printf("Cleared ack received\n");
    int options = (0x01 << option_demo) | (0x01 << option_magneto);
    char optionsString[32];
    sprintf(optionsString, "%d", options);
    printf("set_config message: %s\n", set_config(message, "general:navdata_options", optionsString));

    //printf("Navdata initted!\n");
    
    // Controller state: WAITING_ACK_CLEARED -> READY
    pthread_mutex_lock(&state_mtx);
    controller_state = READY;
    pthread_mutex_unlock(&state_mtx);
    
}

Navdata set_p_available_false ()
{
    m_available = 0;
    return m_navdata;
}

Navdata getNavdata()
{
    if(!isControllerReady())
    {
        fprintf(stderr, "[%s:%d] Error: Navdata controller is not ready!\n", __FILE__, __LINE__);
        exit(1);
    }
    
    pthread_mutex_lock(&navdata_mtx);
    Navdata r = m_navdata;
    pthread_mutex_unlock(&navdata_mtx);
    
    return r;
}

int isControllerReady()
{
    pthread_mutex_lock(&state_mtx);
    int r = (controller_state == READY);
    pthread_mutex_unlock(&state_mtx);
    return r;
}
