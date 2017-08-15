#include <stdio.h>
#include <math.h>
#include<stdlib.h>

void product_check(int *set, int set_size,int k,int n)
{
	/*set_size of power set of a set with set_size
	n is (2**n -1)*/
	unsigned int pow_set_size = pow(2, set_size);
	int counter, j,prod;
    int final_counter=0;
	/*Run from counter 000..0 to 111..1*/

	for(counter = 0; counter < pow_set_size; counter++)
	{
        int product=1;
        int c=0;
        char ans_values[1000]="";
        char temp[100]="";
        for(j = 0; j < set_size; j++)
        {
		/* Check if jth bit in the counter is set
			If set then pront jth element from set */
            if(counter & (1<<j))
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
    printf("The answer is %d",final_counter);
}

/*Driver program to test printPowerSet*/
int main()
{
	int k,n,factors[1000];
	printf("Enter k and n:\n");
	scanf("%d,%d",&k,&n);
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
