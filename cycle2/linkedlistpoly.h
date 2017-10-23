/* Author Abhiram Shibu
 * Copyright 2017
 * Depend : linkedlistpoly.h, GCC(Tested on ArchLinux v7) */
#include<malloc.h>
typedef struct listNode{
	int cfnt;                 
    int expt;
	struct listNode *link;
}listPointer;

void insert(listPointer ** list, int cfnt,int expt){
	listPointer * temp;
	temp=malloc(sizeof(listPointer));
	temp->link=NULL;
	(*list)=temp;
	(*list)->cfnt=cfnt;
    (*list)->expt=expt;
}

void printAll(listPointer ** head){
	listPointer * temp;
	temp=*head;
	while(1)
	{
		if(temp->link==NULL)
		{
			printf("Coefficient :%d Exponent:%d\n",temp->cfnt,temp->expt);
			break;
		}
		else
		{
			printf("Coefficient :%d Exponent:%d\n",temp->cfnt,temp->expt);
			temp=temp->link;
		}
	}

}
/*
void bulkInsert(listPointer ** list){
	listPointer * temp;
	listPointer * head;
	int n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	head=malloc(sizeof(listPointer));
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
		temp=temp->link;
		}
		printf("Success!\n");
	}
	*list=head;
}

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
*/
