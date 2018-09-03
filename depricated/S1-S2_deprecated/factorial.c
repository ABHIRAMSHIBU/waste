#include<stdio.h>
void main()
{
    long long int a,fact=1;
    printf("Enter a number Max is 31 :");
    scanf("%llld",&a);
    while(a)
    {
        fact=fact*a--;
    }
    printf("Factorial of number is : %d",fact);
}
