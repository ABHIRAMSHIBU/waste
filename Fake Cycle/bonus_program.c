#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void product_check(int *set, int set_size ,int k ,int n)
{
	unsigned int pow_set_size = pow(2, set_size);       //Calculating max size of power set.
	int counter, j, prod;
	int final_counter=0;
	int product=1;
        int c=0;
	int buff[pow_set_size];
	for(counter = 1; counter < pow_set_size; counter++) //Run counter to generate all permutations 00000->11111 00000={} 11111={set of all elements}.
	{
        	product=1;
        	c=0;
		for(int i=0; i<pow_set_size;i++)                   //Flush buffer
			buff[i]=0;
        	for(j = 0; j < set_size; j++)                       //Check by using each element.
        	{
            		if(counter & (1<<j))                            //Checking if counter or j is zero, that = nullset
            		{
                		//printf("%d*",set[j]);
                		product*=set[j];
				buff[c]=set[j];
                		c++;
            		}

        	}
        	//printf("\b");
        	//printf("=%d\n",product);
        	if(c==n && product==k)
        	{
			for(int i=0;i<n;i++)
			{
				printf("%d ",buff[i]);
				if(i!=n-1)
				{
					printf("* ");
				}
			}
			printf("= %d",product);
            		final_counter++;
            		getchar();
        	}

    	}
    printf("\n\nThe end of iterations\n");
    printf("Answer is :%d\n",final_counter);
}
int main()
{
	int k,n,factors[1000];
	printf("\nEnter k and n:");
	scanf("%d %d",&k,&n);
	getchar();
	int factor_size=0;
	for(int i=1;i<=k;i++)
	{
        if(k%i==0)
        {
            factors[factor_size]=i;
            factor_size++;
        }
	}
	printf("Factors = ");
	for(int i=0;i<factor_size;i++)
	{
        	printf("%d",factors[i]);
		if(i<factor_size-1)
		{
			printf(", ");
		}
	}
	printf("\n\n\n");
	product_check(factors, factor_size,k,n);            //Calculating factors and products.      
	return 0;
}
