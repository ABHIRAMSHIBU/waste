#include<stdio.h>
#include<conio.h>
void main()
{
 int a,d,n,i;
 printf("Enter first term , the common difference and nth term: ");
 scanf("%d %d %d",&a,&d,&n);
 for(i=2;i<=n;i++)
a=a+d;
 printf("%dth term is %d \n",n,a);
 getch();
}
