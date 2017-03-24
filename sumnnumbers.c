#include<stdio.h>
int main(){
    int a,i=0,buff=0;
    printf("Enter the limit :");
    scanf("%d",&a);
    for(i=0;i<a+1;i++)
        buff=buff+i;
    printf("%d",buff);
    return 0;}
