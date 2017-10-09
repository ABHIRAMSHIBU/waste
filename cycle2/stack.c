/* Header file linkedlist
 * Author  Abhiram Shibu - https://github.com/ABHIRAMSHIBU
 * Copyright (c) 2017 Team Destroyer */
#include<malloc.h>
#include<stdio.h>
#include "stack.h"
int main()
{
    listPointer * head=NULL;
    int n,c;
    printf("Enter how many iterations push:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element %d :",i+1);
        scanf("%d",&c);
        push(&head,c);
    }
    printf("Enter how many iterations pop:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    printf("%d\n",pop(&head));
    }
//     printf("%d\n",pop(&head));
}
