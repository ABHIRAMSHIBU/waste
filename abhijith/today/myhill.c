#include<stdio.h>

struct set{
	int count;
	int e[100];
};

void read_dfa(int d[100][100],int n_states,int n_alpha){
	for(int i=0;i<n_states;i++){
		for(int j=0;j<n_alpha;j++){
			printf("delta(q%d,%d)=",i,j);
			scanf("%d",&d[i][j]);
			printf("q%d\n",d[i][j]);
		}
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

void max_adjust(int *x,int *y){
	if(*x<*y){
		int temp=*x;
		*x=*y;
		*y=temp;
	}
}

void display_matrix(int a[100][100],int r,int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(i>j)
				printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

int check_intersection(struct set s1,struct set s2){
	int intersection=0;
	for(int i=0;i<s1.count;i++){
		for(int j=0;j<s2.count;j++){
			if(s1.e[i]==s2.e[j]){
				intersection=1;
				break;
			}
		}
	}
	return intersection;
}

struct set combine_sets(struct set s1,struct set s2){
	for(int i=0;i<s2.count;i++){
		if(search(s1.e,s1.count,s2.e[i])==-1){
			s1.e[s1.count]=s2.e[i];
			s1.count++;
		}
	}
	return s1;
}
void display_array(int *a,int n){
	printf("[");
	for(int i=0;i<n;i++){
		printf("%d,",a[i]);
	}
	printf("\b");
	printf("]");
}

void minimize_dfa(int d[100][100],int n_states,int n_alpha,int n_final_states,int final_states[],int m[100][100]){
		for(int i=0;i<n_states;i++){
			for(int j=0;j<n_states;j++){
				if(i>j){
					int k1=search(final_states,n_final_states,i);
					int k2=search(final_states,n_final_states,j);
					if((k1!=-1 && k2==-1)||(k2!=-1 &&k1==-1)){
						printf("Marked index %d and %d\n",i,j);
						m[i][j]=1;
					}
				}
			}
		}
		printf("Completed the first stage with final states\n");
		display_matrix(m,n_states,n_states);
		printf("\n");
		while(1){
			int changed=0;
			for(int i=0;i<n_states;i++){
				for(int j=0;j<n_states;j++){
					if(i>j && m[i][j]!=1){
						printf("Considering unchecked pair %d and %d\n",i,j);
						for(int k=0;k<n_alpha;k++){
							int k1=d[i][k];
							int k2=d[j][k];
							max_adjust(&k1,&k2);
							printf("Pairs resulted in states %d and %d for input %d\n",k1,k2,k);
							if(m[k1][k2]==1){
								m[i][j]=1;
								changed=1;
								printf("Marked pair %d and %d\n",i,j);
							}
						}
					}
				}
			}
			if(!changed){
				printf("Completed filling the table as shown below\n");
				display_matrix(m,n_states,n_states);
				break;
			}
		}
		struct set s[100];
		int state_count=0;
		for(int i=0;i<n_states;i++){
			for(int j=0;j<n_states;j++){
				if(i>j && m[i][j]!=1){
					s[state_count].e[0]=i;
					s[state_count].e[1]=j;
					s[state_count].count=2;
					state_count++;
				}
			}
		}
		while(1){
			for(int i=0;i<state_count;i++){
				for(int j=0;j<state_count;j++){
					if(i==j)
						continue;
					// printf("Checking intersection for ");
					// display_array(s[i].e,s[i].count);
					// printf("\t");
					// display_array(s[j].e,s[j].count);
					// printf("\n");
					if(check_intersection(s[i],s[j])){
						int large=i;
						int small=j;
						max_adjust(&large,&small);
						s[small]=combine_sets(s[i],s[j]);
						for(int k=large;k<state_count;k++){
							s[k]=s[k+1];
						}
						state_count--;
						continue;
					}
				}
			}

			break;
		}

		// printf("The no of states at the end are %d\n",state_count);
		// printf("Printing the combined states \n");
		// for(int i=0;i<state_count;i++){
		// 	display_array(s[i].e,s[i].count);
		// 	printf("\n");
		// }

		for(int i=0;i<n_states;i++){
			int found=0;
			for(int j=0;j<state_count;j++){
				if(search(s[j].e,s[j].count,i)!=-1){
					found=1;
					break;
				}
			}
			if(found==0){
				s[state_count].e[0]=i;
				s[state_count].count=1;
				state_count++;
			}
		}

		printf("The no of states of the minized dfa are  %d\n",state_count);
		printf("The minimized states of dfa are \n");
		for(int i=0;i<state_count;i++){
			display_array(s[i].e,s[i].count);
			printf("\n");
		}

		// for(int i=0;i<state_count;i++){
		// 	int state[100];
		// 	int state_array_count=0;
		// 	for(int j=0;j<s[i].count;j++){
		// 		for(int k=0;k<n_alpha;k++){
		// 			int item = d[s[i].e[j]][k];
		// 			if(search(state,state_count,item)==-1){
		// 				state[state_count]=item;
		// 				state_array_count++;
		// 			}
		// 		}
		//
		// 	}
		// 	printf("The state ");
		// 	display_array(s[i].e,s[i].count);
		// 	printf(" on input %d goes to state",);
		// 	display_array(state,state_array_count);
		// 	printf("\n");
		// }

		for(int i=0;i<state_count;i++){
			for(int j=0;j<n_alpha;j++){
				int state[100];
				int state_array_count=0;
				for(int k=0;k<s[i].count;k++){
					int item = d[s[i].e[k]][j];
					// printf("For item, set %d,state %d on input %d goes to %d\n",i,s[i].e[k],j,item);
					if(search(state,state_array_count,item)==-1){
						state[state_array_count]=item;
						state_array_count++;
					}
				}
				for(int l=0;l<state_count;l++){
					if(state_array_count==0){
						printf("Some error has occured here\n");
					}
					else{
						int single_element = state[0];
						if(search(s[l].e,s[l].count,single_element)!=-1){
							printf("The state ");
							display_array(s[i].e,s[i].count);
							printf(" on input %d goes to state ",j);
							display_array(s[l].e,s[l].count);
							printf("\n");

						}

					}
				}

			}

		}



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


	int partition_count=0;

	int m[n_states][n_states];
	for(int i=0;i<n_states;i++){
		for(int j=0;j<n_states;j++){
			m[i][j]=0;
		}
	}

	minimize_dfa(d,n_states,n_alpha,n_final_states,final_states,m);



}
