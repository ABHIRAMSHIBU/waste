/*Author:Abhijith N Raj
 * Program to Convert  NFA to a DFA
 */
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

void eclosure(state * s,state * start){
    stack * curr=s->this;
    int S=traverseInt(&curr);
    printf(" %d ",S);
    if(s->output[0]!=NULL){
        curr = s->output[0];
        while(curr!=NULL){
            state * s1= traverseState(&curr);
            if(s1!=s){
                if(s1==start){
                    return;
                }
                eclosure(s1,start);
            }
        }
    }
    
    //s.output[0]
}
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
        printf("State %d\n",i);
        for(int j=0;j<inputCount;j++){
            printf("Enter no of transition for input %d for state %d :",j,i);
            int trans;
            scanf("%d",&trans);
            printf("%d\n",trans);
            for(int k=0;k<trans;k++){
//                 printf("Enter the %d transition for input %d :",k,j);
                printf("Enter %dth transition delta(%d,%d)=?",k,i,j);
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
                printf("[");
                while(curr!=NULL){
                    //printf("Meh\n");
                    data=traverseState(&curr);
                    if(data!=NULL){
                        stack * s=data->this;
                        int d=traverseInt(&s);
                        printf("%d ",d);
                    }
                }
                printf("]\n");
            }
        }
    }
    for(int i=0;i<stateCount;i++){
        printf("e-closure(%d)=\n",i);
        printf("[");
        eclosure(&(nfa[i]),&(nfa[i]));
        printf("]\n");
    }
}
