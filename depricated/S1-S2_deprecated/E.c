#include<stdio.h>
int main()
{
    long long int i,n,buffer=0;
    printf("Enter a number : ");
    scanf("%lld",&n);
    for(i=0;i<n+1;++i)
    {
        buffer=buffer+i;
    }
    printf("%d",buffer);
    return 0;
}
