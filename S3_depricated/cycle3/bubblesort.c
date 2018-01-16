/* Program written by Abhiram Shibu
 * Copyright (C) 2017 Abhiram Shibu
 */
#include<stdio.h>
#include<malloc.h>
#define VERBOSE 1
#define VERSION 1.0
/* Main bubble sort function with swap flag recursive */
int bubbleSort(int a[],int i,int swapFlag){
    if(i>0 && swapFlag==1){
        for(int j=0;j<i-1;j++){                                                    //Move largest element to end
            if(a[j]>a[j+1]){                                                            //Swap
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                swapFlag=1;
            }
        }
        if(swapFlag==0){
            return 0;
        }
        else{
            swapFlag=1;
        }
         bubbleSort(a,i-1,swapFlag);
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
    bubbleSort(a,n,1);
     if(VERBOSE==1){
        for(int k=0;k<n;k++){
            printf("%d\t",a[k]);
        }
        printf("\n");
    }
}
