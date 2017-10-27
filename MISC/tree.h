/* Header file tree - Binary tree
 * Author  Abhiram Shibu - https://github.com/ABHIRAMSHIBU
 * Copyright (c) 2017 Team Destroyer */
/* All depricated will be removed in the future */
#include<malloc.h>
#define True 1
#define False 0
/* Main node */
typedef struct listNode{
	int data;
	struct listNode * left, * right, * prev;
}listPointer;

/* Try to insert a node  */
int insert(listPointer ** tree, listPointer ** prev,int data){
	listPointer * temp;
	temp=malloc(sizeof(listPointer));
    if(temp==NULL){
        return -1;
    }
	temp->left=NULL;
	temp->right=NULL;
    if(prev==NULL)
        temp->prev=NULL;
    else
        temp->prev=* prev;
	(*tree)=temp;
	(*tree)->data=data;
    return 0;
}
/* IN oder traversal depricated
int inorder(listPointer ** tree){
    listPointer nodeCurrent=* tree
    int leftflag=1;
    int rightflag=0;
    int roothitflag=0;
    listPointer nodePrevPrint=NULL;
    while(1){
        if(leftflag=1){
            if (nodeCurrent->left==NULL){
                roothitflag=1;
            }
            else{
                
            }
        }
    }
}*/

/* Inorder traversal */
int inorder(listPointer ** tree){
    /* Recursive function traverse */
    void traverse(listPointer ** node){
        if(*node==NULL)                               //Node null exception, when parent has no children
            return;
        /* Code segment not needed as its handled as a sideeffect */
        /*if(((*node)->left)==NULL && ((*node)->right)==NULL){
            printf("\n%d\n",(*node)->data);
            return;
        }*/
        if(((*node)->left)!=NULL){               //Node  left traverse if exists
            traverse(&((*node)->left));
            printf("\n%d\n",(*node)->data);  //Print to screen 
            traverse(&((*node)->right));
        }
        else {                                               //Left node dont exist, traverse right
            printf("\n%d\n",(*node)->data);
            traverse((&(*node)->right));
        }
        return;                                            //Return after all siblings are dead(i mean printed)
    }
    traverse(tree);   //First call of traverse
    return 0;
}
