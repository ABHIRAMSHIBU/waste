#include<stdio.h>
#include "stack.h"
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#define true 1
#define false 0
#define True 1
#define False 0
#define STATE_LIMIT 100
_Bool DEBUG=false;
typedef struct{
    stack * this;
    stack * output[STATE_LIMIT];
}state;
int main(int argc, char ** argv){
    FILE * file=fopen("dfa","r");
    state nfa[STATE_LIMIT];
    int stateCount=0;
    for(int i=0;i<STATE_LIMIT;i++){
        int input;
        int j=0;
        int ret = fscanf(file,"%d",&input);
        if(ret==EOF){
            break;
        }
        nfa[i].this=pushInt(nfa[i].this,0);
        while(input!=-1){
            nfa[i].
        }
        
    }
}
