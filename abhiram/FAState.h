#include "stack.h"
#define STATE_LIMIT 100
_Bool DEAD=false;
typedef struct{
    stack * this;
    stack * output[STATE_LIMIT];
}state;
state * traverseState(node ** n);
_Bool compareStates(state * s1, state * s2);
stack * checkPushState(node * head, state *c){
    node * curr=head;
    _Bool flag = false;
    while(curr != NULL){
        state * temp = traverseState(&curr);
        if(compareStates(temp,c)==true){
            flag=true;
            break;
        }
    }
    if(flag==false){
        return push(head,(void *) c);
    }
    return head;
}
stack * pushState(node * head, state *c){
    return push(head,(void *) c);
}
node * popState(node * head, state ** d){
    void * data;
    head=pop(head,&data);
    *d=(state *)data;
    return head;
}
state * traverseState(node ** n){
    state * val = (state *) traverse(n);
    if(val==NULL){
        return NULL;
    }
    return val;
}
//Local extention of stack.h for comparing stacks of state type.
_Bool compareStateStackContents(node * head1,node *head2){
    int count1=stacklen(head1);
    int count2=stacklen(head2);
    if(count1!=count2){
        return false;
    }
    node * curr1=head1;
    while(curr1!=NULL){
        state * data1=traverseState(&curr1);
        node * curr2=head2;
        _Bool flag=false;
        while(curr2!=NULL){
            state * data2=traverseState(&curr2);
            if(data1==data2){
                flag=true;
                break;
            }
        }
        if(flag==false){
            return false;
        }
    }
    return true;
}
_Bool compareIntStackContents(node * head1,node *head2){
    int count1=stacklen(head1);
    int count2=stacklen(head2);
    if(count1!=count2){
        return false;
    }
    node * curr1=head1;
    while(curr1!=NULL){
        int data1=traverseInt(&curr1);
        node * curr2=head2;
        _Bool flag=false;
        while(curr2!=NULL){
            int data2=traverseInt(&curr2);
            if(data1==data2){
                flag=true;
                break;
            }
        }
        if(flag==false){
            return false;
        }
    }
    return true;
}
//compareStates compares 2 given states.
_Bool compareStates(state * s1, state * s2){
    if(compareIntStackContents(s1->this,s2->this)==true){
        for(int i=0;i<STATE_LIMIT;i++){
            if(compareStateStackContents(s1->output[i],s2->output[i])==false){
                return false;
            }
        }
    }
    else{
        return false;
    }
    return true;
}
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

void eclosure(state * s,state * start, stack ** output){
    stack * curr=s->this;
//    int S=traverseInt(&curr);
    *output=pushState(*output,s);
//    printf("State %d\n",S);
    if(s->output[0]!=NULL){
        curr = s->output[0];
        while(curr!=NULL){
            state * s1= traverseState(&curr);
            if(s1!=s){
                if(s1==start){
                    return;
                }
                eclosure(s1,start,output);
            }
        }
    }
}
