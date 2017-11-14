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

int main(){
    int a[100];
    insertionSort(a,0,100);
    for(int i=0;i<100;i++){
        printf("Index: %d, value: %d\n",i,a[i]);
    }
    return 0;   
}
