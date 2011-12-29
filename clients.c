#include "clients.h"

PCONNECT clients = NULL;

void clientsAdd(PCONNECT client) {
    HASH_ADD_INT(clients, sock, client);
}

PCONNECT clientsFind(int sock) {
    PCONNECT connection;

    HASH_FIND_INT(clients, &sock, connection);  /* s: output pointer */
    return connection;
}

void clientsDelete(PCONNECT connection) {
    HASH_DEL(clients, connection);  /* user: pointer to deletee */
    free(connection);
}

void clientsDeleteAll() {
  PCONNECT current_client, tmp;

  HASH_ITER(hh, clients, current_client, tmp) {
    HASH_DEL(clients,current_client);  /* delete it (clients advances to next) */
    free(current_client);            /* free it */
  }
}

void clientsPrint() {
    PCONNECT s;
    int i = 0;
    for(s=clients; s != NULL; s=s->hh.next) {
        //print socketId, addr in and addr out maybe more.
        //printf("user id %d: name %s\n", s->id, s->name);
        printf("client num: %d\n",i++);
    }
}

int clientsSort(PCONNECT a, PCONNECT b) {
    return (a->sock - b->sock);
}

void clientsSortById() {
    HASH_SORT(clients, clientsSort);
}
