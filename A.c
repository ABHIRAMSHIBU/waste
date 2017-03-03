#include<stdio.h>
#include<conio.h>
int main()
{
    long long int a;
    clrscr();
    printf("Enter some number :");
    scanf("%lld",&a);
    if(a>=0)
    {
	printf("\nERROR: Not allowed to print number!\n");
       //	main();
    }
    if(a<0)
    {
	printf("%lld\n",a);
       //	main();
    }
    getch();
    return 0;
}
