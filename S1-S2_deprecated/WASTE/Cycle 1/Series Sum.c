#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
 float x,p,s=0;
 int n,i,m,f,j,flag;
 flag=1;
 printf("Enter 'X' and 'N':");
 scanf("%f %d",&x,&n);
 for(i=1;i<=n;i++)
 {
  m=2*i-1;
  f=1;
  for(j=1;j<=m;j++)
   f=f*j;
  p=pow(x,m);
  s=s+((flag*p)/f);
  if(flag==1)
   flag=-1;
  else
   flag=1;
 }
 printf("Sum of series is %f \n",s);
 getch();
}
