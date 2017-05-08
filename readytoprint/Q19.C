#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char *names[20],name[20];
	int i,n,j,f;
	char *temp,ch;
	printf("\n Enter the no of names you want to enter:");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
		names[i]=(char *)malloc(20*sizeof(char));
	printf("\n Enter the names:");
	for(i=0;i<=n;i++)
			gets(names[i]);
	for(i=0;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(*names[i]>*names[j])
			{
				temp=names[i];
				names[i]=names[j];
				names[j]=temp;
			}
		}
	}
	printf("\n The sorted list of names:");
	for(i=0;i<=n;i++)
			puts(names[i]);
	printf("\n Enter the name you want to search:");
	gets(name);
	for(i=0;i<=n;i++)
	{
		if(strcmp(names[i],name)==0)
		{
			f=1;
			break;
		}
		else
			f=0;
	}
	if(f==1)
		printf("\n The name is in the list");
	else
		printf("\n The name is not in the list");
	printf("\n Enter a character");
	scanf("%c",&ch);
	printf("\n Names starting with %c:",ch);
	for(i=0;i<=n;i++)
		if(names[i][0]==ch)
			puts(names[i]);
	getch();
}
