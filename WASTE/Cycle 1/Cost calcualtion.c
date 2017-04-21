#include<stdio.h>
#include<conio.h>

void main()
{
	float cp,tot;
	int op;
	printf("\n 1.Engine \n 2.Pump \n 3.Fan");
	printf("\n Enter an option:");
	scanf("%d",&op);
	printf("\n Enter  the cost:");
	scanf("%f",&cp);
	switch(op)
	{
		case 1: if(cp>=15000)
				tot=cp-cp*0.1;
			else
				tot=cp;
			printf("\n Total amount:%f",tot);
			break;
		case 2:if(cp>=12000)
				tot=cp-cp*0.2;
			else
				tot=cp;
			printf("\n Total amount:%f",tot);
			break;
		case 3:if(cp>=13000)
				tot=cp-cp*0.3;
			else
				tot=cp;
			printf("\n Total amount:%f",tot);
			break;
		default:printf("\n Invalid option");
	}
	getch();
}
