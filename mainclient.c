#include "rudp.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

int main() {
    char * str = "127.0.0.1";
    rudpClient(str, PORTNO);
    return 0;
}
