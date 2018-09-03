/* Author Abhiram Shibu
 * Copyright 2017
 * Depend : GCC(Tested on ArchLinux v7)*/
#include<stdio.h>
#include "linkedlistpoly.h"
#define True 1
#define False 0
/* Get polynomial function */
void inputPolynomial(listPointer ** head){
    int c,buff,startFlag=1;
    listPointer * currentPointer;
    listPointer  * mainPointer;
    printf("Enter the max degree of the polynomial :");
    scanf("%d",&c);
    for(int i=0;i<=c;i++){
        printf("Enter coefficient for degree-%d:",i);
        scanf("%d",&buff);
        if(buff!=0){
            if(startFlag==1){
                insert(&currentPointer,buff,i);
                mainPointer=currentPointer;
                startFlag=0;
            }
            else{
                insert(&(currentPointer->link),buff,i);
                currentPointer=currentPointer->link;
            }
        }
    }getchar();
    (*head)=mainPointer;
}
/*Start of all arethmatic operations 
 * Add operation*/
listPointer * addPolynomial(listPointer ** polynomial1, listPointer ** polynomial2){
    listPointer * current1, * current2,* polynomialNew,* polynomialNewHead;
    current1=* polynomial1;
    current2=* polynomial2;
    int expt=0,cfnt,current1Flag=True,current2Flag=True,startFlag=True,insertOKflag=False;
    while(True){
        if(current1->expt==expt && current1Flag==True){
            insertOKflag=True;
            cfnt=current1->cfnt;
            if(current1->link==NULL){
                current1Flag=False;
            }
            else{
                current1=current1->link;
            }
        }
        if(current2->expt==expt && current2Flag==True){
            insertOKflag=True;
            cfnt+=(current2->cfnt);
            if(current2->link==NULL){
                current2Flag=False;
            }
            else{
                current2=current2->link;
            }
        }
        if(insertOKflag=True){
            insertOKflag=False;
            if(startFlag==True){
                insert(&polynomialNew,cfnt,expt);
                startFlag=False;
                polynomialNewHead=polynomialNew;
            }
            else{
                insert(&(polynomialNew->link),cfnt,expt);
                polynomialNew=polynomialNew->link;
            }
        }
        if(current1Flag==False && current2Flag==False){
            break;
        }
        expt++;
        cfnt=0;
    }
    return(polynomialNewHead);
}
int main(){
    listPointer * polynomial1, * polynomial2, * polynomialAns;
    inputPolynomial(&polynomial1);
    inputPolynomial(&polynomial2);
    polynomialAns=addPolynomial(&polynomial1,&polynomial2);
    printAll(&polynomialAns);
    return 0;
}
