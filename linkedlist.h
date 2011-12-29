#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node {
   int  seq;
   char * data;
   struct node * next;
};
typedef struct node NODE, *PNODE;

PNODE nodeInit(char * data, int seq);
void nodeDelete(PNODE prev, PNODE ptr);
void listDelete(PNODE ptr);
PNODE listDeleteUntil(PNODE ptr, int seq);
void listAdd(PNODE end, PNODE ptr);
#endif
