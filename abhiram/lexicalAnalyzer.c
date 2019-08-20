#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define true 1
#define false 0
_Bool checkConst(char * buffer,int length){
	_Bool constant=true;
	for(int i=0;i<length;i++){
		if(!(buffer[i]<='9' && buffer[i]>='0')){
			constant=false;
		}
	}
	if(length==0){
		constant=false;
	}
	return constant;
}
void strip(char * buffer,int length){
	char newbuffer[100];
	int pos=0;	
	for(int i=0;i<length;i++){
		if(!(buffer[i]=='\n' || buffer[i]=='\r' || buffer[i]=='\t' || buffer[i]==' ')){
			newbuffer[pos]=buffer[i];
			pos++;	
		}
	}
	newbuffer[pos]='\0';
	strcpy(buffer,newbuffer);
}
_Bool checkKeyword(char * buffer){
	char KEYWORDS[][10]={"include","void","int","char","float","long","double","for","while","do","if","switch","case","struct","typedef",
			     "printf"};
	int KEYWORDS_LEN=16;
	_Bool iskeyword=false;
	for(int i=0;i<KEYWORDS_LEN;i++){
		if(strcmp(buffer,KEYWORDS[i])==0){
			iskeyword=true;
			break;
		}
	}
	return iskeyword;
}	
int main(){
	FILE * f = fopen("text.txt","r");
	char z=fgetc(f);
	char buffer[100];
	char SPECIALS[]={';','<','>','{','}','(',')','*','+','!','='};
	int SPECIALS_LEN=sizeof(SPECIALS);
	char *SPECIALCHARBUFF[10];
	int pos=0; 
	while(z!=EOF){
		//printf("%c",z);
		_Bool SPECIAL=false;
        int SPECIALCHARBUFF_LEN=0;
        if(z=='"'){
            char *s=malloc(sizeof(char)*100);
            int i=0;
            SPECIAL=true;
            SPECIALCHARBUFF_LEN=4;
            SPECIALCHARBUFF[0]=s;
            while(true){
                z=fgetc(f);
                if(z=='"'){
                    break;
                    s[i]='\0';
                }
                else{
                    s[i]=z;
                    i++;
                }
            }
        }
        else{
            for(int i=0;i<SPECIALS_LEN;i++){
                if(z==SPECIALS[i]){
                    if(z=='*' || z=='/'){
                        //printf("('%c',operator)\n",z);
                        SPECIALCHARBUFF[0]="operator";
                        SPECIALCHARBUFF[1]=&z;
                        SPECIALCHARBUFF_LEN=2;
                        SPECIAL=true;
                        break;
                    }
                    else if(z=='+' || z=='-' || z=='<' || z=='>' || z=='='){
                        char next = fgetc(f);
                        if(next=='+' || next=='-'|| next=='<'|| next=='>'|| next=='='){
                            //printf("('%c%c',operator)\n",z,next);
                            SPECIALCHARBUFF[0]="operator";
                            SPECIALCHARBUFF[1]=&z;
                            SPECIALCHARBUFF[2]=malloc(sizeof(char));
                            *SPECIALCHARBUFF[2]=next;
                            SPECIALCHARBUFF_LEN=3;
                            SPECIAL=true;
                            break;
                        }
                        else{
                            fseek(f,ftell(f)-1,0);
                            //printf("('%c',operator)\n",z);
                            SPECIALCHARBUFF[0]="operator";
                            SPECIALCHARBUFF[1]=&z;
                            SPECIALCHARBUFF_LEN=2;
                            SPECIAL=true;
                            break;
                        }
                    }
                    //printf("('%c',special)\n",z);
                    SPECIALCHARBUFF[0]="special";
                    SPECIALCHARBUFF[1]=&z;
                    SPECIALCHARBUFF_LEN=2;
                    SPECIAL=true;
                    break;
                }
            }
        }
		if(z!=' ' && SPECIAL==false){			
			buffer[pos]=z;
			pos++;
		}
		else{
			buffer[pos]='\0';
			strip(buffer,pos);
			if(checkConst(buffer,pos)==true){
				printf("(%s,constant)\n",buffer);
			}
			else if(checkKeyword(buffer)==true){
				printf("(%s,keyword)\n",buffer);
			}
			else{
				printf("Unprocessed :%s\n",buffer);
			}			
			pos=0;
		}
		if(SPECIALCHARBUFF_LEN==2){
            printf("('%c',%s)\n",*SPECIALCHARBUFF[1],SPECIALCHARBUFF[0]);
        }
        else if(SPECIALCHARBUFF_LEN==3){
            printf("('%c%c',%s)\n",*SPECIALCHARBUFF[1],*SPECIALCHARBUFF[2],SPECIALCHARBUFF[0]);
        }
        else if(SPECIALCHARBUFF_LEN==4){
            printf("(\"%s\",string)\n",SPECIALCHARBUFF[0]);
        }
		z=fgetc(f);		
	}
	return 0;
}
