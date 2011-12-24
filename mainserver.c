#include "rudp.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

int main() {
    rudpServer(PORTNO);
    return 0;
}
