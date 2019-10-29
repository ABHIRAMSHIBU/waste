/*
 * ShiftReduce.c
 *
 *  Created on: 29-Oct-2019
 *      Author: students
 */

#include<stdio.h>
#include "cfg.h"
#include "stack.h"

#define true 1
#define false 0
#define True true
#define False false



int checkReduce(struct production *p,int production_count,char * str){
	int reduce = -1;
	for(int i=0;i<production_count;i++){
		for(int j=0;j<p[i].n_rhs;j++){
			if(strcmp(p[i].rhs[j],str)==0){
				reduce=i;
				break;
			}
		}
		if(reduce!=-1){
			break;
		}
	}
	return reduce;
}
int parse(struct production *p,int production_count,char *input){
	char stack[100];
	append_string(stack,input[0]);
	int input_index=0;
	char *old=malloc(100);
	while(true){
		int stack_length = strlen(stack);
		strcpy(old,stack);
		printf("stack length is %d\n",stack_length);
		for(int i=0;i<stack_length;i++){
			int breakflag=0;
			for(int j=i;j<=stack_length;j++){
				printf("input to substring(%d,%d) is :",i,j);
				display_char_array(stack);
				printf("\n");
				char *subs =substring(stack,i,j) ;
				printf("substring is %s\n",subs);
				int reduce=checkReduce(p,production_count,subs);
				if(reduce!=-1){
					printf("Stack before replacing \n");
					display_char_array(stack);
					printf("\n");
					char buff[2];
					buff[0]=p[reduce].lhs;
					buff[1]=0;
					replace(stack,i,j,buff);
					printf("Stack after replacing \n");
					display_char_array(stack);
					printf("\n");
					breakflag=1;
					break;

				}
			}
			if(breakflag==1){
				break;
			}
		}
		if(strcmp(old,stack)==0){

			if(strcmp(stack,"E")==0 && input_index==strlen(input)-1){
				printf("The input string is accepted\n");
				return 1;
			}
			if(input_index==strlen(input)-1 && strcmp(stack,"E")!=0){
				printf("The input string is not accepeted\n");
				return 0;
			}
			input_index++;
			append_string(stack,input[input_index]);

		}
	}
}

int main(){
	int production_count;
	char full_string[100];
	P  p[100];
	read_cfg(p,&production_count,full_string);
	display_cfg(p,production_count);
	char input[20];
	printf("Enter the input string:");
	scanf("%s",input);
	printf("%s\n",input);
	parse(p,production_count,input);
	return 0;
}
