#include<stdio.h>
int main()
{
    long long int a;
    printf("Enter someting, please, enter please, please I beg of U :");
    scanf("%lld",&a);
    if(a>0)
    {
	printf("");
	main();
    }
    else
    {
	printf("%lld\n",a);
	main();
    }
    return 0;
}
