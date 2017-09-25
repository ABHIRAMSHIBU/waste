#include<stdio.h>
#include<malloc.h>
#include "linkedlist.h"

/* Removes all repetion by altering provided SLL */
void killRepetion(listPointer ** head)
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
int main(){
    listPointer * head;
    bulkInsert(&head);
    printf("Before killRepetion\n");
    printAll(&head);
    printf("After killRepetion\n");
    killRepetion(&head);
    printAll(&head);
}
