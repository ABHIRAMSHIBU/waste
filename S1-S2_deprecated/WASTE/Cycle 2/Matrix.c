#include<stdio.h>
#include<stdlib.h>
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
            printf("%d      ",*(mat+count));
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
            printf("Enter row %d, element %d:",i+1,j+1);
            scanf("%d",(mat+count));
            count++;
        }
    }
}
int *add_mat(int *mat1,int *mat2, int x,int y)
{
	int i,j,*mat_res;
	mat_res=(int*)malloc(sizeof(int)*x*y);
	for(i=0;i<x*y;i++)
	{
		*(mat_res+i)=*(mat1+i)+*(mat2+i);
	}
	return mat_res;
}
void mat_sum()
{
    int *mat1,*mat2,row,col,*matsum;
	printf("Enter rows and cols rows <space> cols :");
	scanf("%d %d",&row,&col);
	mat1=make_mat(row,col);
	mat2=make_mat(row,col);
	accept_elements(mat1,row,col);
	print_mat(mat1,row,col);
	accept_elements(mat2,row,col);
	print_mat(mat2,row,col);
	printf("-------Sum of matrix---------\n");
	matsum=add_mat(mat1,mat2,row,col);
	print_mat(matsum,row,col);
}
void mat_mult()
{
    int *mat1,*mat2,row,col,*matmult,i,j,k,count=0;
	printf("Enter rows and cols rows <space> cols :");
	scanf("%d %d",&row,&col);
	mat1=make_mat(row,col);
	mat2=make_mat(row,col);
	accept_elements(mat1,row,col);
	print_mat(mat1,row,col);
	accept_elements(mat2,row,col);
	print_mat(mat2,row,col);
	matmult=make_mat(row,col);
	k=0;
	for(i=0;i<row*col;i+row)
    {
        for(j=0;j<col;j++)
        {
            *(matmult+k)=*(matmult+k)+(*(mat1+i+j)*(*(mat2+(j*row))));
            k++;
        }
    }
    print_mat(matmult,row,col);
}
void main()
{
    mat_mult();
	//int *mat,x,y,i,j;
	//printf("Enter the rows and cols :");
	//scanf("%d %d",&x,&y);
	//mat=make_mat(x,y);
	//accept_elements(mat,x,y);

	/*while(1)
    {
        printf("Enter params :");
        scanf("%d %d",&i,&j);
        print_mat(mat,x,y);
        printf("%d \n",mat[i]);
    }*/
}
