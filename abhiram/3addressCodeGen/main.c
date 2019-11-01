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
#include "stringAdv.c"
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
char * strnncpy(int l, int u, char * str){
	char buffer[100]="";
	int i=l;
	while(i<u){
		appendChar(buffer,str[i]);
	}
	return str;
}
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
	v.limit++;
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
	for(int i=0;i<test.limit;i++){
		printf("%s\n",test.vect[i]);
	}
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
void processVector(vector tokens){
	/* Find equals */
	char c[2]="=";
	int pos=-1;
	tac t[tokens.limit+10];
	int tCount=0;
//	for(int i=0;i<tokens.limit;i++){
//		if(strcmp(c,tokens.vect[i])){
//			pos=i;
//			t[tCount].lhs=genTemp();
//			tCount++;
//			break;
//		}
//	}
	while(true){
		int pos=vectSearch(tokens,"/");
		if(pos!=-1){
			char *l=tokens.vect[pos-1];
		}
	}
}
void test(){
	printf("%s\n",genTemp());
}
int main(){
//	chopychop(NULL);
	char buff[10]="a = b + c";
	vector v = chop(buff);
	v=vectIns(v,1,"z");
	displayVect(v);
	//test();
	//test();
	return 0;
}
