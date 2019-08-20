#include<unistd.h>
#include<stdio.h>
#include<stdbool.h>
#define True 1
#define False 0
int checkPrime(int z){
    if(z==0){
        return 0;
    }
    bool flag=True;
    if(z>1){
        for(int i=2;i<z;i++){
            if(z%i==0){
                flag=False;
                break;
            }
        }
        return flag;
    }
}
int findPrimeAndSum(int a[], int n){
    int sum=0;
    for(int i;i<n;i++){
        if(a[i]!=1){
            if(checkPrime(a[i])){
                sum+=a[i];
            }
        }
    }
    return sum;
}
int findNonPrimeAndSum(int a[],int n){
    int sum=0;
    for(int i;i<n;i++){
        if(a[i]!=1){
            if(!checkPrime(a[i])){
                sum+=a[i];
            }
        }
    }
    return sum;
}
// void main(){
//     int n;
//     scanf("%d",&n);
//     printf("%d",checkPrime(n));
// }
void main(){
    int a[]={10,2,4,6,44,56,34};
    int n=sizeof(a)/sizeof(int);
    printf("N is %d",n);
    if(fork()==0){
        printf("(Child)The sum is:%d\n",findPrimeAndSum(a,n));
    }
    else{
        printf("(Parent)The sum is:%d\n",findNonPrimeAndSum(a,n));
    }
}