/* Copyright (C) 2017 Abhiram Shibu
 * Copyright (C) 2017 Team Destroyer
 */
#include<stdio.h>
#include<malloc.h>
#include "stack.h"
int checkOperant(char a){
//     printf("Char is :%c\n",a);
    if(a!='*' && a!='/' && a!='-' && a!='+' && a!=')' && a!='('){
        return 1;
    }
    else{
        return 0;
    }
}
int infixToPostfix(){
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
//             printf("Operant found:%c\n",a[i]);
               insertEnd(&list,a[i]);
//             printAllChar(&list);
//             printf("\n");
        }
        else if(a[i]=='('){
//             printf("( found %c\n",a[i]);
            push(&stack,a[i]);
//             printf("Pushed!,%d",i);
        }
        else if(a[i]==')'){
//             printf(") %c\n",a[i]);
//             printf("\nTrying pop!.%d\n",i);
//             temp=pop(&stack);
//             insertEnd(&list,temp);
            temp=')';
            while(temp!='('){
                temp=pop(&stack);
                //printf("\nPOPED EVEMENT %c",temp);
                if(temp!='('){
                insertEnd(&list,temp);
                }
            }
        }
        else if(!checkOperant(a[i])){
//             printf("Operator found:%c\n",a[i]);
            start:
            temp=pop(&stack);
            switch(temp){
                case '(' : push(&stack,temp);push(&stack,a[i]); break;
                case '/' :if(a[i]=='+'|| a[i]=='-') { push(&stack,temp);push(&stack,a[i]);} else{insertEnd(&list,temp);goto start;}break;
                case '*' : if(a[i]=='+'|| a[i]=='-' ) {push(&stack,temp);push(&stack,a[i]);} else{insertEnd(&list,temp);goto start;}break;
                case '+' :if(0) {push(&stack,temp);push(&stack,a[i]);} else{insertEnd(&list,temp);goto start;}break;
                case '-' :if(0) {push(&stack,temp);push(&stack,a[i]);} else{insertEnd(&list,temp);goto start;}break;
                case -1 :push(&stack,a[i]);
            }
        }
        if(a[i+1]=='\0'){
//             printf("Empty stack sequence\n");
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
int infixToPrefix(){
    listPointer * list=NULL;
    listPointer * stack=NULL;
    listPointer * revStack=NULL;
    int c,i=0;
    char *a,temp;
    printf("Enter how much bytes to allocates :");
    scanf("%d",&c);
    a=malloc(sizeof(char)*c);
    printf("Enter expression:");
    scanf("%s",a);
    printf("Entered expression :%s\n",a);
    temp=a[i];
    while(temp!='\0'){
        if(temp=='(')
            temp=')';
        else if(temp==')')
            temp='(';
        push(&revStack,temp);
        i=i+1;
        temp=a[i];
    }
    i=0;
    temp=pop(&revStack);
    while(temp!=-1){
        a[i]=temp;
        temp=pop(&revStack);
        i+=1;
    }
    i=0;
    while(a[i]!='\0'){
        if(checkOperant(a[i])){
//             printf("Operant found:%c\n",a[i]);
               insertEnd(&list,a[i]);
//             printAllChar(&list);
//             printf("\n");
        }
        else if(a[i]=='('){
//             printf("( found %c\n",a[i]);
            push(&stack,a[i]);
//             printf("Pushed!,%d",i);
        }
        else if(a[i]==')'){
//             printf(") %c\n",a[i]);
//             printf("\nTrying pop!.%d\n",i);
//             temp=pop(&stack);
//             insertEnd(&list,temp);
            temp=')';
            while(temp!='('){
                temp=pop(&stack);
                //printf("\nPOPED EVEMENT %c",temp);
                if(temp!='('){
                insertEnd(&list,temp);
                }
            }
        }
        else if(!checkOperant(a[i])){
//             printf("Operator found:%c\n",a[i]);
            start:
            temp=pop(&stack);
            switch(temp){
                case '(' : push(&stack,temp);push(&stack,a[i]); break;
                case '/' :if(a[i]=='+'|| a[i]=='-') { push(&stack,temp);push(&stack,a[i]);} else{insertEnd(&list,temp);goto start;}break;
                case '*' : if(a[i]=='+'|| a[i]=='-' ) {push(&stack,temp);push(&stack,a[i]);} else{insertEnd(&list,temp);goto start;}break;
                case '+' :if(0) {push(&stack,temp);push(&stack,a[i]);} else{insertEnd(&list,temp);goto start;}break;
                case '-' :if(0) {push(&stack,temp);push(&stack,a[i]);} else{insertEnd(&list,temp);goto start;}break;
                case -1 :push(&stack,a[i]);
            }
        }
        if(a[i+1]=='\0'){
//             printf("Empty stack sequence\n");
            temp=pop(&stack);
                while(temp!=-1){
                insertEnd(&list,temp);
                temp=pop(&stack);
            }
        }
        i++;
    }
    while(True){
        temp=pop(&list);
        if(temp==-1)
            break;
        else
            push(&revStack,temp);
    }
    printAllChar(&revStack);
//     insertFront(&head,1);
//     insertFront(&head,2);
//     printf("\n%d\n",deleteEnd(&head));
//     printf("\n%d\n",deleteEnd(&head));
//     printf("\n%d\n",deleteEnd(&head));
}
int main(){
    int c;
    printf("%s____________MAIN MENU_____________%s\n",RED,RESET);
    printf("%s1) Infix to Postfix convertor%s\n",GRN,RESET);
    printf("%s2) Infix to Prefix convertor%s\n",GRN,RESET);
    printf("%s__________________________________%s\n",RED,RESET);
    printf("Choose an option:");
    scanf("%d",&c);
    if(c==1)
        infixToPostfix();
    else if(c==2)
        infixToPrefix();
    else
        printf("%sInvalid option!\n%s",RED,RESET);
}
