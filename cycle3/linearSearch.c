/* Program written by Abhiram Shibu
 * Copyright (C) 2017 Abhiram Shibu
 */
#include<stdio.h>
#include<malloc.h>
#define VERBOSE 1
#define VERSION 1.0
int linearSearch(int a[],int n,int data){
    if(n==-1){
        return -1;
    }
    else{
        if(a[n]==data){
            return n;
        }
        else{
            return(linearSearch(a,n-1,data));
        }
    }
}
int * getArray(int n){
    int * a=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        printf("Enter element %d:",i+1);
        scanf("%d",&(a[i]));
    }
    return a;
}
int main(){
    printf("Enter the number of elements:");
    int n;
    scanf("%d",&n);
    int *a=getArray(n);
    int data;
    printf("Enter data you want to find:");
    scanf("%d",&data);
    printf("The index is:%d\n",linearSearch(a,n-1,data));
}
