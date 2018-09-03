#include<stdio.h>
#include "linkedlistcircular.h"
int main(){
    listPointer * list=NULL;
    insertFront(&list,1);
    insertFront(&list,2);
    //printAll(&list);
    insertEnd(&list,3);
    printAll(&list);
    printf("\n%d\n",deleteFront(&list));
    printf("\n%d\n",deleteEnd(&list));
    printAll(&list);
}