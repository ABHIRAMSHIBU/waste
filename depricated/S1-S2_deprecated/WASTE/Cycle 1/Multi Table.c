#include<conio.h>
#include<stdio.h>
int main()
{
	int a=0,b=0,i,j;
	printf("Enter the range, lower limit folowed by upper limit :");
	scanf("%d%d",&a,&b);
    	for(i=a;i<=b;i++)
	{
        		printf("\n==========START===========\n");
		for(j=0;j<=10;j++)
		{
			printf("%d * %d = %d \n",j,i,j*i);
		}
		printf("\n==========END===========\n");
	}
	getch();
}
