#include<stdio.h>
#include<conio.h>
int main()
{
    long long int a;
    clrscr();
    printf("Enter a number :");
    scanf("%lld",&a);
    if(a%2==0)
    {
	printf("%lld is even !\n",a);
      //  main();
    }
    else
    {
	printf("%lld is odd !\n",a);
       // main();
    }
    getch();
}
