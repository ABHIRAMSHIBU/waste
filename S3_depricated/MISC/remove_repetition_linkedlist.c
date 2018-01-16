/* C source  remove_repetition_linkedlist
 * Author  Abhiram Shibu - https://github.com/ABHIRAMSHIBU
 * Copyright (c) 2017 Team Destroyer */
#include<stdio.h>
#include "linkedlist.h"

/* Removes all repetion by altering provided SLL */
void removeRepetion(listPointer ** head)
{
    listPointer * nodeMain, * nodeCurrent, * temp;
    nodeMain=* head;
    nodeCurrent= nodeMain;
    while(nodeMain!=NULL){
        while(nodeCurrent->link!=NULL){
            if(nodeCurrent->link->data==nodeMain->data){
                
                /* Delete node */
                temp=nodeCurrent->link;
                nodeCurrent->link=nodeCurrent->link->link;
                free(temp);
                            
            }
            nodeCurrent=nodeCurrent->link;
        }
        nodeMain=nodeMain->link;
        nodeCurrent=nodeMain;
    }
}
/* Demo of functionality of removeRepetion aka killRepetion */
int main(){
    listPointer * head;
    bulkInsert(&head);
    printf("Before removeRepetion\n");
    printAll(&head);
    printf("After removeRepetion\n");
    removeRepetion(&head);
    printAll(&head);
}
