#ifndef RUDP_H
#define RUDP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORTNO 7000
#define MAXBUFFER 255

typedef struct rudppacket {
int hmm;
} RPKT, *PRPKT;

typedef struct connection {
    char ip[16];
    int16_t port;
    int32_t rxSequence;
    int32_t txSequence;
    int sock;
    struct sockaddr_in servaddr;
} CONNECT, *PCONNECT;

int readFromSocket(int socketFD);
void error(const char *msg);
int rudpServer(int16_t port);
int rudpClient(char *ip, int16_t port);
PCONNECT startConnection(char *ip, int16_t port);

#endif
