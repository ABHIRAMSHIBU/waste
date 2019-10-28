#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct production{
	int n_rhs;
	char lhs;
	char *rhs[100];
}P;
struct array{
	int count;
	int a[100];
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
void display_char_array(char *string){
    int length = strlen(string);
    if(length==0){
        printf("[ ]");
        return;
    }
    printf("[ ");
    for(int i=0;i<strlen(string);i++){
    
        printf(" %c ,",string[i]);
    }
    printf("\b ]");
    
}

void check_concatenate(char *s1,char *s2){
    int l2=strlen(s2);
    for(int i=0;i<l2;i++){
        check_append_string(s1,s2[i]);
    }
}
void find_first(P * p, char * shmem, int production_count, int index,char *check_list){
    char initialProduction = p[index].lhs;
    for(int i=0; i<p[index].n_rhs; i++){
        char curr= p[index].rhs[i][0];
        int pos=search_production(p,production_count,curr);
        if(pos!=-1){
            if(search_string(check_list,curr)==-1){
                append_string(check_list,curr);
                find_first(p,shmem, production_count, pos,check_list);
            }
        }
        else{
            if(search_string(shmem,curr)==-1){
                append_string(shmem,curr);
            }
            
        } 
    }
//     int pos = search_string(shmem,'e');
//     if(pos!=-1){
//         for(int i=0;i<p[index].n_rhs];i++){
//             int pos_rhs = search_string(p[index].rhs[i],'e');
//             if(pos_rhs!=-1){
//                 if(pos_rhs!=strlen(p[index].rhs[i])-1){
//                     char *new_shmm;
//                     find_first(p,shmem,pos_rhs+1,index,check_list);
//                     check_concatenate(shmem,new_shmm);
//                     
//                 }
//             }
//         }
//         
//     }
}

void follow(P * p, int production_count, char ch,char *check_list,char *follow_result,char *first_result[]){
//      printf("Length of follow_result is %d\n",strlen(follow_result));

    for(int i=0;i<production_count;i++){
    
        for(int j=0;j<p[i].n_rhs;j++){
            int pos = search_string(p[i].rhs[j],ch); // search the production for the given character
            if(pos!=-1){ // The character was found in the RHS of the production
                printf("character %c was found in the production at position %d ",ch,pos);
                display_production(p[i]);
                printf("\n");
                if(pos==strlen(p[i].rhs[j])-1){ //if the next string is a null string or epsilon
//                     int first_pos = search_production(p,production_count,p[i].lhs); //find the index of the production of the lhs of the current production
                    printf("The next char is a null string and hence adding ");
                    display_char_array(first_result[i]);
                    printf(" to it \n");
                    check_concatenate(follow_result,first_result[i]);
                }
                else{ //if next char is not a null string
                    char curr = p[i].rhs[j][pos+1]; //get the next char to the right of the given char
                    printf("The next character to the right is %c\n",curr);
                    if(search_production(p,production_count,curr)!=-1){ // If curr  is a non-terminal
                        printf("next character %c is a non terminal\n",curr);
                        if(search_string(check_list,curr)==-1){ // if curr is not already seen
                            printf("We have never encountered Non terminal character %c before\n",curr);
                            check_append_string(check_list,curr);
                            follow(p,production_count,curr,check_list,follow_result,first_result);
                        }
                        
                    }
                    else{ // if curr is a terminal
                        printf("curr = %c is a terminal\n",curr);
                         check_append_string(follow_result,curr);
                         printf("Length of follow_result is %d\n",strlen(follow_result));
                    }
                    
                   
                }
            }
        }
    }
}
 
void fix_epsilon(P *p,int production_count,int production_index,char *follow_result[100]){
    P current_production = p[production_index];
    for(int i=0;i<production_count;i++){
        for(int j=0;j<p[i].n_rhs;j++){
        
            int pos = search_string(p[i].rhs[j],current_production.lhs);
            if(pos==-1){
                continue;
            }
            for(int k=0;k<=pos;k++){
            
                if(search_string(follow_result[k],'e')!=-1){
                        if(k+1 > strlen(p[i].rhs[j])-1){
                            break;
                        }
                        int prod_pos = search_production(p,production_count,p[i].rhs[i][k+1]);
                        if(prod_pos!=-1){
                            check_concatenate(follow_result[production_index],follow_result[prod_pos]);
                        }
                    
                }
            }
        }
    }
}

void fix_find_first(P * p, int production_count, char *follow_result[100]){

    for(int i=0;i<production_count;i++){
        char lhs = p[i].lhs;
        int eps_pos = search_string(follow_result[i],'e');
        if(eps_pos!=-1){
            fix_epsilon(p,production_count,i,follow_result);
        }
        
    }
}


int main(){
    int production_count;
    char full_string[100];
    P  p[100];
    read_cfg(p,&production_count,full_string);
    char *result[100];
    char *check_list;
    for(int i=0;i<production_count;i++){
        check_list= (char *)malloc(sizeof(char)*100);
        result[i]=(char *)malloc(100*sizeof(char));
        find_first(p, result[i],production_count,i,check_list);
    }

    
    
    char *follow_result[100];
    for(int i=0;i<production_count;i++){
        follow_result[i]=(char *)malloc(100*sizeof(char));
//         strcpy(follow_result[i],"");
        check_list= (char *)malloc(sizeof(char)*100);
        follow(p,production_count, p[i].lhs,check_list,follow_result[i],result);

    }
    printf("The first values are as shown below\n");
    for(int i=0;i<production_count;i++){
        printf("First(%c) = ",p[i].lhs);
        display_char_array(result[i]);
        printf("\n");
        
    }
    fix_find_first(p,production_count,follow_result);
    printf("The first values are as shown below\n");
    for(int i=0;i<production_count;i++){
        printf("First(%c) = ",p[i].lhs);
        display_char_array(result[i]);
        printf("\n");
        
    }
    printf("The follow values are as shown below\n");
    for(int i=0;i<production_count;i++){
        printf("Follow(%c) = ",p[i].lhs);
        display_char_array(follow_result[i]);
        printf("\n");

    }

}
