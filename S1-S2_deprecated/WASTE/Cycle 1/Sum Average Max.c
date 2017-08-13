#include<stdio.h>
#include<conio.h>
void main()
{
 int i=0;
 float n,s=0,a,big=0;
 label:
  printf("Enter a number :");
  scanf("%f",&n);
  s=s+n;
  if(big<n)
   big=n;
  i++;
  if(i<5)
   goto label;
 a=s/5;
 printf("Sum= %f \n",s);
 printf("Average =%f \n", a);
 printf("Maximum =%f \n", big);
 getch();
}
