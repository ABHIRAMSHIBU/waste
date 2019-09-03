#include<stdio.h>
#include "FAState.h"
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#define true 1
#define false 0
#define True 1
#define False 0
_Bool DEBUG=false;
_Bool DEAD=false;
_Bool FINAL=false;
void printStateName(state * s, int inputCount){
    printf("State {");
    stack * temp = s->this;
    while(temp!=NULL){
        int val = traverseInt(&temp);
        printf("%d",val);
        if(temp!=NULL){
            printf(", ");
        }
    }
    printf("}\n");
}
void printState(state * s, int inputCount){
    printf("\n\n\n");
    printf("PrintState ");
    FINAL=false;
    printStateName(s,inputCount);
    for(int i =0;i<inputCount;i++){
        printf("OUTPUT %d\n",i);
        stack * temp = s->output[i];
        if(temp==NULL){
            printf("State {dead}\n");
            DEAD=true;
        }
        else{
            while(temp!=NULL){
                state * curr = traverseState(&temp);
                printStateName(curr,inputCount);
            }
            printf("\n");
        }
    }
}
state * resolveStates(stack * stateStack, int inputCount);
stack * nfa2Dfa(int inputCount, state * q0){
    stack * dfa = NULL;
    dfa=pushState(dfa,q0);
    state * next = resolveStates(dfa,inputCount);
    stack * unresolved=NULL;
//     printf("Next -----");
//     printState(next,inputCount);
    stack * curr=dfa;
    _Bool flag=false;
    while(curr!=NULL){
        state * now = traverseState(&curr);
        if(compareStates(now,next)==True){
            flag=True;
            break;
        }
    }
    if(flag==false){
        dfa=checkPushState(dfa,next);
    }
    for(int i=0;i<inputCount;i++){
        if(next->output[i]!=NULL){
            unresolved=checkPushState(unresolved,resolveStates(next->output[i],inputCount));
        }
    }
//     int iter=0;
    while(True){
        next=NULL;
        if(stacklen(unresolved)==0){
//             printf("Breaked! %d\n",iter);
            break;
        }
        unresolved=popState(unresolved,&next);
//         printf("____NEXT_)____\n");
//         printState(next,inputCount);
        for(int i=0;i<inputCount;i++){
            if(next->output[i]!=NULL){
                state * next1 = resolveStates(next->output[i],inputCount);
                curr = dfa;
                _Bool flag=false;
                while(curr!=NULL){
                    state * now = traverseState(&curr);
                    if(compareStates(now,next1)==True){
                        flag=True;
                        break;
                    }
                }
                if(flag==false){
    //                 printf("Pushing ---\n");
    //                 printState(next1,inputCount);
                    dfa=checkPushState(dfa,next1);
                    unresolved=checkPushState(unresolved,next1);
                }
            }
        }
//         iter++;
    }
    return dfa;
}
state * resolveStates(stack * stateStack, int inputCount){
    state * new = malloc(sizeof(state));
    stack * curr = stateStack;
    while(curr!=NULL){
        state * s = traverseState(&curr);
        stack * temp= s->this;
        while(temp!=NULL){
            int stateNum = traverseInt(&temp);
            new->this=checkPushInt(new->this,stateNum);
        }
        for(int i=0;i<inputCount;i++){
            stack * curr1 = s->output[i];
            while(curr1!=NULL){
                state * stateTemp=traverseState(&curr1);
                new->output[i]=checkPushState(new->output[i],stateTemp);
            }
        }
    }
    return new;
}
stack * nfa2dfa(state * nfa,int count,int inputCount, stack * nfal, stack * dfal,stack * dfaState){
    stack * curr = dfaState;
//     stack * dfal[100];
//     for(int i=0;i<100;i++){
//         dfal[i]=NULL;
//     }
    for(int i=0;i<inputCount;i++){
        state * now = traverseState(&curr);
        stack * newDFAState=NULL;
        while(curr!=NULL){
            if(now->output[i]!=NULL){
                stack * temp = now->output[i];
                while(temp!=NULL){
                    newDFAState=checkPushState(newDFAState,traverseState(&temp));
                }
//                 dfal=pushStack(dfal,now->output[i]);
            }
        }
        stack * temp1=dfal;
        while(temp1!=NULL){
            stack * temp2=traverseStack(&temp1);
            if(compareStateStackContents(temp2,newDFAState)==false){
                dfal=pushStack(dfal,newDFAState);
                dfal=nfa2dfa(nfa,count,inputCount,nfal,dfal,newDFAState);
            }
        }
    }
    return dfal;
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
        finalStates=pushInt(finalStates,temp);
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
//     state dfa[STATE_LIMIT];
//     dfa[0].this=nfa[0].this;
//     for(int i=0;i<STATE_LIMIT;i++){
//         dfa[0].output[i]=nfa[0].output[i];
//     }
// Test 1
//     stack * dfaInitialState=NULL;
//     dfaInitialState=pushState(dfaInitialState,&nfa[0]);
//     nfa2dfa(NULL,0,inputCount, NULL, NULL,dfaInitialState);
// Test 1 Fail

// Test 2
    //printState(&nfa[1],inputCount);
    
    
//     stack * testStack=NULL;
//     testStack=pushState(testStack,&nfa[0]);
//     state * testState = resolveStates(testStack, inputCount);
//     printState(testState,inputCount);


    stack * dfa=nfa2Dfa(inputCount,&nfa[0]);
    stack * curr = dfa;
    while(curr!=NULL){
        state * s1 = traverseState(&curr);
        printState(s1,inputCount);
    }
    if(DEAD==True){
        printf("\n\n\nPrintState State {dead}\n");
        for(int i=0;i<inputCount;i++){
            printf("OUTPUT %d\n",i);
            printf("State {dead}\n");
        }
    }
    curr=dfa;
    while(curr!=NULL){
        state * s1 = traverseState(&curr);
        stack * states = s1->this;
        stack  * curr1 = finalStates;
        _Bool Flag=true;
        while(curr1!=NULL && Flag==true){
            int val = traverseInt(&curr1);
            stack * curr2 = states;
            while(curr2!=NULL && Flag==true){
                int val1 = traverseInt(&curr2);
                if(val1==val){
                    printf("-------Final State-------\n");
                    printStateName(s1,inputCount);
                    Flag=false;
                }
            }
        }
    }
//     state * s2 = traverseState(&curr);
//     printState(s2,inputCount);
    //printf("Compare result %d\n",compareStates(s1,s2));
//     for(int i=0;i<stateCount;i++){
//         printState(&nfa[i],inputCount);
//     }
//     printf("%d\n",compareStateStackContents(nfa[0].output[1],nfa[1].output[1]));
//     printf("%d\n",compareStates(&nfa[0],&nfa[0]));
    
}
