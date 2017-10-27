/*Copyright (c) 2017 Abhiram Shibu
 *Copyright (c) 2017 Team Destroyer Projects\
 */     
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
    printf("%smove disk %s%d",RED,GRN,n);
    printf("%s from rod %s%c",RED,GRN, from);
    printf("%s to rod %s%c%s\n",RED,GRN,to,RESET );
    *step=*step+1;
	towerOfHanoi(step,n-1, sub, to, from);
}

int main()
{
    printf("%sProgram Written by %sAbhiram Shibu\n \t\tTOWER!%s\n",BLU,RED,RESET);
	int n;
	int step=1;
    printf("%sEnter number of disks:%s",RED,GRN);
    printf("%s",RESET);
    scanf("%d",&n);
	towerOfHanoi(&step,n, 'A', 'B', 'C');
	return 0;
}
