/* Copyright (c) 2017 Abhiram Shibu
 * Copyright (c) 2017 Team Destroyer
 */
#include<malloc.h>
#include "linkedlist.h"
void push(listPointer ** head,int data){
    insertFront(head,data);
}
int pop(listPointer ** head){
    if(*head==NULL)
    {
        return -1;
    }
    return deleteFront(head);
}
