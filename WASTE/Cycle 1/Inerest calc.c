#include<stdio.h>
#include<conio.h>
void main()
{
 float p,r,t,i;
 printf("Enter the amount and number of years:");
 scanf("%f %f", &p,&t);
 if(p<=1000 && t>=2)
  r=0.05;
 else if(p>1000 && p<5000 && t>=2)
  r=0.07;
 else if(p>5000 && t>=1)
  r=0.08;
 else if(t>=5)
  r=0.10;
 else
  r=0.30;
 i=p*r*t;
 printf("Interest %f ",i);
 getch();
}
