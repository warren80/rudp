#include "rudp.h"

int readFromSocket(int socketFD) {
    int n;
    char buffer[MAXBUFFER];
    bzero(buffer,MAXBUFFER);
    n = read(socketFD,buffer,MAXBUFFER);
    printf("Read amount %d\n", n);
    write(0,buffer,n);
    close(socketFD);
    return 0;
}

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int rudpServer(int16_t port) {
//  readFromSocket(sockfd);
    return 0; 
}

PCONNECT startConnection(char *ip, int16_t port) {
    PCONNECT connection = malloc(sizeof connection);
    if (connection == 0) {
	error("ERROR on allocating connection");
    }
    memcpy(connection->ip, ip, sizeof ip);
    connection->port = port;
    bzero(&connection->servaddr,sizeof(connection->servaddr));
    connection->servaddr.sin_family = AF_INET;
    if (ip == 0) {
        connection->servaddr.sin_addr.s_addr= INADDR_ANY
    } else {
        connection->servaddr.sin_addr.s_addr=inet_addr(connection->ip);
    }    
    connection->servaddr.sin_port=htons(connection->port);
    connection->sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (connection->sock == 0) {
	error("ERROR on creating socket");
    }
    if (bind(connection->sock, (struct sockaddr *) &connection->serv_addr, 
            sizeof serv_addr) < 0) {
        error("ERROR on binding");
    }
    return connection;
}

int createChecksum(void *) {
    return 0;
}
int verifyChecksum(void *) {
    return 0;
}

int txPacket() {
    return 0;
}

int rxPacket() {
    return 0;
}

int rudpClient(char *ip, int16_t port) {
    int n;
    //char sendline[1000];
    //char recvline[1000];
    
    PCONNECT connection = clientSocket(ip, port);
/*
    fgets(sendline, 10000,stdin);
    sendto(connection->sock,sendline,strlen(sendline),0,
	(struct sockaddr *)&servaddr,sizeof(servaddr));
    n=recvfrom(sockfd,recvline,10000,0,NULL,NULL);
    recvline[n]=0;
    fputs(recvline,stdout);
*/
    return 0;
}
