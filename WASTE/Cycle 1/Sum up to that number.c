#include<conio.h>
#include<stdio.h>
int main()
{
	int sum=0,n,i;
	printf("Enter the no:");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		sum=sum+i;
	}
	printf("%d%s",sum," is the sum!");
	getch();
	}
