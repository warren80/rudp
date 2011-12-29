#include "rudp.h"

int rudpServer(int16_t port) {
    crcInit();
    printf("rudpServer:\n");
    PCONNECT connection = startConnection(0, port);
    printf("Server started\n");
    rxPacket(connection);
    return 0;
}

int rudpClient(char *ip, int16_t port) {
    crcInit();
    PCONNECT connection = startConnection(ip, port);
    PNODE head = createlist();
    txPacket(connection, head);
    return 0;
}
