#include<stdio.h>
#include<conio.h>
void compute(int n)
   {
       int i,j,a[1000],buff[1000],temp;
    for(i=0;i<n;i++)
        {
            printf("Enter element %d:",i+1);
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
                if(a[i]>a[j])
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
        printf("\nSorted elements\n");
        for(i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        if(n%2==0)
        {
            temp=(a[n/2-1]+a[(n/2)])/2;
            printf("\nMedian = %d",temp);
        }
        else
        {
            printf("\nMedian = %d",a[n/2]);
        }
        for(i=0;i<n;i++)
        {
            temp=0;
            for(j=i;j<n;j++)
            {
                if(a[i]==a[j])
                {
                temp=temp+1;
                }
            }
            buff[i]=temp;
        }
        printf("\nFrequency distribution table : ");
        for(i=0;i<n;i++)
        {
            printf("%d ",buff[i]);
        }
        temp=buff[0];
        j=0;
        for(i=1;i<n;i++)
        {
            if(buff[i]>temp)
            {
            temp=buff[i];
            j=i;
            }
        }
        printf("\nThe number %d has repeated the max for %d times",a[j],temp);
   }
void main()
{
    int n;
    printf("Enter the number of elements to input [MAX 1000] :");
    scanf("%d",&n);
    if(n<=1000&&n>0)
    {
        compute(n);
    }
    else
    {
        printf("Limit ERROR occurred! Limit=%d is unacceptable",n);
    }
}
