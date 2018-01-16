//gcd_recursive Copyright 2017 Abhiram Shibu
#include <stdio.h>
recur_gcd(int var1, int var2) // Recursive Greatest common divisor
{
	if(var2==0)
		return var1;
	else
		recur_gcd(var2,var1%var2);
}
main()
{
	int var1,var2;
	printf("Enter elements seperated by ',' eg 2,1:");
	scanf("%d,%d",&var1,&var2);
	if(var1>var2)              //Will only work if first is greator
		printf("The answer is :%d",recur_gcd(var1,var2));
	else
		printf("The answer is :%d",recur_gcd(var2,var1));
	return 0;
}
