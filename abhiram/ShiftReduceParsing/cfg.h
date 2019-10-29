/*
 * cfg.h
 *
 *  Created on: 29-Oct-2019
 *      Author: students
 */

#ifndef CFG_H_
#define CFG_H_
typedef struct production{
	int n_rhs;
	char lhs;
	char *rhs[100];
}P;

void display_array(int *a,int n){
	printf("[ ");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("]");
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
void replace(char *a,int index1,int index2,char *b){
	int length=strlen(a)+strlen(b);
	char *ch = (char*) malloc(sizeof(char)*length);
	for(int i=0;i<index1;i++){
		append_string(ch,a[i]);
	}
	for(int i=0;i<strlen(b);i++){
		append_string(ch,b[i]);
	}
	for(int i=index2+1;i<strlen(a);i++){
		append_string(ch,a[i]);
	}
	strcpy(a,ch);
}


void display_production(struct production p){
	printf("%c->",p.lhs);
	for(int i=0;i<p.n_rhs;i++){
		printf(" %s |",p.rhs[i]);
	}
}

void display_cfg(struct production *p,int production_count){
	for(int i=0;i<production_count;i++){
		display_production(*(p+i));
	}
	printf("\n");
}
void read_cfg(struct production* p,int *production_count,char *full_string){
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

// char first[100][100];

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

void append_string(char *string,char ch){
    int length=strlen(string);
    string[length]=ch;
    string[length+1]='\0';
}

void check_append_string(char *string,char ch){
    if(search_string(string,ch)!=-1){
        printf("%c already inside %s\n",ch,string);
        return;
    }
    else{
        append_string(string,ch);
    }
}
void remove_character(char *string,char c){
	char buff[strlen(string)];
	strcpy(buff,"");
	for(int i=0;i<strlen(string);i++){
		if(string[i]!=c){
			append_string(buff, string[i]);
		}
	}
	strcpy(string,buff);
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

void check_concatenate(char *s1,char *s2){
    int l2=strlen(s2);
    for(int i=0;i<l2;i++){
        check_append_string(s1,s2[i]);
    }
}


#endif /* CFG_H_ */
