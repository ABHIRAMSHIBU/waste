/*
 * firstandfollow.c
 *
 *  Created on: Oct 9, 2019
 *      Author: abhiram
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include "stringAdv.c"
#define true 1
#define false 0
typedef struct{
	char nonTerminals[100];
	char right[100][100];
	char left[100];
	int nonTerminalsCount;
}FIRST;
//Fast Data structure Creation
/* Structure inspired by Abhijith N Raj */
typedef struct {
	char left[100];
	char *right[100];
	int rightLimit[100];
	int maxProduction;   //Total Number of production
}cfg;

cfg getInput(){
	cfg new;
	printf("Enter maximum number of productions:");
	scanf("%d",&new.maxProduction);
	for(int i=0;i<new.maxProduction;i++){
		char buff[100];
		printf("Enter LHS for %d:",i);
		scanf("%s",buff);
		new.left[i]=buff[0];
		softErase(buff);
		printf("Enter RHS for %d:",i);
		scanf("%s",buff);
		new.right[i]=malloc(sizeof(char)*strlen(buff)+1);
		strcpy(new.right[i],buff);
		flushBuffer(buff, 100);
	}
	return new;
}
void printAll(cfg current){
	for(int i=0;i<current.maxProduction;i++){
		printf("%c -> %s\n",current.left[i],current.right[i]);
	}
}
FIRST first(cfg current){
	char processed[100]="";
	char notProcessed[100]="";
	for(int i=0;i<current.maxProduction;i++){
		if(charIn(notProcessed,current.left[i])==-1){
			appendChar(notProcessed,current.left[i]);
		}
	}
	int nonTerminalCount=strlen(notProcessed);
	char nonTerminals[100];
	char *f[nonTerminalCount];
	char z[nonTerminalCount];
	strcpy(nonTerminals,notProcessed);
	for(int i=0;i<nonTerminalCount;i++){
		char now=popChar(notProcessed);
		z[i]=now;
		f[i]=malloc(sizeof(char)*100);
		strcpy(f[i],"");
		for(int j=0;j<current.maxProduction;j++){
			if(current.left[j]==now){
				char testChar=current.right[j][0];
				if(testChar==now){
					//No point in following this rabbit hole
					continue;
				}
				else{
					if(charIn(f[i],testChar)==-1){
						appendChar(f[i],testChar); //May be a non terminal, but don't bother
					}
				}
			}
		}
	}
	while(true){
		_Bool flag=true;
		for(int i=0;i<nonTerminalCount;i++){
			int length=strlen(f[i]);
			for(int j=0;j<length;j++){
				if(charIn(nonTerminals,f[i][j])!=-1){
					for(int k=0;k<nonTerminalCount;k++){
						if(z[k]==f[i][j]){
							replaceCharWithStr(f[i],f[k],j);
							flag=false;
						}
					}
				}
			}
		}
		if(flag==false){
			break;
		}
	}
	FIRST F;
	F.nonTerminalsCount=nonTerminalCount;
	strcpy(F.nonTerminals,nonTerminals);
	for(int i=0;i<nonTerminalCount;i++){
		//printf("first(%c) = %s\n",z[i],f[i]);
		F.left[i]=z[i];
		strcpy(F.right[i],f[i]);
	}
	return F;
}
void printFist(FIRST f){
	for(int i=0;i<f.nonTerminalsCount;i++){
		printf("first(%c) = %s\n",f.left[i],f.right[i]);
	}
}
void follow(cfg current, FIRST f){
	char processed[100]="";
	char notProcessed[100]="";
	for(int i=current.maxProduction-1;i>-1;i--){
		if(charIn(notProcessed,current.left[i])==-1){
			appendChar(notProcessed,current.left[i]);
		}
	}
	printf("Not Processed : %s\n",notProcessed);
}
int main(){
	cfg test=getInput();
	printAll(test);
	FIRST f = first(test);
	printFist(f);
	return 0;
}

