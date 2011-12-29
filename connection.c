#include "connection.h"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

PCONNECT startConnection(char *ip, int16_t port) {
    printf("startConnection: malloc\n");
    PCONNECT connection = malloc(sizeof(CONNECT));
    if (connection == 0) {
        error("ERROR on allocating connection");
    }
    connection->port = port;
    bzero(&connection->servaddr,sizeof(connection->servaddr));
    connection->servaddr.sin_family = AF_INET;
    if (ip == 0) {
        connection->servaddr.sin_addr.s_addr= INADDR_ANY;
        connection->servaddr.sin_port=htons(connection->port);
        printf("Recieve set to %s:%d\n", inet_ntoa(connection->servaddr.sin_addr), ntohs(connection->servaddr.sin_port));
    } else {
        printf ("DestIP: %s\n", ip);
        memcpy(connection->ip, ip, sizeof ip);
        //connection->servaddr.sin_addr.s_addr=inet_addr(connection->ip);
        if (inet_aton(ip, &connection->servaddr.sin_addr)==0) {
            printf("inet_aton(): failed\n");
        }
        connection->servaddr.sin_port=htons(connection->port);
        printf("Destination set to %s:%d\n", inet_ntoa(connection->servaddr.sin_addr), ntohs(connection->servaddr.sin_port));
    }

    //connection->servaddr.sin_port=htons(connection->port);
    printf("startConnection: socket\n");
    int i = 1;
    connection->sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (setsockopt(connection->sock, SOL_SOCKET, SO_REUSEADDR, &i, sizeof i) < 0) {
              error("setsockopt(SO_REUSEADDR) failed");
    }
    if (connection->sock == 0) {
        error("ERROR on creating socket");
    }
    if (ip==0) {
        if (bind(connection->sock, (struct sockaddr *) &connection->servaddr,
                    sizeof connection->servaddr) != 0) {
                error("ERROR on binding");
        }
    }
    printf("startConnection: bind\n");
    //this will be needed but testing on one computer so not listening on client side yet
    /*if (bind(connection->sock, (struct sockaddr *) &connection->servaddr,
            sizeof connection->servaddr) < 0) {
        error("ERROR on binding");
    }*/
    printf("Socket: %d\n",connection->sock);
    return connection;
}

int txPacket(PCONNECT connection, PNODE head) {
    int i = 0;
    int result;
    socklen_t addrlen = sizeof(connection->servaddr);
    printf("Destination set to %s:%d\n", inet_ntoa(
               connection->servaddr.sin_addr), ntohs(connection->servaddr.sin_port));
    printf("Socket: %d\n",connection->sock);
    while (head != NULL) {
        ++i;
        result = sendto(connection->sock,head->data,55555,0,
            (const struct sockaddr *) &connection->servaddr,addrlen);
        head = head->next;
        if (result != 55555) {
            printf("Result: %d\n", result);
            printf("Transmited packet to %s:%d\nPacket Number: %d\n",
                   inet_ntoa(connection->servaddr.sin_addr), ntohs(connection->servaddr.sin_port), i);
            exit(1);
        }
        printf("txPacket: %d\n", i);
    }
    printf("%d\n",i);
    return i;
}

int rxPacket(PCONNECT connection) {
    socklen_t addrlen;// = sizeof(connection->servaddr);
    int i = 0;
    char buf[55555];
    int length;
     struct sockaddr_in si_other;
    printf("rxPacket: waiting to recieve\n");
    for (i = 0; i != 3; ++i) {
        //recvfrom(connection->sock,buf,55555,0,0,0);
                 //(struct sockaddr *)&connection->servaddr,&addrlen);
        //length = read(connection->sock,buf,55555);
        //printf("rxPacket: length %d, %d\n ", length, i);
        if ((length = recvfrom(connection->sock, buf, 55555, 0, (struct sockaddr *) &si_other, &addrlen))==-1) {
            error("recvfrom = -1\n");
        }
        printf("Received packet from %s:%d\nPacket Number: %d\n",
               inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), i);
    }
    printf("done\n");
    close(connection->sock);
    return i;
}


PNODE createlist() {
    PNODE head = nodeInit(malloc(1),0);
    PNODE temp = head, pnode;
    int i;
    for(i = 1; i != 3; ++i) {
        char * data = (char *) calloc(3,55555);
        pnode = nodeInit(data,i);
        listAdd(temp, pnode);
        temp = pnode;
        //printf("createlist: %d\n", i);
    }
    return head;
}

int createChecksum(void * buf) {
    return 0;
}
int verifyChecksum(void * buf) {
    return 0;
}
