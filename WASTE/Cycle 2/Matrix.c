#include<stdio.h>
int *make_mat(int x,int y)
{
    int i;
    int *mat;
    mat=(int*)malloc(sizeof(int)*x*y);
    for(i=0;i<x*y;i++)
    {
        *(mat+i)=0;
    }
    return mat;
}
void print_mat(int *mat,int x,int y)
{
    int count=0;
    int i,j;
    for(i=0;i<x;i++)
    {
        for(j=0;j<y;j++)
        {
            printf("%d ",*(mat+count));
            count++;
        }
        printf("\n");
    }
}
void accept_elements(int *mat,int x,int y)
{
    int i,j,count=0;
    for(i=0;i<x;i++)
    {
        for (j=0;j<y;j++)
        {
            printf("Enter row %d, element %d:",i,j);
            scanf("%d",(mat+count));
            count++;
        }
    }
}
void main()
{
    int *mat=make_mat(2,3);
    accept_elements(mat,2,3);
    print_mat(mat,2,3);
}
