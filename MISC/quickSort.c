#include<stdio.h>
int partition(int a[],int ll,int ul){
        int loc=ll;
        int temp=0;
        while(ll<ul){
            while(a[loc]<=a[ul] && loc<ul){
                ul=ul-1;
            }
            if(a[loc]>a[ul]){
                temp=a[loc];
                a[loc]=a[ul];
                a[ul]=temp;
                loc=ul;
                ll=ll+1;
            }
            while(a[loc]>=a[ll] && loc>ll){
                ll=ll+1;
            }
            if(a[loc]<a[ll]){
                temp=a[loc];
                a[loc]=a[ll];
                a[ll]=temp;
                loc=ll;
                ul=ul-1;
            }
        }
        return loc;
}
void quicksort(int a[],int ll,int ul){
    if(ll<ul){
        int pivot=partition(a,ll,ul);
        quicksort(a,ll,pivot-1);
        quicksort(a,pivot+1,ul);
    }
    return;
}
int main(){
    int a[100];
    quicksort(a,0,99);
    for(int i=0;i<100;i++){
        printf("Index: %d, value: %d\n",i,a[i]);
    }
    
    return 0;
}
