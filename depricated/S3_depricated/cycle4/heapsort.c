#include <stdio.h>
#include <malloc.h>
void swap(int a[],int b[]){
    int temp=a[0];
    a[0]=b[0];
    b[0]=temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
 
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void main_depricated(){
	int a[]={1,2,3,10,9,8,7,6,5,4};
	heapSort(a,10);
	for(int i=0; i<10;i++){
		printf("%d ",a[i]);
	}
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
    heapSort    (a,n);
    for(int i=0;i<n;i++){
        printf("Index: %d, value: %d\n",i,a[i]);
    }
    return 0;
}

