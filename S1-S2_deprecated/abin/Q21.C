#define _GNU_SOURCE
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct custrec
{
	char accno[6];
	float balance;
	int state;
}rec;
void menu();
void add(char [2]);

void update();
void disp(rec r);


int main()
{
	menu();
//	fcloseall();
}
void add(char s[4])
{
	rec r;
	FILE *p;
	char accno1[5];
	int accno,i,j,t;
	printf("\n Acc no:");
	scanf("%d",&accno);
	r.accno[0]='n';
	r.accno[1]='o';
	i=5;
	while(accno>0)
	{
		t=accno%10;
		accno1[i]=(char)t;
		i--;
		accno/=10;
	}
	strcat(r.accno,accno1);
	r.accno[6]='\0';
	printf("\n Balance:");
	scanf("%f",&r.balance);
	printf("\n state(active(1)/closed(0)):");
	scanf("%d",&r.state);
	if((p=fopen("custrecord.dat",s))==NULL)
	{
		printf("\n Error opening file..");
		exit(0);
	}
	else
		fwrite(&r,sizeof(r),1,p);
	fclose(p);
}
void update()
{
	rec r;
	int pos;
	char acc[7];
	FILE *p;
	printf("\n Enter the account no you want to update:");
	scanf("%s",acc);
       if((p=fopen("custrecord.dat","rb+"))==NULL)
		printf("\nerror");
       else
       {
	while(!feof(p))
	{
		fread(&r,sizeof(r),1,p);
		if(strcmp(r.accno,strcat("no",acc))!=0)
		{
			disp(r);
			printf("\n Enter new details for the record:");
			printf("\n Balance:");
			scanf("%f",&r.balance);
			printf("\n State:");
			scanf("%d",&r.state);
			pos=ftell(p);
			break;
		}
		else
			printf("\n The record was not found");
	}
	fclose(p);
	p=fopen("custrecord.dat","ab+");
	fseek(p,pos,0);
	fwrite(&r,sizeof(r),1,p);
	fclose(p);
}      }
void disp(rec r)
{
	printf("\n Details of customer:");
	printf("\nAcc no:%s",r.accno);
	printf("\n Balance:%f",r.balance);
	if(r.state==1)
		printf("\n State:%s","active");
	else
		printf("\n State:%s","closed");
}
void menu()
{
	int op,i,no;
	printf("\n 1.store customer record\n 2.Update a record\n 3.Append a record");
	printf("\n Enter your choice...");
	scanf("%d",&op);
	if(op==1)
	{
		printf("\n Enter no of records:");
		scanf("%d",&no);
		for(i=0;i<no;i++)
		{
			printf("\n Enter details for customer %d",i+1);
			add("wb+");
		}
	}
	else if(op==2)
		update();
	else if(op==3)
		{
			printf("\n Enter customer details:");
			add("ab+");
		}
	else
		printf("\n invalid option");
}












