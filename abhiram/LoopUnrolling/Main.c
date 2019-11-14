/*
 * Main.c
 *
 *  Created on: 14-Nov-2019
 *      Author: students
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char * vect[100];
	int limit;
	int vectPtr;
}vector;
char * getf(){
	char * z = malloc(sizeof(char) *100 );
	strcpy(z,"/tmp/a");
	return z;
}
char * mode(){
	char * z = malloc(sizeof(char) *100 );
	strcpy(z,"r");
	return z;
}
FILE * getfile(){
	FILE * a = popen(getf(),mode());
	return a;
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
		printf("%s , ",test.vect[i]);
	}
	printf(" ]\n");
}
vector start(){
	vector k;
	FILE * a = getfile();
	while(1){
		char z=fgetc(a);
		if(z==EOF){
			break;
		}
		printf("%c",z);
	}
	return k;
}
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
int main(){
	vector z = start();
	char test[100] = "a[1] = c";
	vector m = chop(test);
	printf("Done!");
	return 0;
}
