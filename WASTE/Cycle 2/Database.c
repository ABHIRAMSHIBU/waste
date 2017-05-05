#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define DB_NAME "test.db"
#define secF "counter"
#define tempfile "temp"
#define DB_NAME2 "test.db.temp"
void write(FILE *file)
{
    FILE *tempfile1,*secretf; // All temporary files
    char status[2],balance[100],acno[10000],bank[100];
    long long int acnoi,balancei,secret;
    file=fopen(DB_NAME,"w"); //Test.db is the database
    secretf=fopen(secF,"w");
    secret=0;
    printf("Enter Balance <space> status[1/0] :");
    acnoi=secret;
    scanf("%lld %s",&balancei,status);
    tempfile1=fopen(tempfile,"w+");
    fprintf(tempfile1,"%.4d",acnoi);
    rewind(tempfile1);
    fscanf(tempfile1,"%s",acno);
    rewind(tempfile1);
    fprintf(tempfile1,"%.40lld",balancei);
    rewind(tempfile1);
    fscanf(tempfile1,"%s",balance);
    fclose(tempfile1);
    strcat(acno,"/");
    strcat(balance,"/");
    strcat(status,"'");
    strcat(acno,balance);
    strcat(acno,status);
    secret++;
    printf("\nAppend line :%.11lld/%s",secret,acno);
    fprintf(file,"%.11lld/%s\n",secret,acno);
    rewind(secretf);
    fprintf(secretf,"%lld",secret);
}
void append(FILE *file)
{
    FILE *tempfile1,*secretf; // All temporary files
    char status[2],balance[100],acno[10000],bank[100];
    long long int acnoi,balancei,secret;
    file=fopen(DB_NAME,"a"); //Test.db is the database
    secretf=fopen(secF,"r+");
    if(secretf!=NULL)
    {
        printf("Enter Balance <space> status[1/0] :");
        fscanf(secretf,"%lld",&secret);
        acnoi=secret;
        scanf("%lld %s",&balancei,status);
        tempfile1=fopen(tempfile,"w+");
        fprintf(tempfile1,"%.4d",acnoi);
        rewind(tempfile1);
        fscanf(tempfile1,"%s",acno);
        rewind(tempfile1);
        fprintf(tempfile1,"%.40lld",balancei);
        rewind(tempfile1);
        fscanf(tempfile1,"%s",balance);
        fclose(tempfile1);
        strcat(acno,"/");
        strcat(balance,"/");
        strcat(status,"'");
        strcat(acno,balance);
        strcat(acno,status);
        secret++;
        printf("\nAppend line :%.11lld/%s",secret,acno);
        fprintf(file,"%.11lld/%s\n",secret,acno);
        rewind(secretf);
        fprintf(secretf,"%lld",secret);
    }
    else
    {
        printf("Critical files missing, cannot proceed sorry!\n");
        perror("Error");
    }
}
void dumpall(FILE *file)
{
    char line[10000]="Start",lineup[10000];
    int i;
    file=fopen(DB_NAME,"r");
    while(!feof(file))
    {
        fgets(lineup,10000,file);
        if(strcmp(lineup,line))
        {
            strcpy(line,lineup);
            printf("ID:");
            for(i=0;i<11;i++)
            {
                printf("%c",line[i]);
            }
            printf(" ACCOUNT_NUMBER:");
            for(i=12;i<16;i++)
            {
                printf("%c",line[i]);
            }
            printf(" ACCOUNT_BALANCE:");
            for(i=17;i<57;i++)
            {
                printf("%c",line[i]);
            }
            printf(" ACCOUNT_STATUS:");
            if(line[58]=='1')
            {
                printf("ACTIVE");
            }
            else
            {
                printf("INACTIVE[%c]",line[58]);
            }
            printf("\n");
        }
    }
}
void update(FILE *file)
{
    char line[10000]="Start",lineup[10000];
    int i,flag=1,z;
    long long int UACi;
    char UAC[1000],zc[1000];
    FILE *tempfile1,*filenew;
    filenew=fopen(DB_NAME2,"w");
    printf("Enter the account number to update :");
    scanf("%d",&UACi);
    tempfile1=fopen(tempfile,"w+");
    fprintf(tempfile1,"%.4d",UACi);
    rewind(tempfile1);
    fscanf(tempfile1,"%s",UAC);
    rewind(tempfile1);
    file=fopen(DB_NAME,"r");
    while(!feof(file))
    {
        fgets(lineup,10000,file);
        if(strcmp(lineup,line))
        {
            strcpy(line,lineup);
            for(i=12;i<16;i++)
            {
                if(line[i]!=UAC[i-12])
                {
                    flag=0;
                }
                else
                {
                    flag=flag&&1;
                }
            }
            if(flag==1)
            {
                //printf("Found");
                printf("Enter update amount:");
                scanf("%d",&z);
                fprintf(tempfile1,"%.40d",z);
                rewind(tempfile1);
                fscanf(tempfile1,"%s",zc);
                for(i=17;i<57;i++)
                {
                        line[i]=zc[i-17];
                }
                printf("\n%s",line);
                fprintf(filenew,"%s",line);
            }
            else
            {
                //printf("Not found");
                fprintf(filenew,"%s",line);
            }
            printf("\n");
        }
    }
}
void main()
{
    FILE *file;   //Main File
    int c,check;
    printf("----------------------------------------Main Menu---------------------------------------------------\n1)  Append to existing database.\n2)  Create a new database file purging old database and append.\n3)  Update a record.\n4)  Dump all record.\n-----------------------------------------End Menu---------------------------------------------------\n");
    printf("Your choice :");
    scanf("%d",&c);
    if(c==1)
        append(file);
    else if(c==2)
        write(file);
    else if(c==3)
        update(file);
    else if(c==4)
        dumpall(file);
    else
        printf("Invalid input please try running this program again!");
}
