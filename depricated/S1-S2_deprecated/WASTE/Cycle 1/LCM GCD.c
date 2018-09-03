#include<conio.h>
#include<stdio.h>
void main()
{
 int a,b,n,d,lcm,gcd,r;
 printf("Enter two  numbers: ");
 scanf("%d %d", &a,&b);
 if(a>b)
  {
   n=a;
   d=b;
  }
 else
  {
   n=b;
   d=a;
  }
 r=n%d;
 while(r!=0)
  {
   n=d;
   d=r;
   r=n%d;
  }
 gcd=d;
 lcm=a*b/gcd;
 printf("LCM is %d \n",lcm);
 printf("GCD is %d \n",gcd);
 getch();
}
