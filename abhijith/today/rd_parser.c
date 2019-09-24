#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct production{
	int n_rhs;
	char lhs;
	char *rhs[100];
};

void display_production(struct production p){
	printf("%c->",p.lhs);
	for(int i=0;i<p.n_rhs;i++){
		printf(" %s |",p.rhs[i]);
	}
	printf("\b");
}

void eliminate_left_recursion(struct production p){

}

void main(){

	struct production p[100];
	int production_count=0;
	while(1){
		char lhs;
		printf("Enter the lhs of the production : ");
		scanf("%c",&lhs);
		getchar();
		int n_rhs;
		printf("Enter the no. of rhs for lhs %c : ",lhs);
		scanf("%d",&n_rhs);
		getchar();
		p[production_count].n_rhs=n_rhs;
		p[production_count].lhs=lhs;
		for(int i=0;i<n_rhs;i++){
			p[production_count].rhs[i] = (char*)malloc(100*sizeof(char));
			printf("Enter the %dth rhs of the production for lhs %c : ",i,lhs);
			gets(p[production_count].rhs[i]);

		}
		production_count++;
		int choice;
		printf("Enter -1 to quit: ");
		scanf("%d",&choice);
		if(choice==-1){
			break;
		}

	}
	printf("\n");
	for(int i=0;i<production_count;i++){
		display_production(p[i]);
		printf("\n");
	}
	return;
}
