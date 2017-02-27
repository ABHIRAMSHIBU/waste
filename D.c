#include<stdio.h>
int main()
{
    long long int a=0,b=0,c=0;
    printf("Enter 3 numbers with space between them :");
    scanf("%lld %lld %lld",&a,&b,&c);
    if(a>b)
    {
        if(a>c)
        {
            printf("%lld is bigger\n",a);
        }
        else
        {
            printf("%lld is bigger\n",c);
        }
    }
    else
    {
        if(b>c)
        {
            printf("%lld is bigger\n",b);
        }
        else
        {
            printf("%lld is bigger\n",c);
        }
    }
    main();
    return 0;
}
