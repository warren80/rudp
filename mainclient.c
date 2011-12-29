#include "rudp.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#define SRV_IP "127.0.0.1"
#include "clients.h"


/*
void addToHash();
void hashAdd(PCONNECT map. PCONNECT con) {
    HASH_ADD_INT(map, key,one);

}

int main() {
    //char str[10] = SRV_IP;
    PHT map = NULL;

    one->key = 1;

    HASH_ADD_INT(map,key,one);
    //rudpClient(str, 7000);
    return 0;

}
*/


int main() {
    int i;
    PCONNECT s;
    for (i = 0; i != 1000; ++i) {
        s = malloc(sizeof(CONNECT));
        s->sock = i;
        clientsAdd(s);
    }
    clientsPrint();


    return 0;
}
