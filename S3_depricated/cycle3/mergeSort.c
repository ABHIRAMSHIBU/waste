#include<stdlib.h>
#include<stdio.h>

/* Merge function to merge 2 sorted arrays */
void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];

    i = 0; 
    j = 0;
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
 
 /* Call merge interatively until array is sorted */
void mergeSort(int arr[], int n)
{
   int back=1; 
   int front=0;
   while (back<=n-1)
   {
       front=0;
       while (front<n-1)
       {
           int mid = front + back - 1;
           int right = ((front + 2*back - 1) < (n-1))? (front + 2*back - 1):(n-1);
           merge(arr, front, mid, right);
           front += 2*back;
       }
        back = 2*back;
   }
}

/* Print array to user */
void printArray(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int * getArray(int n){
    int * a=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        printf("Enter element %d:",i+1);
        scanf("%d",&(a[i]));
    }
    return a;
}
int main(){
    printf("Enter the number of elements:");
    int n;
    scanf("%d",&n);
    int *a=getArray(n);
    mergeSort(a,n);
    for(int i=0;i<n;i++){
        printf("Index: %d, value: %d\n",i,a[i]);
    }
    return 0;
}
