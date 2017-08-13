//WAP in C to compare 2 strings. If they are not the same concatenate the bigger string behing the shorter one. If they are both the same then reverse and split the 2nd string into 2 halfs and place the 1st string in the middle
#include<stdio.h>
#include<string.h>
char a[]="WAP in C to compare 2 strings. If they are not the same concatenate the bigger string behind the shorter one. If they are both the same then reverse and split the 2nd string into 2 halfs and place the 1st string in the middle";
char *strrev(char *var1)
{
	char *var2=malloc(sizeof(char)*100);
	//printf("\n%d",strlen(var1));
	for(int i=0;i<strlen(var1);i++)
	{
		var2[strlen(var1)-1-i]=var1[i];
		if(i==strlen(var1)-1)
			var2[strlen(var1)]='\0';
	}
	var2[strlen(var1)]='\0';
	return(var2);
}
main()
{
	printf(a);
	char var1[10000],var2[10000],src1[10000],src2[10000],src3[10000],src4[10000];
	printf("\n\nEnter 1st string:");
	scanf("%s",var1);
	printf("Enter 2nd string:");
	scanf("%s",var2);
	printf("String 1 is:%s \nString 2 is:%s",var1,var2);
	if(!strcmp(var1,var2))
	{
		if(strlen(var1)%2==0)
		{
			printf("\nThey are same\n");	
			//strcpy(var1,strrev(var1));
			printf("%s\n",strrev(var1));
			strncpy(src1,strrev(var1),strlen(var1)/2);
			strcat(src1,var1);
			strncpy(src2,var1,strlen(var1)/2);
			strcat(src1,strrev(src2));
			printf("The final value is %s",src1);
		}

		else
		{
			printf("\nThey are same\n");	
			printf("%s\n",strrev(var1));
			strncpy(src3,strrev(var1),strlen(var1)/2+1);
			strcat(src3,var1);
			strncpy(src4,var1,strlen(var1)/2);
			strcat(src3,strrev(src4));
			printf("The final value is %s",src3);
			
			/*printf("%s\n",strrev(var1));
			strncpy(src1,strrev(var1),strlen(var1)/2);
			strcat(src1,var1);
			strncpy(src2,var1,strlen(var1)/2+1);
			strcat(src1,strrev(src2));
			printf("The final value is %s",src1);*/
		

						
		}
	}
		
	else
	{
		printf("\nThey are not same\n");
		if(strlen(var1)>strlen(var2))
		{
			strcat(var1,var2);
			printf("%s\n",var1);
		}
		else
		{
			strcat(var2,var1);
			printf("%s\n",var2);
		}
	}
	return 0;
}
