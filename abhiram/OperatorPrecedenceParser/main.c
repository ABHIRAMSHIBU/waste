/*
 * main.c
 *
 *  Created on: Oct 28, 2019
 *      Author: abhiram
 */
#include<stdio.h>
#include "stack.h"
#define LIMIT 6
#define true 1
#define false 0
#define True true
#define False false
typedef struct {
	int a[LIMIT][LIMIT];
	int limit ;
	char h[100];
} optable;
optable getInput(){
	optable t1;
	int limit=LIMIT ;
	/*
	 *\0 is e
	 *\1 is accept
	 */
	int a[LIMIT][LIMIT]={{'>','<','<','>','<','>'},
						 {'>','>','<','>','<','>'},
						 {'<','<','<','=','<','\0'},
						 {'>','>','\0','>','\0','>'},
						 {'>','>','\0','>','\0','>'},
						 {'<','<','<','\0','<','\1'}
						};
	char h[LIMIT]={'+','*','(',')','i','$'};
	t1.limit=limit;
	for(int i =0;i<limit;i++){
		t1.h[i]=h[i];
		for(int j =0;j<limit;j++){
			t1.a[i][j]=a[i][j];
		}
	}
	return t1;
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
void display(optable t){
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
					printf("rej\t");
				else if(t.a[i][j]=='\1')
					printf("acc\t");
			}
		}
		printf("\n\n");
	}
}
stack * putIntoStack(char * str){
	int length=strlen(str);
	stack * input=NULL;
	input=pushChar(input,'$');
	for(int i =length-1;i>-1;i--){
		input=pushChar(input,str[i]);
	}
	return input;
}
_Bool parser(){
	stack * mainStack=NULL;
	mainStack=pushChar(mainStack,'$');
	optable t = getInput();
	display(t);
	printf("Enter a string :");
	char buff[100];
	scanf("%s",buff);
	printf("%s\n",buff);
	stack * input = putIntoStack(buff);
	// Display Function for stack
	stack * curr=input;
	while(curr!=NULL){
		char c = traverseChar(&curr);
		printf("%c\n",c);
	}
	printf("\n");
	//End display function
	// Display Function for stack
	curr=mainStack;
	while(curr!=NULL){
		char c = traverseChar(&curr);
		printf("%c\n",c);
	}
	printf("\n");
	//End display function
	_Bool errorFlag=False;
	while(True){
		char stackTemp;
		mainStack=popChar(mainStack,&stackTemp);
		char inputTemp;
		input=popChar(input,&inputTemp);
		if(stackTemp=='$' && inputTemp=='$'){
			break;
		}
//		else if(inputTemp=='$'){
//			input=pushChar(input,inputTemp);
//		}
		else if(getPrecidence(t,stackTemp,inputTemp)=='<'){
			printf("pushing %c\n",inputTemp);
			mainStack=pushChar(mainStack,stackTemp);
			mainStack=pushChar(mainStack,inputTemp);
		}
		else if(getPrecidence(t,stackTemp,inputTemp)=='>'){
//			while(getPrecidence(t,stackTemp,inputTemp)=='>'){
//				mainStack=popChar(mainStack,&stackTemp);
//			}
//			mainStack=pushChar(mainStack,stackTemp);
//			mainStack=pushChar(mainStack,inputTemp);
//			continue;
			printf("continous popping\n");
			 while(true){
				 printf("pushing %c\n",inputTemp);
				 char stackTop;
				 mainStack=popChar(mainStack, &stackTop);
				 if(getPrecidence(t,stackTop,stackTemp)=='<'){
					 printf("Breaking pop loop\n");
					 mainStack=pushChar(mainStack,stackTop);
					 break;
				 }
			 }

		}
		else if(getPrecidence(t,stackTemp,inputTemp)=='='){
			mainStack=pushChar(mainStack,stackTemp);
			mainStack=pushChar(mainStack,inputTemp);
		}
		else if(getPrecidence(t,stackTemp,inputTemp)==0){
			errorFlag=True;
			break;
		}
		else if(getPrecidence(t,stackTemp,inputTemp)==1){ //Basically $ $
			break;
		}



		// Display Function for stack
		printf("=======================\n");
		printf("------Input Stack---\n");
			stack * curr=input;
			while(curr!=NULL){
				char c = traverseChar(&curr);
				printf("%c\n",c);
			}
			printf("\n");
			//End display function
			// Display Function for stack
		printf("-----Main Stack---\n");
			curr=mainStack;
			while(curr!=NULL){
				char c = traverseChar(&curr);
				printf("%c\n",c);
			}
			printf("\n");
			printf("----------------------\n");
			//End display function



	}
	return errorFlag;
}
int main(){
	if(parser()==true){
		printf("Error occured while parsing\n");
	}
	else{
		printf("No error detected, all good\n");
	}
	return 0 ;
}
