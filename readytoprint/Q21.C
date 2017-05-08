#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct custrec
{
	char accno[7];
	int balance;
	char state;
}rec;
void menu();
void add(char [4]);
void update();
void disp(rec r);
void main()
{
	clrscr();
	menu();
	fcloseall();
	getch();
}
void add(char s[4])
{
	rec r;
	FILE *p;
	char accno[5];
	int i;
	printf("\n Acc no:");
	scanf("%s",&accno);
	strcpy(r.accno,"no");
	strcat(r.accno,accno);
	printf("\n Balance:Rs.");
	scanf("%d",&r.balance);
	printf("\n state(active(1)/closed(0)):");
	r.state=getche();
	if((p=fopen("custrecord.dat",s))==NULL)
	{
		printf("\n Error opening file..");
		getch();
		menu();

	}
	else
		fwrite(&r,sizeof(r),1,p);
	fclose(p);
	printf("\n The record was added sucessfully..");
	getch();


}
void update()
{
	rec r;
	int pos=-1,i;
	char acc[5],ch='n';
	FILE *p;
	printf("\n Enter the account no you want to update:");

	scanf("%s",&acc);
	if((p=fopen("custrecord.dat","rb+"))==NULL)
	{
			printf("\n Error opening file...");
			getch();
			clrscr();
			menu();
	}
       else
       {
		fseek(p,0,0);
		while(!feof(p))
		{
			fread(&r,sizeof(r),1,p);
			if(strcmp(r.accno,strcat("no",acc))==0)
			{

				pos=ftell(p);
				disp(r);
				break;
			}
			else
			    pos=-1;

		}
		if(pos!=-1)
			{
					fflush(stdin);
					fflush(stdout);
					printf("%s"," Do you want to update this record(y/n):");
					scanf("%c",&ch);
					if(ch=='y'||ch=='Y')
					{
						fflush(stdin);
						printf("\n");
						printf("\n Enter new details for the record:");
						printf("\n Balance:Rs.");
						scanf("%d",&r.balance);
						printf("\n State(acive(1)/closed(0)):");
						r.state=getche();
						fseek(p,pos-sizeof(r),0);
						fwrite(&r,sizeof(r),1,p);

						printf("\n The record  updated successfully..");
						getch();
					 }


			}
		else
		  {
			printf("\n The record was not found...");

			getch();
			clrscr();

		  }
		  fclose(p);
	}

}
void disp(rec r)
{
	printf("\n Details of customer:");
	printf("\n Accno:");
	puts(r.accno);
	printf("\n Balance:%d",r.balance);
	if(r.state=='1')
		printf("\n State:active");
	else
		printf("\n State:closed");
}
void menu()
{
	int op,i,no;



	printf("\n 1.store customer record\n 2.Update a record\n 3.Append a record\n 4.Exit");
	printf("\n Enter your choice...");
	scanf("%d",&op);
	if(op==1)
	{
		printf("\n Enter no of records:");
		scanf("%d",&no);
		for(i=0;i<no;i++)
		{
			printf("\n Enter details for customer %d",i+1);
			if(i==0)
				add("wb+");
			else
				add("ab+");

		}


	}
	else if(op==2)
	{
		update();

	}
	else if(op==3)
		{
			printf("\n\n Enter customer details:");
			add("ab");


		}
	else if(op==4)
		exit(0);

	else
		printf("\n invalid option");
}












