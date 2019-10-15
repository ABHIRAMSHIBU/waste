#define true 1
#define flase 0
#define True 1
#define False 0
#include<malloc.h>
#include<string.h>
void flushBuffer(char * buffer, int bufferLength){
	for(int i=0;i<bufferLength;i++){
		buffer[i]='\0';
	}
}
void softErase(char * buffer){
	buffer[0]='\0';
}
int charIn(char * str, char c){
	int i = 0;
	while(True){
		if(str[i]==c){
			return i;
		}
		else if(str[i]=='\0'){
			return -1;
		}
		i++;
	}
}
void appendChar(char * str, char c){
	int length=strlen(str);
	str[length]=c;
	str[length+1]='\0';
}
char popChar(char * str){
	int length=strlen(str);
	char c = str[length-1];
	str[length-1]='\0';
	return c;
}
void replaceCharWithStr(char * str1, char *str2, int pos){
	char *buff=malloc((strlen(str1)+strlen(str2))*sizeof(char));
	int z=0;
	for(int i=0;i<strlen(str1);i++){
		if(i!=pos){
			buff[z]=str1[i];
			z++;
		}
		else{
			for(int j=0;j<strlen(str2);j++){
				buff[z]=str2[j];
				z++;
			}
		}
	}
	buff[z]='\0';
	strcpy(str1,buff);
}
