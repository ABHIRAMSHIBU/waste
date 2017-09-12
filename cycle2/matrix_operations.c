#include<stdio.h>
#include<malloc.h>
/*Create a Matrix and perform the following operations on it : 1. Exchange the Diagonals 2. Find Determinant 3. Find Rank of the Matrix*/
/* matrix as a structure */
typedef struct matrix{
    int rows;
    int cols;
    int *a[30];
}Matrix;

/* Creates a Matrix */ 
Matrix * matrix_create(){
    Matrix *A;
    A=malloc(sizeof(Matrix));
    printf("Enter thr rows, cols:");
    scanf("%d %d",&(A->rows),&(A->cols));
    printf("Allocating...\n");
    for(int i=0;i<A->rows;i++){                              //Alocating for every row size of cols
        A->a[i]=malloc(sizeof(int)*(A->cols));
    }
    printf("Allocation done\n");
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
int main(){
    Matrix *A=matrix_create();
    matrix_flush(A);
    matrix_print(A);
    matrix_input(A);
    matrix_print(A);
    printf("\n");
    matrix_digonalExchange(A);
    matrix_print(A);
}
