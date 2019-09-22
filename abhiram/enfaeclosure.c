#include<stdio.h>
#include "FAState.h"
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#define true 1
#define false 0
#define True 1
#define False 0
#define STATE_LIMIT 100
_Bool DEBUG=false;

int main(int argc, char ** argv){
    state nfa[STATE_LIMIT];
    int stateCount=0;
    int inputCount=0;
    printf("Enter state count:");
    scanf("%d",&stateCount);
    printf("%d\n",stateCount);
    printf("Enter input count:");
    scanf("%d",&inputCount);
    printf("%d\n",inputCount);
    for(int i=0;i<stateCount;i++){
        for(int j=0;j<STATE_LIMIT;j++){
            nfa[i].output[j]=NULL;
        }
        nfa[i].this=NULL;
        nfa[i].this=pushInt(nfa[i].this,i);
        printf("Entering Data for state %d\n",i);
        for(int j=0;j<inputCount;j++){
            printf("Enter no of transition for input %d :",j);
            int trans;
            scanf("%d",&trans);
            printf("%d\n",trans);
            for(int k=0;k<trans;k++){
                printf("Enter the %d transition for input %d :",k,j);
                int s;
                scanf("%d",&s);
                printf("%d\n",s);
                nfa[i].output[j]=pushState(nfa[i].output[j],&(nfa[s]));
            }
        }
    }
    printf("Entered NFA\n");
    for(int i=0;i<stateCount;i++){
        printf("State %d\n",i);
        for(int j=0;j<STATE_LIMIT;j++){
            if(nfa[i].output[j]!=NULL){
                printf("For input %d\n",j);
                stack * curr=nfa[i].output[j];
                state * data=NULL;
                _Bool flag=False;
                printf("{");
                while(curr!=NULL){
                    //printf("Meh\n");
                    data=traverseState(&curr);
                    if(data!=NULL){
                        stack * s=data->this;
                        int d=traverseInt(&s);
                        printf("%d ",d);
                    }
                }
                printf("}\n");
            }
        }
    }
    for(int i=0;i<stateCount;i++){
        printf("Epsilone closure of %d state\n",i);
        stack * output = NULL;
        eclosure(&(nfa[i]),&(nfa[i]),&output);
        stack * curr=output;
        while(curr!=NULL){
            state * s = traverseState(&curr);
            printStateName(s,inputCount);
        }
    }
}
