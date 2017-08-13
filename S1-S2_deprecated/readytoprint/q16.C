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
		printf("\n Median:%f",(a[n/2]+a[(n/2)-1])/2.0);
	else
		printf("\n Median:%f",a[(n-1)/2.0]);

}

int freq(int a[],int n,int freq[10][2])
{
	int i,j,k,no,s;
	int freqt[10][2];
	k=0;
	for(i=0;i<n;i++)   //create frequency table
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
	s=0;
	for(i=0;i<no;i+=freqt[i][1])
	{
		freq[s][0]=freqt[i][0];
		freq[s][1]=freqt[i][1];
		s++;
	}


	return s;


}
void mode(int freqt[10][2],int no)
{  	int large,i,f,in;
	float mod;
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
			else if(freqt[i][1]==large)
			{
				mod=(mod+freqt[i][0])/2.0;
			}
		}
		printf("\n Mode:%f",mod);
	}
	else
		printf("\n There is no mode for the given list..");
}


void main()
{
	int a[10],n,no,i;
	int freqt[10][2];
	clrscr();
	printf("\n Enter no of elements:");
	scanf("%d",&n);
	printf("\n Enter elements:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	median(a,n);
	printf("\n");
	no=freq(a,n,freqt);
	printf("\n Frequency table\n");
	printf(" NO.\tFrequency\n");
	for(i=0;i<no-1;i++)
	{
		printf(" %d\t%d\n",freqt[i][0],freqt[i][1]);
	}
	mode(freqt,no);


	getch();
}





