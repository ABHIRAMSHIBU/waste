#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int find_prime(int n){
	if(n==1){
		return 0;
	}
	int prime=1;
	for(int i=2;i<=n/2;i++){
		if(n%i==0){
			prime=-1;
			break;
		}
	}
	return prime;
}

void main(){
	int *a,n;
	int p=0,np=0;
	int pi=0,npi=0;
	printf("Enter the no of elements: ");
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
// 	for(int i=0;i<n;i++){
// 		printf("%d\n",find_prime(a[i]));
// 	}
	int pid=fork();
	if(pid==-1){
		printf("Error occurred");
	}
	else if(pid==0){
		for(int npi=0;npi<n;npi++){
                    if(a[npi]!=1 && find_prime(a[npi])==-1){
                            np+=a[npi];
                    }
		}
		printf("Sum of non prime numbers is %d\n",np);
	}
        else{
		for(int pi=0;pi<n;pi++){
                    if(a[pi]!=1 && find_prime(a[pi])==1){
                            p+=a[pi];
                    }
		}
		printf("Sum of prime numbers is %d\n",p);
	}

}
