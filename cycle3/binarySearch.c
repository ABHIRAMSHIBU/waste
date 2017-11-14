/* Program written by Abhiram Shibu
 * Copyright (C) 2017 Abhiram Shibu
 */
#include<stdio.h>
#include<malloc.h>
#define VERBOSE 1
#define VERSION 1.0
/* Main bubble sort function with swap flag */
int Sort(int a[],int size){
    int swapFlag=0;
    for(int i=size;i>0;i--){                                                         //Move subarray
        for(int j=0;j<i-1;j++){                                                    //Move largest element to end
            if(a[j]>a[j+1]){                                                            //Swap
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                swapFlag=1;
            }
            /* Print to user */
            if(VERBOSE==1){
                for(int k=0;k<size;k++){
                    printf("%d\t",a[k]);
                }
                printf("\n");
            }
        }
        if(swapFlag==0){
            break;
        }
        else{
            swapFlag=0;
        }
    }
    return 0;
}
int binarySearch(int a[], int ll, int ul, int data){
    int mid=(ul+ll)/2;
    if(ll==ul){
        if(data==a[ll])
            return ll;
        else
            return -1;
    }
    else if(data==a[mid]){
        return mid;
    }
    else if(data<a[mid]){
        return(binarySearch(a,ll,mid-1,data));
    }
    else if(data>a[mid]){
        return(binarySearch(a,mid+1,ul,data));
    }
}
void search(int * a,int n){
    printf("Enter an element to search:");
    int data;
    scanf("%d",&data);
    printf("Binary search of %d:%d\n",data,binarySearch(a,0,n-1,data));
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
    Sort(a,n);
    search(a,n);
}
