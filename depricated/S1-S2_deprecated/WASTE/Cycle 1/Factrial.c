#include<stdio.h>
#include<conio.h>
void main()
 {
  int f,i,n;
  f=1;
  i=1;
  printf("Enter an integer :");
  scanf("%d",&n);
  while(i<=n)
   {
    f=f*i;
    i=i+1;
   }
  printf("Factorial= %d",f);
  getch();
 }
