#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define true 1
#define false 0
int ID_LEN=0;
char * ID[1000];
extern FILE * stdout;
int checkAndInsert(char * v){
    for(int i=0;i<ID_LEN;i++){
        if(strcmp(ID[i],v)==0){
            return i;
        }
    }
    ID[ID_LEN]=malloc(sizeof(char)*100);
    strcpy(ID[ID_LEN],v);
    ID_LEN++;
    return ID_LEN-1;
}
_Bool checkConst(char * buffer,int length){
	_Bool constant=true;
	for(int i=0;i<length;i++){
		if(!((buffer[i]<='9' && buffer[i]>='0')||buffer[i]=='.')){
			constant=false;
		}
	}
	if(length==0){
		constant=false;
	}
	return constant;
}
_Bool checkIdentifier(char * buffer,int length){
    _Bool identifier=true;
    char illegal[]={'@'};
    int illegal_len=sizeof(illegal);
    if(buffer[0]<='9' && buffer[0]>='0'){
        identifier=false;
    }
    else{
        for(int i=0;i<length;i++){
            for(int j=0;j<illegal_len;j++){
                if(buffer[i]==illegal[j]){
                    identifier=false;
                    break;
                }
            }
            if(identifier==false){
                break;
            }
        }
    }
    return identifier;
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
	FILE * f = fopen("test_source.c","r");
	char z=fgetc(f);
	char buffer[100];
	char SPECIALS[]={';','<','>','{','}','(',')','*','+','!','=',',','/','-'};
	int SPECIALS_LEN=sizeof(SPECIALS);
	char *SPECIALCHARBUFF[10];
	int pos=0; 
	while(z!=EOF){
            //printf("%c",z);
            _Bool SPECIAL=false;
            int SPECIALCHARBUFF_LEN=0;
            if(z=='/'){   //Comment parser
                char next=fgetc(f);
                if(next=='/'){
                   while(true){
                        //break;
                        //printf("%c",next);
                        //printf("gere");
                        char next=fgetc(f);
                        if(next=='\n'){
                            z=fgetc(f);
                            break;
                        }
                    } 
                }
                else if(next!='*'){
                    fseek(f,ftell(f)-1,0);
                    //break;
                }
                else{
                    while(true){
                        //break;
                        //printf("%c",next);
                        //printf("gere");
                        char next=fgetc(f);
                        if(next=='*'){
                            next=fgetc(f);
                            if(next=='/'){
                                z=fgetc(f);
                                break;
                            }
                        }
                    }
                }
            }
            if(z=='#'){
                printf("('#',preprocessorDir)\n");
                z=fgetc(f);
                char buffer[100];
                int i=0;
                while(z!='<'){
                    buffer[i]=z;
                    i++;
                    z=fgetc(f);
                    if(z==' '){
                        break;
                    }
                }
                buffer[i]='\0';
                strip(buffer,i);
                if(strcmp(buffer,"include")==0){
                    printf("(include,keyword)\n");
                    z=fgetc(f);
                    i=0;
                    while(z!='>'){
                        buffer[i]=z;
                        i++;
                        z=fgetc(f);
                    }
                    buffer[i]='\0';
                    strip(buffer,i);
                    printf("(%s,header)\n",buffer);
                    z=fgetc(f);
                }
                else if(strcmp(buffer,"define")==0){
                    printf("(define,keyword)\n(");
                    z=fgetc(f);
//                     int k=0;
//                     char buff[100];
//                     printf("(");
                    //fflush(stdout);
                    while(z!='\n'){
                        printf("%c",z);
                        z=fgetc(f);
                    }
                    printf(", macro)\n");
//                     strip(buffer,k);
//                     printf("(%s,MactroDef)",buff);
                }
            }
            if(z=='"' || z=='\''){
                char c=z;
                char *s=malloc(sizeof(char)*100);
                int i=0;
                SPECIAL=true;
                SPECIALCHARBUFF_LEN=4;
                SPECIALCHARBUFF[0]=s;
                while(true){
                    z=fgetc(f);
                    if(z==c){
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
                            if(z=='&'){
                                printf("(&,operator)\n");
                            }
                            else{
                                buffer[pos]=z;
                                pos++;
                            }
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
                                if(strlen(buffer)>0){
    //                                 printf("Processing :%s, ID: %d\n",buffer,val);
                                    if(checkIdentifier(buffer,pos)==true){
                                        int val = checkAndInsert(buffer);
                                        printf("(\"%s\",identifier,%d)\n",buffer,val);
                                    }
                                    else{
                                        printf("Error illegal identifier :%s\n",buffer);
                                    }
    // 				printf("Unprocessed :%s, Length:%d\n",buffer,(int)strlen(buffer));
                                }
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
