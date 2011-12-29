#ifndef CLIENTS_H
#define CLIENTS_H

#include "connection.h"
#include "uthash.h"

//extern PCONNECT clients;  //don't believe i need global access to this anymore

void clientsAdd(PCONNECT client);
PCONNECT clientsFind(int sock);
void clientsDelete(PCONNECT connection);
void clientsDeleteAll();
void clientsPrint();
int clientsSort(PCONNECT a, PCONNECT b);
void clientsSortById();

#endif
