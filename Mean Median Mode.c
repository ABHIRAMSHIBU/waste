#include<stdio.h>
#include<conio.h>
void median(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	if(n%2==0)
		printf("\n Median:%d",(a[n/2]+a[(n/2)-1])/2);
	else
		printf("\n Median:%d",a[(n-1)/2]);

}
//frequency distribution
int freq(int a[],int n,int freqt[10][2])
{
	int i,j,k,no,s;
	k=0;
	for(i=0;i<n;i++)
	{       freqt[k][0]=a[i];
		freqt[k][1]=1;
		for(j=i+1;j<n;j++)
		{
			if(a[i]==a[j])
			{
				freqt[k][1]++;

			}
		}
		k++;
	}
	no=n+1;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(freqt[i][0]==freqt[j][0])
			{
				freqt[j][0]=freqt[j+1][0];
				freqt[j][1]=freqt[j+1][1];
				for(s=j+1;s<n+1;s++)
				{
					freqt[s][0]=freqt[s+1][0];
					freqt[s][1]=freqt[s+1][1];
				}
				no--;


			}
		}
	}

	return no;


}
void mode(int freqt[10][2],int no)
{  	int large,mod,i,f,in;
	in=freqt[0][1];
	for(i=0;i<no-1;i++)
	{
		if(freqt[i][1]==in)
			f=1;
		else
			{
				f=0;
				break;
			}
	}
	if(f==0)
	{

		for(i=0;i<no-1;i++)
		{ 	if(i==0)
			{
				large=freqt[0][1];
				mod=freqt[0][0];

			}
			if(freqt[i][1]>large)
			{
				large=freqt[i][1];
				mod=freqt[i][0];
			}
		}
		printf("\n Mode:%d",mod);
	}
	else
		printf("\n There is no mode for the given list..");
}


void main()
{
	int a[10],n,no,i;
	int freqt[10][2];
	printf("\n Enter no of elements:");
	scanf("%d",&n);
	printf("\n Enter elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	median(a,n);
	printf("\n");
	no=freq(a,n,freqt);
	printf("\n Frequency Distribution\n");
	printf(" Numbers6\tFrequency\n");
	for(i=0;i<no-1;i++)
	{
		printf(" %d\t\t%d\n",freqt[i][0],freqt[i][1]);
	}
	mode(freqt,no);
}
