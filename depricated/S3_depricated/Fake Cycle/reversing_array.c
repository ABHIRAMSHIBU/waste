//Program to reverse an array using pointers

#include<stdio.h>

void reverse_array(int *a,int n)//*a has value and a has address
{
	int i,temp;
	for(i=0;i<n/2;i++)
	{
		temp=*(a+i);
		*(a+i)=*(a+n-1-i);
		*(a+n-1-i)=temp;
	}
}

void display(int *a,int n)
{	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\n",*(a+i));
	}
}
int main()
{
	int *a;
	int i=0,n;
	printf("\nEnter the no of elements of the array\n");
	scanf("%d",&n);
	a=malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	printf("\nElements of the array befor reversing\n");
	display(a,n);
	reverse_array(a,n);
	printf("Reversed array is \n");
	display(a,n);	
	
}
