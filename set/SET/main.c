//SET_COMPUTE  Copyright (C) 2017 Abhiram Shibu, Abhijith N Raj
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
typedef struct
{
    int size;
    char *set[103710];
}set;

void set_init(set *A) //Initialize to zero
{
    A->size=0;
}

int set_check_present(set *A,char item[]) //Check if a vlaue is alredy present
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
void set_insert(set *A,char item[]) //Insert element to set.
{
    if(set_check_present(A,item) !=1)
    {
        (*A).set[(*A).size]=malloc(sizeof(char)*1000);
        strcpy(&A->set[A->size],item);
        (*A).size++;
    }

}

set *set_union(set *A,set *B) //A union B
{
    int i=0,j=0;
    set *temp;
    temp=A;
    set val=*temp;
    temp=&val;
    for(i=0;i<B->size;i++)
    {
        if(set_check_present(temp,&B->set[i])==0)
        {
            set_insert(temp,&B->set[i]);
        }
    }

    return(temp);
}

set *set_intersection(set *A,set *B) //A intersection B
{
    set Int;
    set *val;
    val=&Int;
    set_init(&Int);
    int i=0;
    for(i=0;i<A->size;i++)
    {
        if(set_check_present(B,&A->set[i])==1)
        {
            set_insert(&Int,&A->set[i]);
        }
    }

    return(val);
}

set *set_minus(set *A,set *B) //A-B
{
    set Int;
    set *val;
    val=&Int;
    set_init(&Int);
    int i=0;
    for(i=0;i<A->size;i++)
    {
        if(set_check_present(B,&A->set[i])==0)
        {
            set_insert(&Int,&A->set[i]);
        }
    }

    return(val);
}

set *set_delta(set *A,set *B) //Symmetric differnce of A and B
{
    set AB=*set_minus(A,B);
    set BA=*set_minus(B,A);
    return(set_union(&AB,&BA));
}


void set_disp(set *A) //Display out the set
{
    int i;
    printf("{");
    for(i=0;i<(A->size);i++)
    {
        if(A->size==0)
        {
            printf("or \u03D5");
            break;
        }
        printf(" %s",&A->set[i]);
        if(i!=A->size-1)
        {
            printf(",");
        }
    }
    printf("}\n");


}
void menu(set *A,set *B) //MAIN MENU
{
    char c=NULL;
    system("clear");
    printf("\nWelcome to basic set operations program");
    printf("\nA=");
    printf(ANSI_COLOR_GREEN);
    set_disp(A);
    printf(ANSI_COLOR_RESET);
    printf("\nB=");
    printf(ANSI_COLOR_BLUE);
    set_disp(B);
    printf(ANSI_COLOR_RED);
    printf("\n================Main Menu==============");
    printf("\nOption         Description             ");
    printf(ANSI_COLOR_GREEN);
    printf("\n---------------------------------------");
    printf(ANSI_COLOR_RED);
    printf("\n1               A \u222A B              ");
    printf("\n2               A \u2229 B              ");
    printf("\n3               A - B              ");
    printf("\n4               B - A              ");
    printf("\n5               A \u0394 B              ");
    printf("\n6             New A and B              ");
    printf("\n7               EXIT                ");
    printf(ANSI_COLOR_GREEN);
    printf("\n---------------------------------------");
    printf(ANSI_COLOR_RESET);
    printf("\n\nEnter an option :");
    scanf(" %c",&c);
    printf("%c",c);
    if(c=='1')
    {   printf("\nOption 1 selected.\n");
        printf("A \u222A B:\n");
        printf("\nR=");
        printf(ANSI_COLOR_RED);
        set_disp(set_union(A,B));
        printf(ANSI_COLOR_RESET);
        printf("Press Enter to continue....");
        getchar();
        getchar();
        menu(A,B);
    }
    else if(c=='2')
    {
        printf("\nOption 2 selected.\n");
        printf("A \u2229 B:\n");
        printf("\nR=");
        printf(ANSI_COLOR_RED);
        set_disp(set_intersection(A,B));
        printf(ANSI_COLOR_RESET);
        printf("Press Enter to continue....");
        getchar();
        getchar();
        menu(A,B);
    }
    else if(c=='3')
    {

        printf("\nOption 3 selected.\n");
        printf("A - B:\n");
        printf("\nR=");
        printf(ANSI_COLOR_RED);
        set_disp(set_minus(A,B));
        printf(ANSI_COLOR_RESET);
        printf("Press Enter to continue....");
        getchar();
        getchar();
        menu(A,B);

    }
    else if(c=='4')
    {

        printf("\nOption 4 selected.\n");
        printf("B - A:\n");
        printf("\nR=");
        printf(ANSI_COLOR_RED);
        set_disp(set_minus(B,A));
        printf(ANSI_COLOR_RESET);
        printf("Press Enter to continue....");
        getchar();
        getchar();
        menu(A,B);

    }
    else if(c=='5')
    {

        printf("\nOption 5 selected.\n");
        printf("A \u0394 B :\n");
        printf("\nR=");
        printf(ANSI_COLOR_RED);
        set_disp(set_delta(A,B));
        printf(ANSI_COLOR_RESET);
        printf("Press Enter to continue....");
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
        printf(ANSI_COLOR_RED);
        printf("\nOption 7 selected. Exiting..");
        printf(ANSI_COLOR_RESET);
        return;
    }

    else
    {
        printf(ANSI_COLOR_RED);
        printf("\nSorry invalid option. Please try again!\n");
        printf("Press Enter to continue....");
        printf(ANSI_COLOR_RESET);
        getchar();
        getchar();
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
        printf(ANSI_COLOR_GREEN);
        printf("Enter a element in set A [/0=end]:");
        printf(ANSI_COLOR_RESET);
        scanf("%s",buff);
        if(!strcmp(buff,"/0"))
            break;
        set_insert(&A, buff);
    }
    printf("A=");
    printf(ANSI_COLOR_GREEN);
    set_disp(&A);
    printf(ANSI_COLOR_RESET);
    set_init(&B);
    while(1)
    {
        printf(ANSI_COLOR_BLUE);
        printf("Enter a element in set B [/0=end]:");
        printf(ANSI_COLOR_RESET);
        scanf("%s",buff);
        if(!strcmp(buff,"/0"))
            break;
        set_insert(&B, buff);
    }
    printf("B=");
    printf(ANSI_COLOR_BLUE);
    set_disp(&B);
    printf(ANSI_COLOR_RESET);
    printf("Press any key to continue....");
    getchar();
    getchar();
    menu(&A,&B);
}
