#include<stdio.h>
#include<malloc.h>
/*Copyright (C) 2017 Abhiram Shibu*/
/*Create a Matrix and perform the following operations on it : 1. Exchange the Diagonals 2. Find Determinant 3. Find Rank of the Matrix*/
/* matrix as a structure */
typedef struct matrix{
    int rows;
    int cols;
    int *a[30];
}Matrix;
/* Linked list execution state buffer(stack) */
typedef struct listNode{
	Matrix * A;                 
    int status;
	struct listNode *link;
}listPointer;
/* Inset into matrix  to null location*/
void insert(listPointer ** list, Matrix * A,int status){
	listPointer * temp;
	temp=malloc(sizeof(listPointer));
	temp->link=NULL;
	(*list)=temp;
	(*list)->A=A;
    (*list)->status=status;
}

/* Insert to end */
void insert_end(listPointer * head, Matrix *A, int status){
    listPointer * now=head;
    while(now->link!=NULL){
        now=now->link;
    }
    insert(&(now->link),A,status);
}

/* Print everything in it */
void printAll(listPointer ** head){
	listPointer * temp;
	temp=*head;
    void matrix_print(Matrix *A);
	while(1)
	{
		if(temp->link==NULL)
		{
			printf("Data\n");
            matrix_print(temp->A);
            printf("\nStatus:%d",temp->status);
			break;
		}
		else
		{
			printf("Data\n");
            matrix_print(temp->A);
            printf("\nStatus:%d",temp->status);
			temp=temp->link;
		}
	}
}
/* Matrix again */
/* Creates a Matrix */ 
Matrix * matrix_create(){
    Matrix *A;
    A=malloc(sizeof(Matrix));
    printf("Enter the rows, cols:");
    scanf("%d %d",&(A->rows),&(A->cols));
    printf("Allocating...\n");
    for(int i=0;i<A->rows;i++){                              //Alocating for every row size of cols
        A->a[i]=malloc(sizeof(int)*(A->cols));
    }
    printf("Allocation done\n");
    return A;
}
Matrix * matrix_create_noInp(int rows, int cols){
    Matrix *A;
    A=malloc(sizeof(Matrix));
/* I know, no allocation handeling! too lazy sorry */
    A->rows=rows;
    A->cols=cols;
    for(int i=0;i<A->rows;i++){                              //Alocating for every row size of cols
        A->a[i]=malloc(sizeof(int)*(A->cols));
    }
    return A;
}
/* Dumps everthing in matrix to user */
void matrix_print(Matrix *A){
    for(int i=0;i<A->rows;i++){
        for(int j=0;j<A->cols;j++)
            printf(" %d",A->a[i][j]);
        printf("\n");
    }
}

/* Flushes everything in matrix with 0 */
void matrix_flush(Matrix *A){
    printf("Flushing matrix...\n");
    for(int i=0;i<A->rows;i++)
        for(int j=0;j<A->cols;j++)
            A->a[i][j]=0;
}

/* Inputs everyelement from user */
void matrix_input(Matrix *A){
    for(int i=0;i<A->rows;i++)
        for(int j=0;j<A->cols;j++){
            printf("Enter row:%d cols:%d :",i,j);
            scanf("%d",&(A->a[i][j]));
        }
}

/* Exchange diagonals of a matrix */
void matrix_digonalExchange(Matrix *A){
    int temp;
    if(A->rows==A->cols){
        for(int i=0;i<(A->rows);i++){
            temp=A->a[i][i];
            A->a[i][i]=A->a[i][(A->rows-1)-i];
            A->a[i][(A->rows-1)-i]=temp;
        }
    }
    else
        printf("Not possible to exchange digonals.\n");
}

 int matrix_det(Matrix * A){
    int x=A->rows;
     if(x==1)
        return A->a[0][0];
    int detsum=0;
    Matrix * temp=matrix_create_noInp(25,25);         //Create a matrix
    for(int k=0; k<x;k++) {                           //Major fist row traverse
        int p=0, q=0;
        for(int i=0; i<x;i++) {                       //traverse row
                for(int j=0; j<x;j++) {               //traverse column
                    if(j==k || i==0) {
                        continue;
                    }
                    else {
                        if(q==x-1){
                            p++;q=0;	
                        }
                        temp->a[p][q++]=A->a[i][j];   //Finding cofactor
                    }
                }
        }
        temp->rows=x-1;
        detsum+=(k%2==0?1:-1)*A->a[0][k]*matrix_det(temp);
    }
    return detsum;
}
void swap(Matrix * A, int row1, int row2,int col)
{
    for (int i = 0; i < col; i++)
    {
        int temp = A->a[row1][i];
        A->a[row1][i] = A->a[row2][i];
        A->a[row2][i] = temp;
    }
}
int matrix_rank(Matrix * A)
{
    int n=A->rows;
    int m=A->cols;
    int rank = n;
 
    for (int row = 0; row < rank; row++)
    {
        if (A->a[row][row])
        {
           for (int col = 0; col < m; col++)
           {
               if (col != row)
               {
                 double mult = (double)A->a[col][row] / A->a[row][row];
                 for (int i = 0; i < rank; i++)
                   A->a[col][i] -= mult * A->a[row][i];
              }
           }
        }
        else
        {
            int reduce = 1;
 
            for (int i = row + 1; i < m;  i++)
            {
                if (A->a[i][row])
                {
                    swap(A, row, i, rank);
                    reduce = 0;
                    break ;
                }
            }
 
            if (reduce)
            {
                rank--;
 
                for (int i = 0; i < m; i ++)
                    A->a[i][row] = A->a[i][rank];
            }
 
            row--;
        }
 
    }
    return rank;
}

int main(){
    Matrix *A=matrix_create();
    matrix_flush(A);
    matrix_input(A);
    matrix_print(A);
    printf("\n-----------Main Menu-----------\n");
    printf("1)Exchange Diagonals\n");
    printf("2)Determinant\n");
    printf("3)Rank\n");
    printf("-------------------------------\n");
    printf("Enter the option:");
    int c;
    scanf("%d",&c);
    if(c==1){
        matrix_digonalExchange(A);
        matrix_print(A);
    }
    else if(c==2){
        int a=matrix_det(A);
        printf("\nMatrix Determinant is: ");
        printf("%d\n",a);
    }
    else if(c==3){
        printf("Rank of the matrix is: %d\n", matrix_rank(A));
    }
    else{
        main();
    }
     printf("\n");
}
