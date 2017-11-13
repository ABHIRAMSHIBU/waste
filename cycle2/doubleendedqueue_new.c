#include<stdio.h>
#include<stdlib.h>
#include "color.h"
typedef struct queue{
    int data;
    struct queue *next;
    struct queue *prev;
}queue;
void insertAtFront(queue **head, queue **tail, int data){
    queue *new_node=(queue*)malloc(sizeof(queue));
    new_node->data=data;
    if(*head==NULL){
        *tail=new_node;
        *head=new_node;
        new_node->next=NULL;
        new_node->prev=NULL;
        return;
    }
    new_node->next=*head;
    new_node->prev=NULL;
    (*head)->prev=new_node;
    (*head)=new_node;
}
void insertAtRear(queue **head,queue **tail, int data){
    queue *new_node=(queue*)malloc(sizeof(queue));
    new_node->data=data;
    new_node->next=NULL;
    if(*tail==NULL){
        *tail=new_node;
        *head=new_node;
        new_node->next=NULL;
        new_node->prev=NULL;
        return;
    }
    new_node->prev=*tail;
    (*tail)->next=new_node;
    (*tail)=new_node;
}
void deleteAtFront(queue **head){
    queue *temp=*head;
    *head=(*head)->next;
    (*head)->prev=NULL;
    free(temp);
}
void deleteAtRear(queue **tail){
    queue *temp=*tail;
    *tail=(*tail)->prev;
    (*tail)->next=NULL;
    free(temp);
}
void printlist(queue *head, queue *tail){
    printf("The queue is:");
    while(head!=NULL){
        printf(" %d ",head->data);
        head=head->next;
    }
    printf("\n");
    //while(tail!=NULL){
    //printf(" %d ",tail->data);
    //tail=tail->prev;
    //}
}
void main()
{
    queue *head=NULL;
    queue *tail=NULL;
    int choice=1,temp;
    while(choice){
        printf("%s\n-------------------MAIN MENU-----------------\n%s",RED,RESET);
        printf("%s1)%s Insert in the front%s\n",RED,GRN,RESET);
        printf("%s2)%s Insert in the rear%s\n",RED,GRN,RESET);
        printf("%s3)%s Delete in the front%s\n",RED,GRN,RESET);
        printf("%s4)%s Delete in the rear%s\n",RED,GRN,RESET);
        printf("%s5)%s Display the Queue%s\n",RED,GRN,RESET);
        printf("%s6)%s Exit Program%s\n",RED,GRN,RESET);
        printf("%s---------------------------------------------\n%s",RED,RESET);
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter element: "); scanf("%d",&temp); insertAtFront(&head,&tail,temp); break;
            case 2: printf("Enter element: "); scanf("%d",&temp); insertAtRear(&head,&tail,temp); break;
            case 3: deleteAtFront(&head); break;
            case 4: deleteAtRear(&tail); break;
            case 5: printlist(head,tail); break;
            default : choice=0;
        }
    }
}