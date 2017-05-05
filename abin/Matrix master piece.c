
#include<stdio.h>
#include<conio.h>
void prod();
void ip(int a[10][10],int*,int*);
void op(int a[10][10],int,int);
void trans(int [10][10],int,int);
void sob(int [10][10],int,int);
void sym();
void main()
{

    int c;
    start:
    printf("\n1)Multiplication and boundary sum\n2)Symmetric Matrix?");
    printf("\n Enter an option :");
    scanf("%d",&c);
    if(c==1)
        prod();
	if(c==2)
        sym();
    goto start;
}
void prod()
{
	int a[10][10],b[10][10],m,n,i,j,p,q,c[10][10],k;
	printf("\n---Enter details of First matrix---");
	ip(a,&m,&n);
	printf("\n---Enter details of Second matrix---");
	ip(b,&p,&q);
	if(n==p)
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<q;j++)
			{
				c[i][j]=0;
				for(k=0;k<p;k++)
				{
					c[i][j]+=a[i][k]*b[k][j];
				}
			}
		}

		printf("\n Product is:");
		op(c,m,q);
	}
	else
	{
		printf("\n ERROR :COLUMN of first MATRIX should be equal to second MATRIX!");
	}
	trans(a,m,n);
	sob(b,p,q);
}
void ip(int a[10][10],int *m,int *n)
{
	int i,j;
	printf("\n Enter order of the matrix:");
	scanf("%d%d",m,n);
	printf("\n Enter elements:");
	for(i=0;i<*m;i++)
		for(j=0;j<*n;j++)
			scanf(" %d",&a[i][j]);
}
void op(int a[10][10],int m,int n)
{
	int i,j;
	for(i=0;i<m;i++)
	      {
			printf("\n");
			for(j=0;j<n;j++)
				printf("\t%d",a[i][j]);
	      }
}
void trans(int a[10][10],int m,int n)
{
	int i,j;
	if(m==n)
	{
		printf("\n Transpose of first matrix:");
		for(i=0;i<m;i++)
		{
			printf("\n");
			for(j=0;j<n;j++)
				printf("\t%d",a[j][i]);
		}
	}
	else
		printf("\n ERROR 1st Matrix is not a square matrix! Transpose undefined!");

}

void sob(int a[10][10],int m,int n)
{
	int i,j;
	int sum=0;
	for(i=1;i<n-1;i++)
	     {
			sum+=a[0][i];
			sum+=a[m-1][i];
	     }
	for(i=1;i<m-1;i++)
	      {
			sum+=a[i][0];
			sum+=a[n-1][i];
	      }
	      sum+=(a[0][0]+a[m-1][0]+a[0][n-1]+a[m-1][n-1]);
	printf("\n Sum of boundary numbers of second matrix=%d",sum);
	//sym();
}
void sym()
{
	int a[10][10],b[10][10],m,n,f,i,j;
	f=0;
	printf("\n---Enter details of a matrix---");
	ip(a,&m,&n);
	if(m==n)
	{
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
				b[i][j]=a[j][i];
		for(i=0;i<m;i++)
			for(j=0;j<n;j++)
			{
				if(a[i][j]==b[i][j])
					f=1;
				else
				{
					f=0;
					break;
				}
			}
		if(f==1)
		{
			printf("\n Entered matrix is Symmetric");
		}
		else
			printf("\n Entered matrix is Not symmetric");
	}

	else
		printf("\n Entered matrix is not symmetric");
}

