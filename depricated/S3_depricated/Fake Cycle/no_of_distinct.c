//pgm to calculate the no of ways in which n can be written as the product of k distinct non negative integers

#include<stdio.h>

long factorial(int n)
{
	if(n==0)
	{
		return 1;
	}
	else
	{	
		return n*factorial(n-1);
	}
}	

long combination(int n, int r)
{
	return factorial(n)/(factorial(n-r)*factorial(r));
}

void main()
{
	int n,k;
	printf("for f(n,k) enter n and k with comma:");
	scanf("%d,%d",&n,&k);
	printf("No of ways in which n can be written as product of k distinct integers is %d",combination(n+k-1,k-1));
}
