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


void eliminate_left_recursion_production(struct production *p,int index,char *full_string,int *production_count){
	struct array lr = find_lr(p[index]);
	for(int i=0;i<lr.count;i++){
		char *rhs = (p+index)->rhs[lr.a[i]];
		char *subs = substring(rhs,1,strlen(rhs));
		printf("Substring of %s is %s\n",rhs,subs);
		char new_char = get_subs(full_string);
		printf("New char recieved is %c\n",new_char);
		p[*production_count].lhs=new_char;
		p[*production_count].rhs[0] = subs;
        int length=strlen(subs);
		p[*production_count].rhs[0][length]=new_char;
        p[*production_count].rhs[0][length+1]='\0';
        p[*production_count].rhs[1] = malloc(5*sizeof(char));
        strcpy(p[*production_count].rhs[1],"e");
        p[*production_count].n_rhs=2;
        
        *production_count+=1;
        
		//a->al/b  =>  a->ba` ,a`->la`/e
// 		int length=strlen(subs);
// 		subs[length]=new_char;
// 		subs[length+1]='\0';
// 		printf("new subs value is %s\n",subs);
// 		p->rhs[lr.a[i]]=subs;
        char *temp = p[index].rhs[1];
        length=strlen(temp);
        temp[length]=new_char;
        temp[length+1]='\0';
        p[index].rhs[lr.a[i]]=temp;
        p[index].n_rhs--;
	}
	
	printf("No. of productions when returning is %d\n",*production_count);

}
void display_cfg(struct production *p,int production_count){
    for(int i=0;i<production_count;i++){
		display_production(p[i]);
        printf("\n");
	}
    
}

void eliminate_left_recursion_complete(struct production *p,char *full_string,int *production_count){
    int old_production_count=*production_count;
    for(int i=0;i<old_production_count;i++){
        eliminate_left_recursion_production(p,i,full_string,production_count);
        printf("The cfg after index %d is \n",i);
        display_cfg(p,*production_count);
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

int input_index=0;
int recursive_descend_parser(struct production *p,int production_number,int production_count,char *input){
    
    for(int k=0;k<p->n_rhs;k++){
        int current_string_index_pos=0;
        char current_string[100];
        strcpy(current_string,p[production_number].rhs[k]);
        int current_string_length = strlen(p[production_number].rhs[k]);
        printf("Current string under consideration is %s\n",current_string);
        for(int i=0;i<current_string_length;i++){
            printf("Now searching for %c\n",current_string[i]);
            int non_terminal=0;
            int pos=-1;
            for(int j=0;j<production_count;j++){
//                 printf("Search values cur_str %c, lhs %c\n",current_string[i],p[j].lhs);
                if(current_string[i]==p[j].lhs){
                    non_terminal=1;
                    pos=j;
                    break;
                }
                
            }
            
            if(non_terminal==1){
                printf("%c is a non-terminal and  hence expanding\n",current_string[i]);
                int retval = recursive_descend_parser(p,pos,production_count,input);
//                 if(retval==-1){
//                     break;
//                 }
//                 if(retval==1){
//                     return 1;
//                     
//                 }

            }
            else{
                printf("%c is a terminal\n",current_string[i]);
                printf("Current input under consideration is %c\n",input[input_index]);
                if(current_string[i]=='e'){
                    printf("Epsilon non terminal found simply moving to next thing\n");
                    continue;
                }
                if(current_string[i]==input[input_index]){
                        printf("match found\n");
                        if(input_index==strlen(input)-1){
                            printf("This string can be parsed here\n");
                            return 1;
                        }
                        input_index++;
                        continue;
                }
                else{
                        printf("Match not found here\n");
                        break;
                }
                
            }
            
                
        }
    }

    
    
    
}


void main(){

	struct production p[100];
	int production_count=0;
	char full_string[100];
	read_cfg(p,&production_count,full_string);
	for(int i=0;i<production_count;i++){
		display_production(p[i]);
		struct array lr = find_lr(p[i]);
		printf("Left recursion is found at indexes : \n");
		display_array(lr.a,lr.count);
		printf("\n");
	}
// 	eliminate_left_recursion(p,0,full_string,&production_count);
// 	printf("production after eliminating left recursion is\n");
    eliminate_left_recursion_complete(p,full_string,&production_count);
// 	display_cfg(p,production_count);
    recursive_descend_parser(p,0,production_count,"i+i*i");
    
	// printf("Full string is %s\n",full_string);

	// char string[]="abhijith";
	// char *output =substring(string,1,4);
	// printf("\nsubstring is %s \n",output);
	return;
}
