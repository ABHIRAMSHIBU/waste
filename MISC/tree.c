#include<stdio.h>
#include "tree.h"

int main(){
    listPointer * head;
    insert(&head,NULL,10);
    listPointer * currentNode=head;
    for(int i=9;i>-1;i--){
        insert(&(currentNode->left),&currentNode,i);
        currentNode=currentNode->left;
    }
    currentNode=head;
    for(int i=20;i<=41;){
        insert(&(currentNode->right),&currentNode,i);
        currentNode=currentNode->right;
        i=i+2;
    }
    currentNode=head->right;
    for(int i=21;i<41;){
        insert(&(currentNode->left),&currentNode,i);
        currentNode=currentNode->right;
        i=i+2;
    }
    insert(&(head->right->left),&head->right,11);
    printf("\nLast left:%p right:%p\n",head->left->left->left->left->left->left->left->left->left->left->left,head->right);
    inorder(&head);
    return 0;
}
