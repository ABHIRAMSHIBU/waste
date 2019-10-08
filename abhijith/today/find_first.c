#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "advString.c"
typedef struct production{
	int n_rhs;
	char lhs;
	char *rhs[100];
}P;
struct array{
	int count;
	int a[100];
};

void display_array(int *a,int n){
	printf("[ ");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("]");
}

void display_production(struct production p){
	printf("%c->",p.lhs);
	for(int i=0;i<p.n_rhs;i++){
		printf(" %s |",p.rhs[i]);
	}
}
void read_cfg(struct production* p,int *production_count,char *full_string){
	full_string[0]='\0';
	while(1){
		char lhs;
		printf("Enter the lhs of the production : ");
		scanf("%c",&lhs);
		int length=strlen(full_string);
		printf("length is %d\n",length);
		full_string[length]=lhs;
		full_string[length+1]='\0';
		printf("%c\n",lhs);
		int n_rhs;
		printf("Enter the no. of rhs for lhs %c : ",lhs);
		scanf("%d",&n_rhs);
		printf("%d\n",n_rhs);
		p[*production_count].n_rhs=n_rhs;
		p[*production_count].lhs=lhs;
		for(int i=0;i<n_rhs;i++){
			p[*production_count].rhs[i] = (char*)malloc(100*sizeof(char));
			printf("Enter the %dth rhs of the production for lhs %c : ",i,lhs);
			scanf("%s",p[*production_count].rhs[i]);
			strcat(full_string,p[*production_count].rhs[i]);
			printf("%s\n",p[*production_count].rhs[i]);
		}
		(*production_count)+=1;
		int choice;
		printf("Enter -1 to quit: ");
		scanf("%d",&choice);
		printf("%d\n",choice);
		if(choice==-1){
			break;
		}
		scanf("%d",&choice );
	}
	printf("\n");

}
int main(){
    int production_count;
    char full_string[100];
    P  p[100];
    read_cfg(p,&production_count,full_string);
    
}
