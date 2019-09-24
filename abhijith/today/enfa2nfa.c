#include<stdio.h>
#include<malloc.h>
struct transition {
	int count;
	int *states;
};

struct NFASTATE {
	struct transition *transition;
};

struct EPSILON_STRUCT{
	int count;
	int *sl;
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
void display_array(int *a,int n){
	printf("[ ");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("]");
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

struct EPSILON_STRUCT* epsilon_closure(struct NFASTATE *N,int n,int n_alpha,int state_input,struct EPSILON_STRUCT *eps){
	if(eps==NULL){
		eps = (struct EPSILON_STRUCT*) malloc(sizeof(struct EPSILON_STRUCT));
		eps->count = 0;
		eps->sl = (int*) malloc(n*sizeof(int));
	}
	eps->sl[eps->count]=state_input;
	eps->count++;
	if(N[state_input].transition[0].count!=0){
		for(int i=0;i<N[state_input].transition[0].count;i++){
			int next_state = N[state_input].transition[0].states[i];
			int already_checked=0;
			for(int j=0;j<eps->count;j++){
				if(eps->sl[j]==next_state){
					already_checked=1;
					break;
				}
			}
			if(already_checked==0){
				epsilon_closure(N,n,n_alpha,next_state,eps);
			}

		}
	}
	bubblesort(eps->sl,eps->count);
	return eps;

}


void enfa2nfa(struct NFASTATE* N,int n,int n_alpha,int *final_states,int n_final_states){
	struct EPSILON_STRUCT  *ecl;
	for(int i=0;i<n;i++){
		ecl=epsilon_closure(N,n,n_alpha,i,NULL);
		printf("NFA state %d is ",i);
		display_array(ecl->sl,ecl->count);
		printf("\n");
		if(i==0){
			printf("This is the intial state\n");
		}
		int f=0;
		for(int j=0;j<n_final_states;j++){
			if(search(ecl->sl,ecl->count,final_states[j])!=-1){
				f=1;
				break;
			}
		}
		if(f==1){
			printf("This is a final state\n");
		}
		for(int j=1;j<n_alpha;j++){
			int new_sl[100];
			int new_sl_count=0;
			for(int k=0;k<ecl->count;k++ ){
				for(int l=0;l<N[ecl->sl[k]].transition[j].count;l++){
					int item=N[ecl->sl[k]].transition[j].states[l];
					if(search(new_sl,new_sl_count,item)==-1){
						new_sl[new_sl_count]=ecl->sl[k];
						new_sl_count++;
					}

				}
			}
			printf("For input %d the intermediate output is ",j);
			display_array(new_sl,new_sl_count);
			printf("\n");

			int result[100];
			int result_count=0;
			for(int k=0;k<new_sl_count;k++){
				struct EPSILON_STRUCT *e = epsilon_closure(N,n,n_alpha,new_sl[k],NULL);
				for(int l=0;l<e->count;l++){
					if(search(result,result_count,e->sl[l])==-1){
						result[result_count]=e->sl[l];
						result_count++;
					}
				}
			}
			printf("For input %d the  the state %d goes to is ",j,i);
			display_array(result,result_count);
			printf("\n");
		}
	printf("\n\n");

	}

}

void *read_nfa(struct NFASTATE *N,int n,int n_alpha,int *final_states,int n_final_states){

		for(int i=0;i<n;i++){
			N[i].transition = (struct transition*) malloc(n_alpha*sizeof(struct transition));
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n_alpha;j++){
				int n_transitions;
				printf("Enter the no. of transitions from state %d for input %d :",i,j);
				scanf("%d",&n_transitions);
				printf("%d\n",n_transitions);
				N[i].transition[j].count=n_transitions;

				if(n_transitions!=0)
					N[i].transition[j].states = (int *)malloc(n_transitions * sizeof(int));

				for(int k=0;k<n_transitions;k++){
					printf("Enter the %dth transition from state %d for input %d: ",k,i,j);
					scanf("%d",&N[i].transition[j].states[k]);
					printf("%d\n",N[i].transition[j].states[k]);
				}

			}
		}


		for(int i=0;i<n_final_states;i++){
			printf("Enter the %dth final state: ",i);
			scanf("%d",final_states+i);
			printf("%d\n",final_states[i]);
		}
		printf("All the final states are ");
		display_array(final_states,n_final_states);
		printf("\n");


}


void main(){
	int n;
	printf("Enter the no. of states in NFA\n");
	scanf("%d",&n);
	printf("%d\n",n);

	struct NFASTATE *N;
	N = (struct NFASTATE*)malloc(n*sizeof(struct NFASTATE));

	int n_alpha;
	printf("Enter the no. of input alphabets\n");
	scanf("%d",&n_alpha);
	printf("%d\n",n_alpha);

	int *final_states;
	int n_final_states;
	printf("Enter the no. of final states\n");
	scanf("%d",&n_final_states);
	printf("%d\n",n_final_states);
	final_states = (int*)malloc(n_final_states*sizeof(int));

	read_nfa(N,n,n_alpha,final_states,n_final_states);
	printf("All the final states are in main");
	display_array(final_states,n_final_states);
	printf("\n");

	enfa2nfa(N,n,n_alpha,final_states,n_final_states);

}
