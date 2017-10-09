/* C file stack.c
 * Author  Abhiram Shibu - https://github.com/ABHIRAMSHIBU
 * Copyright (c) 2017 Team Destroyer */
#include<malloc.h>
#include<stdio.h>
#include "stacklist.h"
#include "stackarray.h"
#include<stdlib.h>

/* Push to linked list */
void LinkPush(int k,int *s,int *top,listPointer **head){
	printf("Pushing to liked list from array\n");
	int temp;
	for(int i=0;i<k;i++){
		temp=POP(s,top);
        	printf("LinkPush status:%d\n",temp);        
	        LPUSH(head,temp);
	}
}

/* Pop from linked list */
void LinkPop(int k,int *s,int *top,listPointer **head){
	printf("Poping from liked list to array\n");
	int temp;
	for(int i=0;i<k;i++){
            temp=LPOP(head);
            printf("LinkPop status:%d\n",temp);
            PUSH(s,top,temp);
	}
}

/* Main menu for program */
void menu(int *s,int *top,listPointer **head){
   char ch='y';
   while(ch=='Y' || ch=='y'){
       int choice=-1;
       int k=0;
       printf("Enter the operation you want to perform:\n1.LinkPush\n2.LinkPop\n3.Display stack(list)\n4.Display stack(array)\nEnter an option :");
       scanf("%d",&choice);
       if(choice==1){
		printf("Enter the no of elements to pop (k):");
		scanf("%d",&k);
		LinkPush(k,s,top,head);
	}
        if(choice==2){
                printf("Enter the no of elements to pop (k):");
                scanf("%d",&k); 
                LinkPop(k,s,top,head);
        }
	if(choice==3){
		printAll(head);
	}
	if(choice==4){
		displayStack(s,*top);
	}
	printf("Do you want to continue [y/n]:");
	getchar();
    scanf("%c",&ch);
    system("clear");
   }
}

int main()
{
    listPointer * head=NULL;                                                                            //Linked list stack
    int nl,c;                                                                                                   //nl elements to push to Linked list stack
    int s[100],top=-1,na;                                                                                //Array stack, na elements to push to Array stack
    printf("Enter the no of elements to push into stack using linked list:");
    scanf("%d",&nl);                                                                                      //Input elements to push to linked list
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
