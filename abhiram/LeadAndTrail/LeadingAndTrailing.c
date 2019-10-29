/*
 * LT.c
 *
 *  Created on: Oct 28, 2019
 *      Author: abhijith
 */


#include<stdio.h>
#include<string.h>

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
typedef struct production{
	int n_rhs;
	char lhs;
	char *rhs[100];
}P;

#define LIMIT 6
#define True 1
#define False 0
typedef struct {
	int a[LIMIT][LIMIT];
	int limit ;
	char h[100];
} optable;
struct array{
	int count;
	int a[100];
};
struct stack{
	int a[100];
	int top;
};
struct char_array{
    int count;
    char a[100];
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
void display_cfg(struct production *p,int production_count){
    for(int i=0;i<production_count;i++){
		display_production(p[i]);
        printf("\n");
	}

}
int search_production(P *p,int production_count,char lhs){
    int pos=-1;
    for(int j=0;j<production_count;j++){
            if(p[j].lhs==lhs){
                pos=j;
                break;
            }
        }
    return pos;
}
void read_cfg(struct production* p,struct production* rev_p,int *production_count,char *full_string){
	full_string[0]='\0';
	while(1){
		char lhs;
		char buff[10];
		printf("Enter the lhs of the production : ");
		scanf("%s",buff);
		lhs=buff[0];
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
		rev_p[*production_count].n_rhs=n_rhs;
		rev_p[*production_count].lhs=lhs;
		for(int i=0;i<n_rhs;i++){
			p[*production_count].rhs[i] = (char*)malloc(100*sizeof(char));
			rev_p[*production_count].rhs[i] = (char*)malloc(100*sizeof(char));
			printf("Enter the %dth rhs of the production for lhs %c : ",i,lhs);
			scanf("%s",p[*production_count].rhs[i]);
			strcpy(rev_p[*production_count].rhs[i],p[*production_count].rhs[i]);
			strrev(rev_p[*production_count].rhs[i]);
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
void append_string(char *string,char ch){
    int length=strlen(string);
    string[length]=ch;
    string[length+1]='\0';
}
int search_string(char *string,char item){
    int pos=-1;
    for(int i=0;i<strlen(string);i++){
        if(string[i]==item){
            pos=i;
            break;
        }
    }
    return pos;
}
void display_char_array(char *string){
    int length = strlen(string);
    if(length==0){
        printf("[ ]");
        return;
    }
    printf("[ ");
    int i;
    for(i=0;i<strlen(string)-1;i++){

        printf(" %c ,",string[i]);
    }
    printf("%c ]",string[i]);

}
void Leading(struct production *p,int production_count,int production_index,char *leading,char *completed){
	//production_index will point to the Production which we are finding Leading(p->lhs) for
	struct production curr_prod = *(p+production_index);
	//printf("Finding the Leading(%c)\n",curr_prod.lhs);
	if(search_string(completed,curr_prod.lhs)!=-1){
//		printf("This Non terminal character %c has already been considered hence returning \n",curr_prod.lhs);
		return;
	}
	else{
//		printf("Add %c to completed list\n",curr_prod.lhs);
		append_string(completed,curr_prod.lhs);
	}
	for(int i=0;i<curr_prod.n_rhs;i++){
//		printf("Now considering the rhs part %s\n",curr_prod.rhs[i]);
		if(search_production(p, production_count, curr_prod.rhs[i][0])==-1){
//			printf("First character %c is a terminal and adding to Leading(%c)\n",curr_prod.rhs[i][0],curr_prod.lhs);
			append_string(leading,curr_prod.rhs[i][0]);
		}
		else if(strlen(curr_prod.rhs[i])==1){
//			printf("rhs length is only one\n");
			int new_index = search_production(p, production_count, curr_prod.rhs[i][0]);
			if(new_index!=-1){
//				printf("First character %c is a calling Leading(%c)\n",curr_prod.rhs[i][0],curr_prod.rhs[i][0]);
				Leading(p, production_count,new_index, leading, completed);
			}
		}
		else {
			int pos1 = search_production(p, production_count, curr_prod.rhs[i][0]);
			int pos2 = search_production(p, production_count, curr_prod.rhs[i][1]);
			if(pos1!=-1 && pos2==-1){
//				printf("Second character %c is a terminal and adding to Leading(%c)\n",curr_prod.rhs[i][1],curr_prod.lhs);
				append_string(leading,curr_prod.rhs[i][1]);
//				printf("First character %c is a Non Terminal and finding Leading(%c)\n",curr_prod.rhs[i][0],curr_prod.rhs[i][0]);
				Leading(p, production_count,pos1, leading, completed);

			}


		}

	}
}
void construct_parse_table(optable *t,char leading[][100],char trailing[][100],struct production *p,int production_count){

	//$<lead(S)
	int dollar_pos = search_string(t->h, '$');
	for(int i=0;i<strlen(leading[0]);i++){
		char lead_char = leading[0][i];
		int lead_char_pos = search_string(t->h,lead_char);
		t->a[dollar_pos][lead_char_pos]='<';
	}
	//trail(S)>$
	for(int i=0;i<strlen(trailing[0]);i++){
		char trail_char = trailing[0][i];
		int trail_char_pos = search_string(t->h,trail_char);
		t->a[trail_char_pos][dollar_pos]='>';
	}

	for(int i=0;i<production_count;i++){
//		printf("Now considering production ");
		display_production(p[i]);
		printf("\n");
		for(int j=0;j<p[i].n_rhs;j++){
			char *curr_str = p[i].rhs[j];
//			printf("current rhs is %s\n",curr_str);
			for(int k=0;k<strlen(curr_str);k++){
//				printf("Now considering character %c \n",curr_str[k]);
				int pos  = search_production(p, production_count, curr_str[k]);
				if(pos==-1){
//					printf("The character %c is a terminal\n",curr_str[k]);
					if(k+1<strlen(curr_str) && search_production(p, production_count, curr_str[k+1])==-1){
//						printf("Found immediate neighbor %c which is a terminal\n",curr_str[k+1]);
						int pos1 = search_string(t->h,curr_str[k]);
						int pos2 = search_string(t->h,curr_str[k+1]);
						t->a[pos1][pos2]='=';
						t->a[pos2][pos1]='=';
					}
					if(k+1<strlen(curr_str) && search_production(p, production_count, curr_str[k+1])!=-1){
						int term2 = search_production(p, production_count, curr_str[k+1]);
						int pos1 = search_string(t->h,curr_str[k]);
						for(int l=0;l<strlen(leading[term2]);l++){
							int pos2 = search_string(t->h,leading[term2][l]);
							t->a[pos1][pos2]='<';
						}
					}
					if(k+2<strlen(curr_str)){
						int term2 = search_production(p, production_count, curr_str[k+1]);
						int term3 =  search_production(p, production_count, curr_str[k+3]);
						if(term2!=-1 && term3==-1){
							int pos1 = search_string(t->h,curr_str[k]);
							int pos2 = search_string(t->h,curr_str[k+2]);
							t->a[pos1][pos2]='=';
						}
					}
					if(k-1>=0){
						int prev_term = search_production(p, production_count, curr_str[k-1]);
						if(prev_term!=-1){
							for(int l=0;l<strlen(trailing[prev_term]);l++){
								int pos1 = search_string(t->h,trailing[prev_term][l]);
								int pos2 = search_string(t->h,curr_str[k]);
								t->a[pos1][pos2]='>';
							}
						}
					}
				}
			}
		}
	}

}
void display_table(optable t){
	int limit = t.limit;
	_Bool start=True;
	for(int i =0;i<limit;i++){
		if(start==True){
			printf("\t");
			for(int j=0;j<limit;j++){
				printf("%c\t",t.h[j]);
			}
			printf("\n\n");
			start=False;
		}
		printf("%c\t",t.h[i]);
		for(int j=0;j<limit;j++){
			if(t.a[i][j]!='\0' && t.a[i][j]!='\1'){
				printf("%c\t",t.a[i][j]);
			}
			else{
				if(t.a[i][j]=='\0')
					printf("e\t",t.a[i][j]);
				else if(t.a[i][j]=='\1')
					printf("a\t",t.a[i][j]);
			}
		}
		printf("\n\n");
	}
}
void push(struct stack *s,char item){
	if(s->top==-1){
		s->top=0;
	}
	s->a[s->top]=item;
	s->top=s->top+1;
}

char pop(struct stack *s){
	if(s->top==-1){
		printf("stack underflow\n");
		return 'z';
	}
	else{
		char item = s->a[s->top];
		s->top = s->top-1;
		return item;
	}

}
int getPosition(optable t, char c){
	int pos = -1;
	for(int i =0;i<t.limit;i++){
		if(t.h[i]==c){
			pos=i;
			break;
		}
	}
	return pos;
}

int getPrecidence(optable t,char s,char ipt){
	int spos=getPosition(t,s);
	int iptpos=getPosition(t,ipt);
	int val=-1;
	if(spos!=-1 && iptpos!=-1){
		val = t.a[spos][iptpos];
	}
	return val;
}
int main(){
	int production_count;
	char full_string[100];
	P  p[100];
	P rev_p[100];
	read_cfg(p,rev_p,&production_count,full_string);




//	printf("The CFG read is \n");
//	display_cfg(p, production_count);
//	printf("The reversed CFG is \n");
//	display_cfg(rev_p, production_count);
	printf("\n");

	//Main code for finding leading
	char leading[100][100];
	for(int i=0;i<production_count;i++){
//		printf("-------------Iteration%d--------------\n",i);
		strcpy(leading[i],"");
		char completed[100]="";
		Leading(p, production_count, i, &leading[i], completed);
	}
//	printf("\n----LEADING---\n");
//	for(int i=0;i<production_count;i++){
//		printf("Leading(%c) is ",(p+i)->lhs);
//		display_char_array(leading[i]);
//		printf("\n");
//	}



	//Main code for finding Trailing
	char trailing[100][100];
	for(int i=0;i<production_count;i++){
//		printf("-------------Iteration%d--------------\n",i);
		strcpy(trailing[i],"");
		char completed[100]="";
		Leading(rev_p, production_count, i, &trailing[i], completed);
	}
//	printf("\n----TRAILING---\n");
//	for(int i=0;i<production_count;i++){
//		printf("Trailing(%c) is ",(p+i)->lhs);
//		display_char_array(trailing[i]);
//		printf("\n");
//	}
	printf("Enter the terminals as a string\n");
	char terminals[20];
	scanf("%s",terminals);
	append_string(terminals,'$');
	printf("The terminals are\n");
	display_char_array(terminals);
	optable t;
	strcpy(t.h,terminals);
	t.limit=strlen(terminals);
	construct_parse_table(&t, leading, trailing, p, production_count);
	printf("The table is \n");
	display_table(t);

//	struct stack s ;
//	s.top=-1;
//	push(&s,'$');
//	parse(t, s, "id+");







}
