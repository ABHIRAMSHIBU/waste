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
_Bool DEBUG=false;
_Bool DEAD=false;
_Bool FINAL=false;
void printStateName(state * s, int inputCount){
//     printf("State [");
    stack * temp = s->this;
    while(temp!=NULL){
        int val = traverseInt(&temp);
        printf("q%d ",val);
        if(temp!=NULL){
            printf(", ");
        }
    }
//     printf("]\n");
}
void printState(state * s, int inputCount){
    printf("\n\n\n");
//     printf("PrintState ");
    FINAL=false;
    printf("[");
    printStateName(s,inputCount);
    printf("]\n");
    for(int i =0;i<inputCount;i++){
        printf("INPUT %d\n",i);
        stack * temp = s->output[i];
        if(temp==NULL){
            printf("Dead state\n");
            DEAD=true;
        }
        else{
            printf("[");
            while(temp!=NULL){
                state * curr = traverseState(&temp);
                printStateName(curr,inputCount);
            }
            printf("]\n");
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
    int iter=0;
    while(True){
        next=NULL;
        if(stacklen(unresolved)==0){
           // printf("Breaked! %d\n",iter);
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
        iter++;
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

// void displayFinalStackContents(stack * stateStack, int FinalStateCount){
//     stack *head = stateStack;
//     int index =0;
//     while(1){
//         state = head->next;
//         printf("For the index state %d,the states in the final stack are ",state->output[0]);
//         if(state==NULL){
//             break;
//         }   
//         index++;
//     }
// }

int main(int argc, char ** argv){
    state nfa[STATE_LIMIT];
    int stateCount=0;
    int inputCount=0;
    int finalCount=0;
    stack * finalStates=NULL;
    printf("Enter the state count for the DFA\n");
    scanf("%d",&stateCount);
    printf("%d\n",stateCount);
    printf("Enter the no of alphabets:");
    scanf("%d",&inputCount);
    printf("%d\n",inputCount);
    printf("Enter the count for final states\n");
    scanf("%d",&finalCount);
    printf("%d\n",finalCount);
    for(int i=0;i<finalCount;i++){
        int temp;
        printf("Enter Final State %dth one:",i);
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
        printf("Transition for state %d\n",i);
        for(int j=0;j<inputCount;j++){
            printf("Enter no of transition for input %d :",j);
            int trans;
            scanf("%d",&trans);
            printf("%d\n",trans);
            for(int k=0;k<trans;k++){
                printf("Transition Number%d, delta(%d,%d) = ?:",k,i,j);
                int s;
                scanf("%d",&s);
                printf("%d\n",s);
                nfa[i].output[j]=pushState(nfa[i].output[j],&(nfa[s]));
            }
        }
    }
    printf("Transition Function is as shown below\n");
    for(int i=0;i<stateCount;i++){
        //printf("State %d\n",i);
        for(int j=0;j<STATE_LIMIT;j++){
            if(nfa[i].output[j]!=NULL){
                printf("State %d on input %d goes to following states\n",i,j);
                stack * curr=nfa[i].output[j];
                state * data=NULL;
                _Bool flag=False;
                printf("[");
                while(curr!=NULL){
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



    stack * dfa=nfa2Dfa(inputCount,&nfa[0]);
    stack * curr = dfa;
    while(curr!=NULL){
        state * s1 = traverseState(&curr);
        printState(s1,inputCount);
    }
    
    printf("\n\n\nFor the dead state\n");
    if(DEAD==True){
//         printf("\n\n\nPrintState State {dead}\n");
        for(int i=0;i<inputCount;i++){
            printf("INPUT %d\n",i);
            printf("Dead state\n");
        }
    }
    curr=dfa;
    
    printf("\n\n\n[q0] is the intial state\n");
    printf("Final State\n");
    while(curr!=NULL){
        state * s1 = traverseState(&curr);
        stack * states = s1->this;
        stack  * curr1 = finalStates;
        _Bool Flag=true;
        printf("[");
        while(curr1!=NULL && Flag==true){
            int val = traverseInt(&curr1);
            stack * curr2 = states;
            while(curr2!=NULL && Flag==true){
                int val1 = traverseInt(&curr2);
                if(val1==val){
                    printStateName(s1,inputCount);
                    Flag=false;
                }
            }
        }
        printf("]\n");
    }

    
}
