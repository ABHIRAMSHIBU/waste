/* Header file linkedlistcircular
 * Author  Abhiram Shibu - https://github.com/ABHIRAMSHIBU
 * Copyright (c) 2017 Team Destroyer */
#include <malloc.h>
#define True 1
#define False 0
/* Main node */
typedef struct listNode{
	int data;
	struct listNode *link;
}listPointer;

/* Try to insert a node  */
int insert_caution(listPointer ** list, int data){
	listPointer * temp;
	temp=malloc(sizeof(listPointer));
    if(temp==NULL){
        return -1;
    }
    temp->link=NULL;
    (*list)=temp;
    (*list)->data=data;
    return 0;
}

/* Dumps everyting from given node */
void printAll(listPointer ** head){
    listPointer * temp;
    temp=*head;
    while(1)
    {
        if(temp->link==(*head))
        {
            printf("Data :%d\n",temp->data);
            break;
        }
        else
            {
                printf("Data :%d\n",temp->data);
                temp=temp->link;
            }
    }
}
void printAllChar(listPointer ** head){
    listPointer * temp;
    temp=*head;
    while(1)
    {
        if(temp->link==(*head))
        {
            printf("Data :%c\n",temp->data);
            break;
        }
        else
        {
            printf("Data :%c\n",temp->data);
            temp=temp->link;
        }
    }
}
int insertEnd(listPointer ** head,int data){
    listPointer * temp = *head;
    if(*head==NULL){
        insert_caution(head,data);
        (*head)->link=(*head);
        return;
    }
    while(temp->link!=(*head)){
        temp=temp->link;
    }
    insert_caution(&(temp->link),data);
    temp->link->link=(*head);
}

int deleteEnd(listPointer ** head){
    if(* head==NULL){
        return -1;
    }
    int data;
    listPointer * temp = * head;
    listPointer * prev = NULL;
    while(temp->link!=*head){
        prev=temp;
        temp=temp->link;
    }
    if(prev==NULL){
        data=(*head)->data;
        free(* head);
        * head=NULL;
        return data;
    }
    else{
        data=temp->data;
        free(temp);
        prev->link=(*head);
        return data;
    }
}
void insertFront(listPointer ** head,int data){
    if(*head==NULL){
        insert_caution(head,data);
        (*head)->link=(*head);
        return;
    }
    listPointer * temp,* temp2;
    temp=malloc(sizeof(listPointer));
    temp2=*head;
    while(temp2->link!=(*head)){temp2=temp2->link;}
    temp->link=*head;
    temp->data=data;
    *head=temp;
    temp2->link=(*head);
}
int deleteFront(listPointer ** head){
    int data;
    listPointer * temp=(*head)->link;
    data=(*head)->data;
    free(*head);
    *head=temp;
    return data;
}
/* Inserts as a list with so many nodes */
int bulkInsert(listPointer ** list){
    listPointer * temp;
    listPointer * head;
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    head=malloc(sizeof(listPointer));
    if(head==NULL)
    return -1;
    temp=head;
    int key;
    for(int i=0;i<n;i++)
    {
        printf("Enter key %d :",i+1);
        scanf("%d",&key);
        temp->data=key;
        if(i<n-1)
            {
                temp->link=malloc(sizeof(listPointer));
                if(temp->link==NULL)
                return -1;
                temp=temp->link;
            }
            printf("Success!\n");
    }
    *list=head;
    return 0;
}

/* Delete repetition(delete repeating nodes) in a given list */
void killRepetion(listPointer ** head)
{
    listPointer * nodeMain, * nodeCurrent, * temp;
    nodeMain=* head;
    nodeCurrent= nodeMain;
    while(nodeMain!=NULL){
        while(nodeCurrent->link!=NULL){
            if(nodeCurrent->link->data==nodeMain->data){
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
