#include "rudp.h"
#include "crc.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

int main() {
    printf("Main:\n");
    rudpServer(7000);
    return 0;
}
