#include "linkedlist.h"
/* Insert into queue */
void enqueueFront(listPointer ** head,int data){
    insertFront(head,data);
}
void enqueueEnd(listPointer ** head,int data){
    insertEnd(head,data);
}
/* Delete from queue */
int dequeueFront(listPointer ** head){
    return deleteFront(head);
}
int dequeueEnd(listPointer ** head){
    return deleteEnd(head);
}