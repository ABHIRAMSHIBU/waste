/*
 * main.c
 *
 *  Created on: Nov 1, 2019
 *      Author: abhiram
 */
#define true 1
#define false 0
#define True true
#define False false

#include "stack.h"
typedef struct {
	char * vect[100];
	int limit;
	int vectPtr;
}vector;
typedef struct{
	char * lhs;
	char * rhs1;
	char * op;
	char * rhs2;
	_Bool unary;
}tac;

//vector chopychop(char * str){
//	vector new;
//	new.limit=0;
//	new.vectPtr=0;
//	int ptr1=0,ptr2=0;
//	int length = strlen(str);
//	for(int i=0;i<length;i++){
//		if()
//	}
//	//printf("%s\n",a);
//}
int vectSearch(vector v,char * str){
	for(int i=0;i<v.limit;i++){
		if(strcmp(v.vect[i],str)==0){
			return i;
		}
	}
	return -1;
}
vector vectDel(vector v, int index){
	for( int i=index;i<(v.limit-1);i++){
		strcpy(v.vect[i],v.vect[i+1]);
	}
	v.limit--;
	return v;
}
vector vectIns(vector v, int index, char * str){
	v.vect[v.limit]=malloc(strlen(v.vect[v.limit-1])+1);
	for(int i=v.limit;i>index;i--){
		strcpy(v.vect[i],v.vect[i-1]);
	}
	strcpy(v.vect[index],str);
	v.limit=v.limit+1;
	return v;
}
vector chop(char *str){
	const char s[4]=" ";
	char *tok;
	vector new;
	new.limit=0;
	tok = strtok(str,s);
	int length=strlen(tok);
	new.vect[new.limit]=malloc(length+1);
	strcpy(new.vect[new.limit],tok);
	new.limit++;
	while (tok != 0) {
		tok = strtok(0, s);
		if(tok==0){
			break;
		}
		int length=strlen(tok);
		new.vect[new.limit]=malloc(length+1);
		strcpy(new.vect[new.limit],tok);
		new.limit++;
	}
	return new;
}
void displayVect(vector test){
	printf("[ ");
	for(int i=0;i<test.limit;i++){
		printf("%s  ",test.vect[i]);
	}
	printf(" ]\n");
}
char * genTemp(){
	static int count=0;
	char * buff = malloc(10);
	strcpy(buff,"tmp");
	char buff2[10];
	sprintf(buff2, "%d", count);
	strcat(buff,buff2);
	count++;
	return buff;
}

void Reduce(vector *tokens,int pos,tac *t,char *op,int *tCount){
	printf("The value of pos is %d\n",pos);
	printf("Entering reduce value of tCount is %d\n",*tCount);
	char *l=malloc(strlen(tokens->vect[pos-1]));
	strcpy(l,tokens->vect[pos-1]);
	char *r=malloc(strlen(tokens->vect[pos+1]));
	printf("The value of that is %s\n",tokens->vect[pos-1]);
	strcpy(r,tokens->vect[pos+1]);
	*tokens=vectDel(*tokens, pos-1);
	*tokens=vectDel(*tokens, pos-1);
	*tokens=vectDel(*tokens, pos-1);
	char *new_temp = genTemp();
	*tokens=vectIns(*tokens, pos-1,new_temp);
	t[*tCount].lhs = malloc(strlen(new_temp));
	strcpy(t[*tCount].lhs,new_temp);
	t[*tCount].op= malloc(strlen(op));
	t[*tCount].op=op;
	t[*tCount].rhs1=malloc(strlen(l));
	t[*tCount].rhs1=l;
	t[*tCount].rhs2=malloc(strlen(r));
	t[*tCount].rhs2=r;
	*tCount=*tCount+1;
	printf("The value of tCount on Exit is %d\n",*tCount);
}
void displayTAC(tac t){
	printf("%s ",t.lhs);
	printf(" = ");
	printf("%s ",t.rhs1);
	if(strcmp(t.op,"=")!=0){
		printf("%s ",t.op);
		printf("%s",t.rhs2);

	}

	printf("\n");

}
tac *processVector(vector tokens, int *tCount){
	/* Find equals */
	printf("The value of tCount is %d",*tCount);
	printf("The vector to be processed is  ");
	displayVect(tokens);
	printf("\n");
	tac *t;
	t=malloc((tokens.limit+10)*sizeof(tac));
	while(true){
		if(tokens.limit==3){
			t[*tCount].lhs=tokens.vect[0];
			t[*tCount].rhs1=tokens.vect[2];
			t[*tCount].op="=";
			*tCount=*tCount+1;
			break;
		}
		int pos=vectSearch(tokens,"/");
		if(pos!=-1){
			printf("operator / found at %d\n",pos);
			Reduce(&tokens, pos, t,"/", tCount);
			displayVect(tokens);
			continue;
		}
		pos=vectSearch(tokens,"*");
		if(pos!=-1){
			printf("operator * found at %d\n",pos);
			Reduce(&tokens, pos, t,"*", tCount);
			displayVect(tokens);
			continue;
		}

		pos=vectSearch(tokens,"+");
		if(pos!=-1){
			printf("operator + found at %d\n",pos);
			Reduce(&tokens, pos, t,"+", tCount);
			displayVect(tokens);
			continue;
		}

		pos=vectSearch(tokens,"-");
		if(pos!=-1){
			printf("operator * found at %d\n",pos);
			Reduce(&tokens, pos, t,"-", tCount);
			displayVect(tokens);
			continue;
		}


	}
	printf("\n3AC is for count %d\n",*tCount);
	for(int i=0;i<*tCount;i++){
		displayTAC(*(t+i));
	}
	return t;
}


void test(){
	printf("%s\n",genTemp());
}
void eliminateBrackets(vector tokens,int *tCount){
	stack *s=NULL;
	vector v[20];
	tac *t[100];
//	t=malloc(100*sizeof(tac));
	int vCount=0;
	int hereTCount=0;
	int count[100];
	for(int i=0;i<tokens.limit;i++){
		if(strcmp(")",tokens.vect[i])==0){
			printf("Found ) at pos %d \n",i);
			int k=0;
			v[vCount].limit=0;
			while(true){
				char new_str[20];
				s=popStr(s,new_str);
				if(strcmp(new_str,"(")==0){
//					printf("a chopped vector is \n");
//					displayVect(v[vCount]);
//					printf("\n");
					char *temp = genTemp();
					v[vCount]=vectIns(v[vCount],0,"=");
					v[vCount]=vectIns(v[vCount],0,temp);
					displayVect(v[vCount]);
					int new_tCount=0;
					t[hereTCount]= processVector(v[vCount],&new_tCount);
					count[hereTCount]=new_tCount;
					hereTCount++;
//					printf("new_tCount %d \n",new_tCount);
					*tCount=*tCount+new_tCount;
//					printf("tCount now is %d\n",*tCount);
					pushStr(s,temp);
					vCount++;
					break;
				}
				v[vCount]=vectIns(v[vCount],k,new_str);
				k++;
			}

		}
		else{
			s=pushStr(s,tokens.vect[i]);
		}

	}
	for(int i=0;i<hereTCount;i++){
		for(int j=0;j<count[i];j++){
//			printf("%p %d %d\n",t+i,i,hereTCount);
			displayTAC(*(t[i]+j));
		}
	}

}
int main(){
//	chopychop(NULL);
//	char buff[100]="t1 = ( ( b + c + e ) * d )";
	char buff[100]= "( ( c + d ) * e / f + ( h - e )  ";
	vector v = chop(buff);
	displayVect(v);
	int tCount=0;
	eliminateBrackets(v,&tCount);
//	tac *t=processVector(v,&tCount);
//	printf("3AC is for count %d\n",tCount);
//	for(int i=0;i<tCount;i++){
//		displayTAC(*(t+i));
//	}
//	displayVect(v);
	//test();
	//test();
	return 0;
}
