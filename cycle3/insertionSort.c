#include<stdio.h>
int insertionSort(int a[],int ll,int ul){
    if(ll==0){
        insertionSort(a,ll+1,ul);
    }
    else if(ll<ul){
        for(int i=ll;i>0;i--){
            if(a[i]<a[i-1]){
                int temp=a[i];
                a[i]=a[i-1];
                a[i-1]=temp;
            }
        }
        insertionSort(a,ll+1,ul);
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
    int * a=getArray(n);
    insertionSort(a,0,n);
    for(int i=0;i<n;i++){
        printf("Index: %d, value: %d\n",i,a[i]);
    }
    return 0;   
}
