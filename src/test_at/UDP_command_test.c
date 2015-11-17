/*Lien du tuto d'où provient le code
http://www.upsilonaudio.com/ar-drone-envoyer-des-commandes-at-paquets-udp/
lien vers un listing des commandes AT
http://www.upsilonaudio.com/ar-drone-recapitulatif-des-commandes-at/
*/

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

#define BUFLEN 512
#define ADRESSEIP "127.0.0.1"
#define PORT 5556
#define MESSAGE1 "AT*REF=101,290718208\r"
#define MESSAGE2 "AT*REF=102,290717696\r"

void delai ( int delaiSecondes );
void err(char *s);

int main(int argc, char** argv)
{
    struct sockaddr_in serv_addr;
    int sockfd, slen=sizeof(serv_addr);
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
    {
        err("socket");
    }
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_aton(ADRESSEIP, &serv_addr.sin_addr)==0)
    {
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);
    }
    if (sendto(sockfd, MESSAGE1, BUFLEN, 0, (struct sockaddr*)&serv_addr, slen)==-1)
    {
        err("sendto()");
    }
	/*delai(5);
    if (sendto(sockfd, MESSAGE2, BUFLEN, 0, (struct sockaddr*)&serv_addr, slen)==-1)
    {
        err("sendto()");
    }*/
    close(sockfd);
    return 0;
}

void err(char *s)
{
    perror(s);
    exit(1);
}

void delai ( int delaiSecondes )
{
    while ( clock()/CLOCKS_PER_SEC < delaiSecondes)
    {
    }
}
