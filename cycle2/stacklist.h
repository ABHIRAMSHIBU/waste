#include<malloc.h>
#include "linkedlist.h"
void LPUSH(listPointer ** head,int data){
    insertFront(head,data);
}
int LPOP(listPointer ** head){
    if(*head==NULL)
    {
        return -1;
    }
    return deleteFront(head);
}

