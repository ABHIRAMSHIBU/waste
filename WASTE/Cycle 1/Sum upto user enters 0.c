#include<stdio.h>
#include<conio.h>
void main()
{
 int n,sum=0,i;
 printf("Enter the numbers(Enter  0 to stop input)\n");
 do
 {
  scanf("%d",&n);
  sum=sum+n;
 }while(n!=0);
 printf("The sum of all the numbers is %d \n",sum);
 getch();
}
