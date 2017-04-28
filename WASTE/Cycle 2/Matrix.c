#include<stdio.h>
int *make_mat(int x,int y)
{
    int *mat;
    mat=(int*)malloc(sizeof(int)*x*y);
    for(int i=0;i<x*y;i++)
    {
        *(mat+i)=0;
    }
    return mat;
}
void print_mat(int *mat,int x,int y)
{
    int count=0;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            printf("%d ",*(mat+count));
            count++;
        }
        printf("\n");
    }
}
void main()
{
    int *mat=make_mat(5,6);
    print_mat(mat,5,6);
}
