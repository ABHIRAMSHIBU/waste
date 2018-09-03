#include<stdio.h>
#include<conio.h>
int main()
{
    long long int n,i,big=0,temp=0;
    printf("Enter how many numbers :");
    scanf("%lld",&n);
    printf("Enter a number :");
    scanf("%lld",&big);
    for(i=0;i<n-1;i++)
    {
            printf("Enter a number :");
            scanf("%lld",&temp);
            if(temp>big)
            {
                        big=temp;
            }
    }
    printf("%lld is biggest",big);
    getch();
}
