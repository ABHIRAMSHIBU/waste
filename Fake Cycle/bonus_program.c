#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void product_check(int *set, int set_size ,int k ,int n)
{
	unsigned int pow_set_size = pow(2, set_size);       //Calculating max size of power set.
	int counter, j, prod;
	int final_counter=0;
	for(counter = 0; counter < pow_set_size; counter++) //Run counter to generate all permutations 00000->11111 00000={} 11111={set of all elements}.
	{
        int product=1;
        int c=0;
        char ans_values[1000]="";
        char temp[100]="";
        for(j = 0; j < set_size; j++)                       //Check by using each element.
        {
            if(counter & (1<<j))                            //Checking if counter or j is zero, that = nullset
            {
                //printf("counter=%d,j=%d,counter & (1<<j)=%p\n",counter,j,counter &(1<<j));
                printf("%d*",set[j]);
                //printf("\nin loop %d",product);
                product*=set[j];
                c++;//printf("%d\n",product);
            }

        }
        printf("\b");
        printf("=%d\n",product);
        if(c==n && product==k)
        {
            final_counter++;
            getchar();
            getchar();
        }

    }
    printf("\n\nThe end of iterations\n");
    printf("Answer is :%d",final_counter);
}

/*Driver program to test printPowerSet*/
int main()
{
	int k,n,factors[1000];
	printf("\nEnter k and n:");
	scanf("%d %d",&k,&n);
	int factor_size=0;
	for(int i=1;i<=k;i++)
	{
        if(k%i==0)
        {
            factors[factor_size]=i;
            factor_size++;
        }
	}

	for(int i=0;i<factor_size;i++)
	{
        	printf("%d\n",factors[i]);
	}
	product_check(factors, factor_size,k,n);
	getchar();
	return 0;
}
