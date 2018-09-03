#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int a,b,c;
	float flag=0,z,r1,r2;
	clrscr();
	printf("Enter a<space>b<space>c :");
	scanf("%d %d %d",&a,&b,&c);
	z=((b*b)-(4*a*c));
	printf("%f",z);
	if(z>-1)
	{
		flag=0;
	}
	else
	{
		flag=1;
	}
	if(flag==1)
	{
		printf("Roots are imaginary!\n");
	}
	else
	{
		printf("\nRoots are real!\n");
	}
	if(flag==1)
	{
		if(b<0)
		{
			b=b*-1;
		}
		printf("(-%d+%fi)/%d",b,sqrt(z*-1),2*a);
	}
	else
	{
		z=sqrt(z);
		r1=((b*-1)+z)/(2*a);
		printf("%f",r1);
	}
	printf("\t");
	if(flag==1)
	{
		if(b<0)
		{
			b=b*-1;
		}
		printf("(-%d-%fi)/%d",b,sqrt(z*-1),2*a);
	}
	else
	{
		r2=((b*-1)-z)/(2*a);
		printf("%f",r2);
	}
	if(r1==r2)
	{
		printf("\nRoots are the same!");
	}
	getch();
	}
