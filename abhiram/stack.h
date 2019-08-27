// Copyleft 2019 Abhiram Shibu.
/*Stack header for any datatype in C
 *========================================*
 *              Implemented               *
 *int-------------------------------------*
 *stack * pushInt(stack * head,int i)     *
 *stack * popInt(stack * head,int * i)    *
 *int traverseInt(stack ** ptr)           *
 *char------------------------------------*
 *stack * pushChar(stack * head,char c)   *
 *stack * popChar(stack * head,char * c)  *
 *char traverseChar(stack ** ptr)         *
 *str-------------------------------------*
 *stack * pushStr(stack * head,char * str)*
 *stack * popStr(stack * head,char * buff)*
 *char * traverseChar(stack ** ptr)       *
 *void------------------------------------*
 *stack * push(stack * head, void * data) *
 *stack * pop(stack * head, void ** data) *
 *void * traverse(stack ** ptr)           *
 *========================================*/
#include<malloc.h>
#include<string.h>
#include<limits.h>
#define true 1
#define false 0
typedef struct n{
    struct n *next;
    void * data;
}node,stack;
_Bool isEmpty(node * head){
    if(head==NULL){
        return true;
    }
    else{
        return false;
    }
}
node * push(node * head,void * data);
node * pushStr(node * head, char *c){
    char * temp = malloc(sizeof(char)*strlen(c));
    strcpy(temp,c);
    return push(head,(void *) temp);
}
node * pushInt(node * head,int c){
    int * temp = malloc(sizeof(int));
    *temp = c;
    return push(head,(void *) temp);
}
node * pushChar(node * head, char c){
    char * temp = malloc(sizeof(char));
    *temp = c;
    return push(head,(void *) temp);
}
node * push(node * head,void * data){
    if(head==NULL){       //Stack dont exist
        head=malloc(sizeof(node));
        head->data=data;
        head->next=NULL;  // Set next data to null
    }
    else{
        node * curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=malloc(sizeof(node));
        curr->next->next=NULL;
        curr->next->data=data;
    }
    return head;
}

node * pop(node * head,void ** d);
node * popInt(node * head, int * d){
    void * data;
    head=pop(head,&data);
    *d=*((int *)data);
    free(data);
    return head;
}
node * popChar(node * head, char * d){
    void * data;
    head=pop(head,&data);
    *d=*((char *)data);
    free(data);
    return head;
}
node * popStr(node * head, char * d){
    void * data;
    head=pop( head,&data);
    strcpy(d,(char *)data);
    free(data);
    return head;
}
/* Need to pop into a pointer which needs to be a pointer because of local variable binding.
 */
node * pop(node * head,void ** d){
    if(head==NULL){
        return NULL;
    }
    else{
        node * curr=head;
        if(head->next==NULL){
            void * data=head->data;
            free(head);
            *d=data;
            return NULL;
        }
        else{
            while(curr->next->next!=NULL){
                curr=curr->next;
            }
            void * data=curr->next->data;
            *d=data;
            free(curr->next);
            curr->next=NULL;
            return head;
        }
    }
}
void * traverse(node ** n){
    if(*n==NULL){
        return NULL;
    }
    else{
        void * data=(*n)->data;
        *n=(*n)->next;
        return data;
    }
}
int traverseInt(node ** n){
    int * val = (int *) traverse(n);
    if(val==NULL){
        return INT_MIN;
    }
    return *(val);
}
char traverseChar(node ** n){
    char * val =(char *) traverse(n);
    if(val==NULL){
        return CHAR_MIN;
    }
    return *(val);
}
char * traverseStr(node ** n){
    return (char *) traverse(n);
}
int stacklen(node * head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}
// int main(){
//     node * stack =NULL;
//     char a[20]="Hello World!";
//     stack=pushStr(stack,a);
//     strcpy(a,"Hello Moon!");
//     stack=pushStr(stack,a);
// //     printf("%d %d\n",*((int *)stack->data),*((int *)stack->next->data));
//     while(isEmpty(stack)==false){
//         stack=popStr(stack,(char *)&a);
//         printf("%s\n",a);
//     }
//     return 0;
// }
