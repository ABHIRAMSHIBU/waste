#include<stdio.h>
#include "color.h"
/* Tower of Hanoi recursive way */
void towerOfHanoi(int * step,int n, char from, char to, char sub)
{
	if (n == 1)
	{
		printf("\t%sStep:%s%d, ",RED,GRN,* step);
        printf("%smove disk %s1",RED,GRN, from, to);
        printf("%s from rod %s%c",RED,GRN, from);
        printf("%s to rod %s%c%s\n",RED,GRN,to,RESET );
        *step=*step+1;
		return;
	}
	towerOfHanoi(step,n-1, from, sub, to);
	printf("\t%sStep:%s%d, ",RED,GRN,* step);
    printf("%smove disk %s1",RED,GRN, from, to);
    printf("%s from rod %s%c",RED,GRN, from);
    printf("%s to rod %s%c%s\n",RED,GRN,to,RESET );
    *step=*step+1;
	towerOfHanoi(step,n-1, sub, to, from);
}

int main()
{
    printf("%sProgram Written by %sAbhiram Shibu\n \t\tTOWER!%s\n",GRN,RED,RESET);
	int n = 3; // Number of disks
	int step=1;
	towerOfHanoi(&step,n, 'A', 'B', 'C'); // A, B and C are names of rods
	return 0;
}
