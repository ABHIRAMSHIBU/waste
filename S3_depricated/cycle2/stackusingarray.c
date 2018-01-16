#include<stdio.h>
#include<malloc.h>
#include "color.h"
#define DEBUG 1
#define VERSION 1.0
typedef struct stack{
    int top;
    int bottom;
    int size;
    int * stack;
}stack;
int PUSH(stack * A,int data){
    if(DEBUG){
        printf("%s____________________PROGRAM_TRACE_stack()_____________________%s\n",RED,RESET);
        printf("Pointer A : %p, Pointer A->stack : %p, Int A->size : %d, Int A->top : %d, Int A->size : %d\n",A,A->stack,A->size,A->top,A->size);
        printf("%s____________________END___TRACE___stack()_____________________%s\n",RED,RESET);
    }
    if(A->stack==NULL && DEBUG){
        printf("%sWhat the heck are you planing to do with a null stack!%s\n",RED,RESET);
    }
    else{
        if(DEBUG)
            printf("%sTrying to push to stack:%s%d\n",YEL,RESET,data);
        if((A->top)<(A->size)){
            *((A->stack)+A->top)=data;
            A->top+=1;
        }
        else{
            printf("%sStack overflow!%s\n",RED,RESET);
            return -1;
        }
    }
    if(DEBUG){
        printf("%sPush completed!%s\n",GRN,RESET);
    }
    return 0;
}
stack * create(int size){
    stack * new =NULL;
    new=malloc(sizeof(stack));
    if(new==NULL){
        printf("%sNo more memory in your system, please free up some memory and try again!%s\n",RED,RESET);
        new->stack=NULL;
        return NULL;
    }
    if(size==0){
        printf("%sWhy! Why do you want to create a stack with 0 elements!%s\n",RED,RESET);
        return NULL;
    }
    else{
            new->stack=malloc(sizeof(int)*size);
            if(new->stack==NULL){
                printf("%sSorry, memory overflow just occured! %sFREE UP RAM!%s\n",RED,RESET);
                free(new);
                new=NULL;
            }
            else{
                new->size=size;
                new->top=0;
                new->bottom=0;
                if(DEBUG){
                    printf("%s________________TRACE_________________%s\n",RED,RESET);
                    printf("Pointer new : %p, Pointer new->stack : %p, Int new->size : %d, Int new->top : %d, Int new->size : %d\n",new,new->stack,new->size,new->top,new->size);
                    printf("%s______________END_TRACE______________%s\n",RED,RESET);
                    printf("%sStack allocation completed! Hurray!%s\n",GRN,RESET);
                }
            }
    }
    return new;
}
void main(){
    printf("%sStack program, use a single array to make a stack.%s\n",GRN,RESET);
    stack * A;
    A=create(100);
    for(int i=0;i<101;i++){
        if(PUSH(A,i)==-1){
            printf("%sError occured!%s\n",RED,RESET);
        }
    }
    free(A);
}
