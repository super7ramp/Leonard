/*
 * test_pcap.c
 * Install libpcap-dev before trying to compile
 * Compile with: gcc -Wall -lpcap test_pcap.c -o test_pcap
 * See http://www.tcpdump.org/pcap.html and https://github.com/Rajesh-Sec-Project/simon/blob/master/drone/src/navdatacontroller.cpp
 */

#include <stdio.h>
#include <pcap.h>

#define IFACE   "lo" // loopback interface

void action_on_packet_reception(u_char *args, const struct pcap_pkthdr *header, const u_char *packet)
{
    // This a callback function
    // TODO
}

int main()
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

    // Make a loop; -1 means sniffing until an error occurs
    //pcap_loop(handle, -1, action_on_packet_reception, NULL);

    return 0;
}
