#ifndef RUDP_H
#define RUDP_H

#include "connection.h"
#include "crc.h"

int rudpServer(int16_t port);
int rudpClient(char *ip, int16_t port);


#endif
