//Program made by Abhiram Shibu and Abhijith N Raj
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int size;
    char *set[1037540];
}set;
void set_init(set *A)
{
    A->size=0;
    //A->set[A->size]=malloc(sizeof(char)*1000);
    //A->set[A->size]='\0';
}
void set_insert(set *A,char item[])
{
    (*A).set[(*A).size]=malloc(sizeof(char)*1000);
    //printf("Adding value into %d",(*A).size);
    strcpy(&A->set[A->size],item);
    (*A).size++;
}
void set_disp(set *A)
{
    int i;
    printf("\n{");
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
int main()
{
    set A;
    set_init(&A);
    set_insert(&A,"Hello ");
    set_insert(&A,"bla");
    set_insert(&A,"NOW?");
    //("Size %d, set %s",A.size,&A.set[0]);
    set_disp(&A);
}
