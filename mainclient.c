#include "rudp.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#define SRV_IP "127.0.0.1"
int main() {
    char str[10] = SRV_IP;
    rudpClient(str, 7000);
    return 0;
}
