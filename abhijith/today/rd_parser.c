#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct production{
	int n_rhs;
	char lhs;
	char *rhs[100];
};
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
char *substring(char *a,int index1,int index2){
	int length=strlen(a);
	char *ch = (char*) malloc(sizeof(char)*length);
	for(int i=index1;i<index2;i++){
			ch[i-index1]=a[i];
	}
	ch[index2-index1]='\0';
	return ch;
}
struct array find_lr(struct production p){
	struct array lr;
	lr.count=0;
	for(int i=0;i<p.n_rhs;i++){
		if(p.rhs[i][0]==p.lhs){
			lr.a[lr.count]=i;
			lr.count++;
		}
	}
 return lr;
}
char get_subs(char *full_string){
	for(char i='A';i<='Z';i++){
		if(index(full_string,i)==NULL){
			int length=strlen(full_string);
			full_string[length]=i;
			full_string[length+1]='\0';
			return i;
		}
	}
}


void eliminate_left_recursion(struct production *p,char *full_string){
	struct array lr = find_lr(*p);
	for(int i=0;i<lr.count;i++){
		char *rhs = p->rhs[lr.a[i]];
		char *subs = substring(rhs,1,strlen(rhs));
		printf("Substring of %s is %s",rhs,subs);
		char new_char = get_subs(full_string);
		printf("New char recieved is %c",new_char);
		int length=strlen(subs);
		subs[length]=new_char;
		subs[length+1]='\0';
		printf("new subs value is %s\n",subs);
		p->rhs[lr.a[i]]=subs;
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

void main(){

	struct production p[100];
	int production_count=0;
	char full_string[100];
	read_cfg(p,&production_count,full_string);
	for(int i=0;i<production_count;i++){
		display_production(p[i]);
		struct array lr = find_lr(p[i]);
		printf("Left recursion is found at indexes : ");
		display_array(lr.a,lr.count);
		printf("\n");
	}
	eliminate_left_recursion(&p[0],full_string);
	printf("production after eliminating left recursion is\n");
	display_production(p[0]);
	// printf("Full string is %s\n",full_string);

	// char string[]="abhijith";
	// char *output =substring(string,1,4);
	// printf("\nsubstring is %s \n",output);
	return;
}
