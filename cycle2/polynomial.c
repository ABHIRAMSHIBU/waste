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
 /* Substract operation*/
listPointer * subPolynomial(listPointer ** polynomial1, listPointer ** polynomial2){
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
            cfnt-=(current2->cfnt);
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
/* Find maximum power in a polynomial */
int maxPolynomial(listPointer * polynomial1){
    listPointer * current =polynomial1;
    int max=0;
    while(1){
        if((current->expt)>max){
            max=current->expt;
        }
        current=current->link;
        if(current==NULL){
            break;
        }
    }
    return(max);
}
/* Create an Empty Polynomial */
listPointer * createEmptyPolynomial(int power){
    listPointer * polynomialNew =NULL;
    listPointer * polynomialNewHead=NULL;
    int startFlag=1;
    for(int i=0;i<=power;i++){
        if(startFlag==1){
            insert(&polynomialNew,0,i);
            startFlag=0;
            polynomialNewHead=polynomialNew;
        }
        else{
            insert(&(polynomialNew->link),0,i);
            polynomialNew=polynomialNew->link;
        }
    }
    return(polynomialNewHead);
}
listPointer * polynomialMultiply(listPointer ** polynomial1, listPointer ** polynomial2){
    listPointer * current1, * current2,* polynomialNew,* polynomialNewHead;
    current1=* polynomial1;
    current2=* polynomial2;
    int maxpower = maxPolynomial(current1);
    int cfnt1,expt=0,cfnt=0;
    maxpower+= maxPolynomial(current2);
    current1=* polynomial1;
    current2=* polynomial2;
    polynomialNew=createEmptyPolynomial(maxpower);
    polynomialNewHead=polynomialNew;
    while(1){
        if(current1==NULL){
            break;
        }
        else{
            while(1){
                if(current2==NULL){
                    break;
                }
                else{
                    cfnt=(current1->cfnt)*(current2->cfnt);
                    expt=(current1->expt)+(current2->expt);
                    printf("\nEnponent final =%d, current1->cfnt:%d, current2->cfnt:%d\n",cfnt,current1->cfnt,current2->cfnt);
                    while(1){
                        if(expt==polynomialNew->expt){
                            polynomialNew->cfnt+=cfnt;
                            break;
                        }
                        polynomialNew=polynomialNew->link;
                    }
                    polynomialNew=polynomialNewHead;     //Reset polynomialNew
                    current2=current2->link;
                }
                printf("\nRAN!\n");
            }
            current1=current1->link;
            current2=* polynomial2;
        }
        printf("\nRAN!\n");
    }
    return polynomialNewHead;
}
int main(){
    listPointer * polynomial1=NULL, * polynomial2=NULL, * polynomialAns=NULL;
    inputPolynomial(&polynomial1);
    inputPolynomial(&polynomial2);
    printf("\nAddition answer\n");
    polynomialAns=addPolynomial(&polynomial1,&polynomial2);
    printAll(&polynomialAns);
    printf("\nSubstration answer\n");
    polynomialAns=subPolynomial(&polynomial1,&polynomial2);
    printAll(&polynomialAns);
    printf("\nMax power is :%d\n",maxPolynomial(polynomialAns));
    printf("\nMult answer\n");
    polynomialAns=polynomialMultiply(&polynomial1,&polynomial2);
    printAll(&polynomialAns);
    printf("\nPrinting empty polynomial\n");
    polynomialAns=createEmptyPolynomial(3);
    printAll(&polynomialAns);
    return 0;
}
