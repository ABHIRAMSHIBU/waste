#include<unistd.h>
#include<string.h>
#include<stdio.h>
#define MAX 100
int main(){
    int p[2];
    int result=pipe(p);
    fflush(stdin);
    if(result<0){
        printf("Pipe Failed\n");
    }
    else{
        printf("Pipe success\n");
        char buff[MAX];
        if(fork()==0){
            read(p[0],buff,MAX);
            printf("Read Data is:%s",buff);
        }
        else{
            strcpy(buff,"Hello World");
            write(p[1],buff,MAX);
        }
    }
}
