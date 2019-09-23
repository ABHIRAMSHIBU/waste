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
stack * delta(stack * states,int input){
    stack * curr = states;
    stack * new = NULL;
    while(curr!=NULL){
        state * s = traverseState(&curr);
        stack * output=s->output[input];
        stack * curr2 = output;
        while(curr2 != NULL){
            state * this = traverseState(&curr2);
            new = checkPushState(new, this);
        }
    }
    return new;
}
int main(int argc, char ** argv){
    state nfa[STATE_LIMIT];
    int stateCount=0;
    int inputCount=0;
    int finalCount=0;
    stack * finalStates=NULL;
    printf("Enter state count:");
    scanf("%d",&stateCount);
    printf("%d\n",stateCount);
    printf("Enter input count:");
    scanf("%d",&inputCount);
    printf("%d\n",inputCount);
    printf("Enter number of final states:");
    scanf("%d",&finalCount);
    printf("%d\n",finalCount);
    for(int i=0;i<finalCount;i++){
        int temp;
        printf("Enter final State %d:",i);
        scanf("%d",&temp);
        printf("%d\n",temp);
        finalStates=pushState(finalStates,&(nfa[temp]));
    }
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
        stack * output = NULL;
        eclosure(&(nfa[i]),&(nfa[i]),&output);;
        stack * curr=output;
        printf("Epsilone closure of %d state\n",i);
        while(curr!=NULL){
            state * s = traverseState(&curr);
            printStateName(s,inputCount);
        }
        for(int z=1;z<inputCount;z++){
            stack * deltaOutput = delta(output,z);
            curr=deltaOutput;
            printf("Delta of %d, %d state\n",i,z);
            while(curr!=NULL){
                state * s = traverseState(&curr);
                printStateName(s,inputCount);
            }
            stack * stackEclosureOutput = stackEclosure(deltaOutput);
            curr=stackEclosureOutput;
            _Bool finalFlag = false;
            printf("Eclosure of delta\n");
            while(curr!=NULL){
                state * s = traverseState(&curr);
                stack * curr1 = finalStates;
                while(curr1!=NULL){
                    state * f =traverseState(&curr1);
                    if(compareStates(s,f)==true){
                        finalFlag=true;
                        break;
                    }
                }
                printStateName(s,inputCount);
            }
            if(finalFlag==true){
                printf("That is a final state\n");
            }
        }
    }
}
