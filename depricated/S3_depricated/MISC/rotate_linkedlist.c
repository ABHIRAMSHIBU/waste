/* C source rotate_linkedlist
 * Author  Abhiram Shibu - https://github.com/ABHIRAMSHIBU
 * Copyright (c) 2017 Team Destroyer(TD) */
#include<stdio.h>
#include "linkedlist.h"
int rotate(listPointer ** head,int n){
    listPointer * nodeCurrent= * head, * nodeTemp, * nodeTemp2;
    if(n==0)
        return(-2);
    else if(n<0)
        return(-1);
    for(int i=0;i<n-1;i++){
        if(nodeCurrent->link == NULL || nodeCurrent == NULL)
            return(-1);
        nodeCurrent=nodeCurrent->link;
    }
    if(nodeCurrent->link==NULL)
        return(-2);
    nodeTemp=nodeCurrent->link;
    nodeCurrent->link=NULL;
    nodeTemp2=nodeTemp;
    while(nodeTemp->link!=NULL)
        nodeTemp=nodeTemp->link;
    nodeTemp->link=* head;
    * head = nodeTemp2;
    return(n);
}

/* Demo using rotate , handle error codes */
int main(){
    int n;
    listPointer * head;
    bulkInsert(&head);
    printf("Before rotate \n");
    printAll(&head);
    printf("Enter where you want to rotate:");
    scanf("%d",&n);
    n=rotate(&head,n);
    if(n==-1)
        printf("Rotation failed!, may be invaid n\n");
    else if(n==-2)
        printf("Rotation not needed or error occured!");
    else
        printAll(&head);
}
