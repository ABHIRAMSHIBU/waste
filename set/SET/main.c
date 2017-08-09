//Program made by Abhiram Shibu and Abhijith N Raj
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int size;
    char *set[103710];
}set;
void set_init(set *A)
{
    A->size=0;
    //A->set[A->size]=malloc(sizeof(char)*1000);
    //A->set[A->size]='\0';
}

int checkpresent(set *A,char item[])
{
        int i;
    int flag;
    for(i=0;i<A->size;i++)
    {
        if(!strcmp(&A->set[i],item))
        {
            flag=1;
            break;
        }
        else
        {
            flag=0;
        }
    }

    return(flag);
}
void set_insert(set *A,char item[])
{
    if(checkpresent(A,item) !=1)
    {
        (*A).set[(*A).size]=malloc(sizeof(char)*1000);
        //printf("Adding value into %d",(*A).size);
        strcpy(&A->set[A->size],item);
        (*A).size++;
    }

}

set *Union(set *A,set *B)
{
    int i=0,j=0;
    set *temp;
    temp=A;
    set val=*temp;
    temp=&val;
    for(i=0;i<B->size;i++)
    {
        if(checkpresent(temp,&B->set[i])==0)
        {
            set_insert(temp,&B->set[i]);
        }
    }

    return(temp);
}

set *Intersection(set *A,set *B)
{
    set Int;
    set *val;
    val=&Int;
    set_init(&Int);
    int i=0;
    for(i=0;i<A->size;i++)
    {
        if(checkpresent(B,&A->set[i])==1)
        {
            set_insert(&Int,&A->set[i]);
        }
    }

    return(val);
}

set *Minus(set *A,set *B)
{
    set Int;
    set *val;
    val=&Int;
    set_init(&Int);
    int i=0;
    for(i=0;i<A->size;i++)
    {
        if(checkpresent(B,&A->set[i])==0)
        {
            set_insert(&Int,&A->set[i]);
        }
    }

    return(val);
}

set *dell(set *A,set *B)
{
    set AB=*Minus(A,B);
    set BA=*Minus(B,A);
    return(Union(&AB,&BA));
}


void set_disp(set *A)
{
    int i;
    printf("{");
    for(i=0;i<(A->size);i++)
    {
        //printf("%d",i);
        printf(" %s",&A->set[i]);
        if(i!=A->size-1)
        {
            printf(",");
        }
    }
    printf("}\n");
}
void menu(set *A,set *B)
{
    char c=NULL;
    system("clear");
    printf("\nWelcome to basic set operations program");
    printf("\nA=");
    set_disp(A);
    printf("\nB=");
    set_disp(B);
    printf("\n================Main Menu==============");
    printf("\nOption         Description             ");
    printf("\n---------------------------------------");
    printf("\n1               A \u222A B              ");
    printf("\n2               A \u2229 B              ");
    printf("\n3               A - B              ");
    printf("\n4               B - A              ");
    printf("\n5               A \u0394 B              ");
    printf("\n6             New A and B              ");
    printf("\n7               EXIT                ");
    printf("\n---------------------------------------");
    printf("\n\nEnter an option :");
    scanf(" %c",&c);
    printf("%c",c);
    if(c=='1')
    {   printf("\nOption 1 selected.\n");
        printf("A \u222A B:\n");
        printf("\nR=");
        set_disp(Union(A,B));
        printf("Press any key to continue....");
        getchar();
        getchar();
        menu(A,B);
    }
    else if(c=='2')
    {
        printf("\nOption 2 selected.\n");
        printf("A \u2229 B:\n");
        printf("\nR=");
        set_disp(Intersection(A,B));
        printf("Press any key to continue....");
        getchar();
        getchar();
        menu(A,B);
    }
    else if(c=='3')
    {

        printf("\nOption 3 selected.\n");
        printf("A - B:\n");
        printf("\nR=");
        set_disp(Minus(A,B));
        printf("Press any key to continue....");
        getchar();
        getchar();
        menu(A,B);

    }
    else if(c=='4')
    {

        printf("\nOption 4 selected.\n");
        printf("B - A:\n");
        printf("\nR=");
        set_disp(Minus(B,A));
        printf("Press any key to continue....");
        getchar();
        getchar();
        menu(A,B);

    }
    else if(c=='5')
    {

        printf("\nOption 5 selected.\n");
        printf("A \u0394 B :\n");
        printf("\nR=");
        set_disp(dell(A,B));
        printf("Press any key to continue....");
        getchar();
        getchar();
        menu(A,B);
    }

    else if(c=='6')
    {
        main();
    }

    else if(c=='7')
    {
        printf("\nOption 7 selected. Exiting..");
        return;
    }

    else
    {

        printf("\nSorry invalid option. Please try again");
        menu(A,B);
    }
}
int main()
{
    system("clear");
    set A;
    set B;
    char buff[1000];
    set_init(&A);
    while(1)
    {
        printf("Enter a element in set A [/0=end]:");
        scanf("%s",buff);
        if(!strcmp(buff,"/0"))
            break;
        set_insert(&A, buff);
    }
    //("Size %d, set %s",A.size,&A.set[0]);
    printf("A=");
    set_disp(&A);
    set_init(&B);
    while(1)
    {
        printf("Enter a element in set B [/0=end]:");
        scanf("%s",buff);
        if(!strcmp(buff,"/0"))
            break;
        set_insert(&B, buff);
    }
    //("Size %d, set %s",A.size,&A.set[0]);
    printf("B=");
    set_disp(&B);
    printf("Press any key to continue....");
    getchar();
    getchar();
    menu(&A,&B);
}
