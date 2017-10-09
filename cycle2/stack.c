/* Header file linkedlist
 * Author  Abhiram Shibu - https://github.com/ABHIRAMSHIBU
 * Copyright (c) 2017 Team Destroyer */
#include<malloc.h>
#include<stdio.h>
#include "stacklist.h"
#include "stackarray.h"
#include<stdlib.h>
void LinkPUSH(int k,int *s,int *top,listPointer **head){
	printf("LINKPUSHING\n");
	int temp;
	for(int i=0;i<k;i++){
		temp=POP(s,top);
        	printf("Linkpushed=%d\n",temp);        
	        LPUSH(head,temp);
	}
}

void LinkPOP(int k,int *s,int *top,listPointer **head){
	printf("LINKPOPPING\n");
	int temp;
	for(int i=0;i<k;i++){
            temp=LPOP(head);
            printf("Linkpopped=%d\n",temp);
            PUSH(s,top,temp);
	}
}

void menu(int *s,int *top,listPointer **head){
   char ch='y';
   while(ch=='Y' || ch=='y'){
       int choice=-1;
       int k=0;
       printf("Enter the operation you want to perform:\n1.LINKPUSH\n2.LINKPOP\n3.DISPLAY LIST\n4.DISPLAY ARRAY\n");
       scanf("%d",&choice);
       if(choice==1){
		printf("Enter the no of elements to pop (k):");
		scanf("%d",&k);
		LinkPUSH(k,s,top,head);
	}
        if(choice==2){
                printf("Enter the no of elements to pop (k):");
                scanf("%d",&k); 
                LinkPOP(k,s,top,head);
        }
	if(choice==3){
		printAll(head);
	}
	if(choice==4){
		display_stack(s,*top);
	}
	printf("Do you want to continue (y/n):\n");
	scanf("\n%c",&ch);
       system("clear");
   }
}

int main()
{
    listPointer * head=NULL;
    int nl,c;
    int s[100],top=-1,na;
    printf("Enter the no of elements to push into list->stack:");
    scanf("%d",&nl);
    for(int i=0;i<nl;i++){
        printf("Enter element %d :",i+1);
        scanf("%d",&c);
        LPUSH(&head,c);
    }
    printf("Enter the no of elements to push into array[stack]:");
    scanf("%d",&na);
    for(int i=0;i<na;i++){
        printf("Enter element %d :",i+1);
        scanf("%d",&c);
        PUSH(s,&top,c);
    }
  system("clear");
  menu(s,&top,&head);
   


}
