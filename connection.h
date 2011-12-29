#ifndef CONNECTION_H
#define CONNECTION_H


#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "crc.h"

#define PORTNO 7000
#define MAXBUFFER 255

typedef struct {
    char ip[16];
    int16_t port;
    int32_t rxSequence;
    int32_t txSequence;
    int sock;
    struct sockaddr_in servaddr;
    struct sockaddr_in addrOut;
    char status;
    struct node *head;
} CONNECT, *PCONNECT;

void error(const char *msg);
PCONNECT startConnection(char *ip, int16_t port);
int rxPacket(PCONNECT connection);
int txPacket(PCONNECT connection, PNODE head);


#endif
