#include<malloc.h>
#include "linkedlist.h"
void LPUSH(listPointer ** head,int data){
    insert_front(head,data);
}
int LPOP(listPointer ** head){
    if(*head==NULL)
    {
        return -1;
    }
    return delete_font(head);
}

