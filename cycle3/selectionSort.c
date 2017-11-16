/* Program written by Abhiram Shibu
 * Copyright (C) 2017 Abhiram Shibu
 */
#include<stdio.h>
#include<malloc.h>
#define VERBOSE 1
#define VERSION 1.0
/* Main selection sort function with swap flag recursive */
int selectionSort(int * a,int i){
    int big=a[i-1];
    int bigIndex=i-1;
    if(i==0){
        return 0;
    }
    for(int j=0;j<i-1;j++){                                                    //Move largest element to end
        if(big<a[j]){                                                            //Swap
            big=a[j];
            bigIndex=j;
        }
    }
    if(bigIndex<i){
        a[bigIndex]=a[i-1];
        a[i-1]=big;
    }
    selectionSort(a,i-1);
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
    selectionSort(a,n);
     if(VERBOSE==1){
        for(int k=0;k<n;k++){
            printf("%d\t",a[k]);
        }
        printf("\n");
    }
}
