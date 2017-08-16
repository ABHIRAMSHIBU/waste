#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	char model[25];
	int year;
	char manufacturer[25];
	int dim[3];
}cars;

int find_index(cars *car)
{
	int vol,big,i,pos=0;
	big=((car)->dim[0] * (car)->dim[1] * (car)->dim[2]);
	for(i=0;i<5;i++)
	{
		vol=((car+i)->dim[0] * (car+i)->dim[1] * (car+i)->dim[2]);
		if(vol>big)
		{
			big=vol;
			pos=i;
		}
	}
	return pos;
}
void main()
{
	cars *car;
	int index;
	car=(cars*)malloc(5*sizeof(cars));
	printf("Car program");
	for(int i=0;i<5;i++)
	{
		printf("Enter the model, year, manufacturer, dimension.Car  %d :",i+1);
		scanf("%s",(car+i)->model);
		scanf("%d",&(car+i)->year);
		scanf("%s",(car+i)->manufacturer);
		for(int j=0;j<3;j++)
		{
			scanf("%d",&(car+i)->dim[j]);
		}
	}
	index=find_index(car);
	printf("Biggest car is:");
	printf("%s ",(*(car+index)).model);
	printf("%d ",(*(car+index)).year);
	printf("%s \n",(*(car+index)).manufacturer);
	for(int j=0;j<3;j++)
	{
		   printf("%d ",(car+index)->dim[j]);
	}
	printf("\n");
}
