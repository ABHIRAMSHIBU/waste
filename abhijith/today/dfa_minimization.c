#include<stdio.h>
#include<stdlib.h>

struct partition{
	int count;
	int set[100];
};
void bubblesort(int *a,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i]<a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

// int combine(struct set s1,struct set s2){
//
// 	for(i)
// }

void display_array(int *a,int n){
	printf("[");
	for(int i=0;i<n;i++){
		printf("%d",a[i]);
	}
	printf("]");
}
void display_partition(int p[],int partition_count){
	for(int i=0;i<partition_count;i++){
		display_array(p[i].set,p[i].count);
	}
}

int search(int *a,int length,int element){ //returns -1 for not present and index if present
	int member=-1;
	for(int i=0;i<length;i++){
		if(a[i]==element){
			member=i;
			break;
		}
	}
	return member;
}


void read_dfa(int d[100][100],int n_states,int n_alpha){
	for(int i=0;i<n_states;i++){
		for(int j=0;j<n_alpha;j++){
			printf("delta(q%d,%d)=",i,j);
			scanf("%d",&d[i][j]);
			printf("q%d\n",d[i][j]);
		}
	}
}

void minimize_dfa(int d[100][100],int n_states,int n_alpha,struct partition p[100],int partition_count,int n_final_states,int final_states[]){
	if(partition_count==0){
		for(int i=0;i<n_final_states;i++){
			p[0].set[i]=final_states[i];
			p[0].count++;
		}
		for(int i=0;i<n_states;i++){
			if(search(p[0]))
		}
	}
	else{

	}
	return;
}
void main(){
	int n_states;
	int n_alpha;
	printf("Enter the no of states of DFA: ");
	scanf("%d",&n_states);
	printf("%d\n",n_states);

	printf("Enter the no. of input alphabets of DFA: ");
	scanf("%d",&n_alpha);
	printf("%d\n",n_alpha);

	int final_states[100];
	int n_final_states;
	printf("Enter the no. of final states: ");
	scanf("%d",&n_final_states);
	printf("%d\n",n_final_states);

	for(int i=0;i<n_final_states;i++){
		printf("Enter the %dth final_state : ",i);
		scanf("%d",final_states+i);
		printf("%d\n",final_states[i]);
	}


	int d[100][100];
	// int *d = (int*)malloc(n_states*n_alpha*sizeof(int));
	read_dfa(d,n_states,n_alpha);

	struct partition p[100];
	for(int i=0;i<100;i++){
		p[i].count=0;
	}
	int partition_count=0;

	minimize_dfa(d,n_states,n_alpha,p,partition_count,n_final_states,final_states);



}
