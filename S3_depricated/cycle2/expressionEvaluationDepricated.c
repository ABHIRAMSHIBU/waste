#include<stdio.h>
#include<malloc.h>
#include "stack.h"
int checkOperant(char a){
    printf("Char is :%c\n",a);
    if(a!='*' && a!='/' && a!='-' && a!='+' && a!=')' && a!='('){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    listPointer * list=NULL;
    listPointer * stack=NULL;
    int c,i=0;
    char *a,temp;
    printf("Enter how much bytes to allocates :");
    scanf("%d",&c);
    a=malloc(sizeof(char)*c);
    printf("Enter expression:");
    scanf("%s",a);
    printf("Entered expression :%s\n",a);
    while(a[i]!='\0'){
        if(checkOperant(a[i])){
            printf("Operant found:%c\n",a[i]);
            insertEnd(&list,a[i]);
            printAllChar(&list);
            printf("\n");
        }
        else if(a[i]=='('){
            printf("( found %c\n",a[i]);
            push(&stack,a[i]);
        }
        else if(a[i]==')'){
            printf(") %c\n",a[i]);
            temp=pop(&stack);
            insertEnd(&list,temp);
            while(temp!='('){
                temp=pop(&stack);
                insertEnd(&list,temp);
            }
        }
        else if(!checkOperant(a[i])){
            printf("Operator found:%c\n",a[i]);
            temp=pop(&stack);
            switch(temp){
                case '(' : push(&stack,temp);break;
                case ')' : push(&stack,temp);break;
                case '/' :if(a[i]=='(' || a[i]==')' || a[i]=='/') { push(&stack,a[i]);insertEnd(&list,temp);} else{insertEnd(&list,a[i]);}break;
                case '*' :if(a[i]=='(' || a[i]==')' || a[i]=='/' || a[i]=='*' ) {push(&stack,a[i]);insertEnd(&list,temp);} else{insertEnd(&list,a[i]);}break;
                case '+' :if(a[i]=='(' || a[i]==')' || a[i]=='/' || a[i]=='*' || a[i]=='+' ) {push(&stack,a[i]);insertEnd(&list,temp);} else{insertEnd(&list,a[i]);}break;
                case '-' :if(a[i]=='(' || a[i]==')' || a[i]=='/' || a[i]=='*'|| a[i]=='+' || a[i]=='-' ) {push(&stack,a[i]);insertEnd(&list,temp);} else{insertEnd(&list,a[i]);}break;
                case -1 :push(&stack,a[i]);printf("RAN!");
            }
        }
        if(a[i+1]=='\0'){
            printf("Empty stack sequence\n");
            temp=pop(&stack);
                while(temp!=-1){
                insertEnd(&list,temp);
                temp=pop(&stack);
            }
        }
        i++;
    }
    printAllChar(&list);
//     insertFront(&head,1);
//     insertFront(&head,2);
//     printf("\n%d\n",deleteEnd(&head));
//     printf("\n%d\n",deleteEnd(&head));
//     printf("\n%d\n",deleteEnd(&head));
}
