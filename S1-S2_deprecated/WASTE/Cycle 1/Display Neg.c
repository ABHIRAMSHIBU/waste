#include<conio.h>
#include<stdio.h>
int main()
{
   int n;
   printf("Enter a no:");
   scanf("%d",&n);
   if(n<0)
   printf("%d",n);
   else
   printf("***ErRoR No rule to desplay that number.");
   getch();
   return 0;
}
