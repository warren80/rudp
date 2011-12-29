#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node {
   int  seq;
   char * data;
   struct node * next;
};
typedef struct node NODE, *PNODE;

PNODE initnode(char * data, int seq);
void deletenode(PNODE prev, PNODE ptr);
void deletelist(PNODE ptr);
PNODE deleteuntil(PNODE ptr, int seq);
void add(PNODE end, PNODE ptr);
#endif
