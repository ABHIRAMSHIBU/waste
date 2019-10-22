/*
 * firstandfollow.c
 *
 *  Created on: Oct 9, 2019
 *      Author: abhiram
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "stringAdv.c"
#define true 1
#define false 0
typedef struct{
	char nonTerminals[100];
	char right[100][100];
	char left[100];
	int nonTerminalsCount;
}FIRST;
void displayCharArray(char *string){
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
//	while(true){
//		_Bool flag=true;
//		for(int i=0;i<nonTerminalCount;i++){
//			int length=strlen(f[i]);
//			for(int j=0;j<length;j++){
//				if(charIn(nonTerminals,f[i][j])!=-1){
//					for(int k=0;k<nonTerminalCount;k++){
//						if(z[k]==f[i][j]){
//							_Bool problem=replaceCharWithStr_CFG(f[i],f[k],j);
//							if(problem==true){
//								printf("Error exists for %c merge with %c\n",z[i],z[k]);
//								for(int l=0;l<current.maxProduction;l++){
//									//Find the production with conflict
//									if(current.left[l]==z[i] && charIn(current.right[l],z[k])!=-1){
//										int pos=charIn(current.right[l],z[k]);
//										char charPos = current.right[l][pos];
//										for( int m=0; m<nonTerminalCount; m++){
//											// Append the first of next thing
//										}
//									}
//								}
//							}
//							flag=false;
//						}
//					}
//				}
//			}
//		}
//		if(flag==false){
//			break;
//		}
//	}
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
		printf("first(%c) = ",f.left[i]);
		displayCharArray(f.right[i]);
		printf("\n");
	}
}
void follow(cfg current, FIRST F){
	char processed[100]="";
	char notProcessed[100]="";
	for(int i=current.maxProduction-1;i>-1;i--){
		if(charIn(notProcessed,current.left[i])==-1){
			appendChar(notProcessed,current.left[i]);
		}
	}
	int nonTerminalCount=strlen(notProcessed);
	char nonTerminals[100];
	char *f[nonTerminalCount];
	char z[nonTerminalCount];
	strcpy(nonTerminals,notProcessed);
	//printf("Not Processed : %s\n",notProcessed);
	_Bool start=true;
	for(int i=0;i<nonTerminalCount;i++){
		char now=popChar(notProcessed);
		z[i]=now;
		f[i]=malloc(sizeof(char)*100);
		strcpy(f[i],"");
		if(start==true){
			appendChar(f[i],'$');
			start=false;
		}
		for(int j=0;j<current.maxProduction;j++){
			//printf("Poped %c \n",now);
			if(charIn(current.right[j],now)!=-1){
				//printf("YAY FOUND %c %s\n",now,current.right[j]);
				int nextCharPos=charIn(current.right[j],now)+1;
				char nextChar = current.right[j][nextCharPos];
				//printf("DEBUG : %c\n",nextChar);
				/* Three conditions for nextChar can arrise 
					1) nextChar is 0 aka \0 then we need to add follow of this production to current follow.
					2) nextChar is a nonTerminal then need first of that thing.
					3) nextChar is a terminal, then add to the follow collection
				*/
				if(nextChar == 0){
					//Follow needs to be copied here
					for(int k=0;k<nonTerminalCount;k++){
						if(z[k]==current.left[i]){
							char * right = f[k];
							int rightlen = strlen(right);
							for(int l=0; l<rightlen;l++){
								char temp = right[l];
								if(charIn(f[i],temp)==-1){
									appendChar(f[i],temp);					
								}
												
							}		
						}					
					}				
				}
				else if(charIn(nonTerminals,nextChar)!=-1){ //aka found.. ie its a nonterminal
					//First needs to be appended
					for(int k=0;k<F.nonTerminalsCount;k++){
						if(F.left[k]==nextChar){
							char * right = F.right[k];
							int rightlen = strlen(right);
							for(int l=0; l<rightlen;l++){
								char temp = right[l];
								if(charIn(f[i],temp)==-1){
									appendChar(f[i],temp);					
								}
												
							}		
						}					
					}
				}
				else{
					//Im happy.. append the result!
					if(charIn(f[i],nextChar)==-1){
						appendChar(f[i],nextChar);					
					}
				}
			}
		}
	}
	for(int i=0;i<nonTerminalCount;i++){
		printf("follow(%c) = ",z[i]);
		displayCharArray(f[i]);
		printf("\n");
	}
}
int main(){
	cfg test=getInput();
	printAll(test);
	FIRST f = first(test);
	printFist(f);
	follow(test,f);
	return 0;
}
