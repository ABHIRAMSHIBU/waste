
#include<stdio.h>
#include<conio.h>
typedef struct student
{
	int rollno;
	char name[20];
	int marks[3];
}stud;
void getdata(stud *s,int *n)
{
	int i,j;
	printf("\n Enter no of students:");
	scanf("%d",n);
	for(i=0;i<*n;i++)
	{
		printf("\n Enter details of student %d",i+1);
		printf("\n Roll no:");
		scanf("%d",&s[i].rollno);
		printf("\n Name:");
		scanf("%s",s[i].name);
		for(j=0;j<3;j++)
		{
			printf("\n mark of subject %d:",j+1);
			scanf("%d",&s[i].marks[j]);
		}

	}
}
void main()
{
	stud s[100],temp;
	int n,i,j,k,f=1;
	FILE *p,*in;
	clrscr();
	getdata(s,&n);
	if((p=fopen("student.dat","wb+"))==NULL)
	{
		printf("\n Error opening file...");
		exit(0);
	}
	else
	{
		for(i=0;i<n;i++)
			fwrite(&s[i],sizeof(s),1,p);
		fclose(p);
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(s[i].rollno>s[j].rollno)
				{
					temp=s[i];
					s[i]=s[j];
					s[j]=temp;
				}
			}
		}
		if((p=fopen("studsort.dat","wb+"))==NULL)
		{
			printf("\n Error opening file...");
			exit(0);
		}
		else
		{
			for(i=0;i<n;i++)
				fwrite(&s[i],sizeof(s),1,p);
			fclose(p);
			in=fopen("studsort.dat","rb+");
			printf("\n List of students failed:\n");
			k=0;
			while(k<n)
			{
				fread(&temp,sizeof(s),1,in);
				for(j=0;j<3;j++)
				{
					if(temp.marks[j]<40)
					{
						printf("\t%s\n",temp.name);
						break;
					}

				}
				k++;

			}
			fclose(in);
		}
	}
	getch();
}
