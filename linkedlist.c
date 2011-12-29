#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* this initialises a node, allocates memory for the node, and returns   */
/* a pointer to the new node. Must pass it the node details, seq          */
PNODE nodeInit(char * data, int seq) {
   PNODE ptr;
   ptr = (PNODE) calloc( 1, sizeof(NODE));
   if(ptr == NULL) {
       return 0;
   } else {
       ptr->seq = seq;
       ptr->data = data;
       ptr->next = NULL;
       return ptr;
   }
}

/* this adds a node to the end of the list. You must allocate a node and  */
/* then pass its address to this function                                 */
void listAdd(PNODE end, PNODE ptr) {
   end->next = ptr;
}

/* deletes the specified node pointed to by 'ptr' only to be used when
   deleting a node in middle of list.  To delete from start of list used
   deleteuntil */
void nodeDelete(PNODE prev, PNODE ptr) {
    if (ptr->next == NULL) {
        prev->next = NULL;
    } else {
        prev->next = ptr->next;
    }
    free(ptr->data);
    free(ptr);
}

/* this deletes all nodes from the place specified by ptr                 */
/* if you pass it head, it will free up entire list                       */
void listDelete(PNODE ptr) {
    PNODE temp;
    if (ptr == NULL) {
        return;
    }
    do {
        temp = ptr->next;
        free(ptr->data);
        free(ptr);
        ptr = temp;
    } while (ptr != NULL);
}

PNODE listDeleteUntil(PNODE ptr, int seq) {
    PNODE temp;
    //check for wrapping
    do {
        temp = ptr->next;
        free(ptr->data);
        free(ptr);
        ptr = temp;
    } while (ptr != NULL && ptr->seq <= seq);
    return ptr;
}
