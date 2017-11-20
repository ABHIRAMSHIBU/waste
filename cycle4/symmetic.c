/* Copyright (c) 2017 Abhiram Shibu
 * Tree mirror check
 * Tested on Arch Linux GCC version 7.2.0
 */

#include<stdio.h>
#include<malloc.h>

/* Local header files */
#include "color.h"
#include "stack.h"

/* Macro definitions */
#define True 1
#define False 0
#define Error -1
#define debug 1
#define VERSION 1.0
// A Binary Tree Node

/* Tree as a linked list */
typedef struct Node
{
    int key;
    struct Node* left, *right;
}Node;

/* Tree as an array test code */
 typedef struct {
    int * tree;                                     // Tree as an array
    int null;                                       // Defining what the null value is
}tree;

// Utility function to create new Node
Node * createNode(int key)
{
    Node *temp = malloc(sizeof(Node)) ;
    temp->key  = key;
    temp->left  = temp->right = NULL;
    return (temp);
}
int checkEven(int c){
    int returnValue=False;
    if(c%2==0)
        returnValue=True;
    else
        returnValue=False;
}

/* Check if a given choice is positive */
int checkPositive(char c){
    int returnValue=False;
    if(c=='y'|| c=='Y'|| c =='1'){
        returnValue=True;
    }
    else if(c=='n' || c=='N' || c=='0'){
        returnValue=False;
    }
    else{
        returnValue=Error;
    }
    return returnValue;
}
/* Initialize a tree with null bits... */
tree * treeInitialize(int n){
    tree * newTree=malloc(sizeof(tree));            // Manual memory allocation thus compiler wont free after this function.
    newTree->tree=malloc(sizeof(int)*(n+1));        // Manual dynamic memory allocation for tree as an array.
    *(newTree->tree + 0)=n;                         // First element in the tree is not the root node, it stores max size.
    newTree->null=-100000;                          // Define what a null value is !

    /* Write to all memory location from 0 to n null */
    for(int i=1;i<=n;i++){
        *(newTree->tree + i)=newTree->null;
    }
    return newTree;
}

/* Print tree to educated user until iI find a way to pictorically represent tree in C */
tree * displayTreeAsAray(tree A){
    for(int i=0;i<*(A.tree + 0);i++){
        printf("%d\t",*(A.tree + i));
    }
    printf("\n");
}

/* Get tree nodes from user with node number
 *       12
 *      /  \
 *     13  14
 *    /  \
 *   15  16
 * Will be represented as
 * -------------------
 * Index    |    Value
 * -------------------
 * 1        |       12
 * 2        |       13
 * 3        |       14
 * 4        |       15
 * 5        |       16
 * -------------------
 */
tree * getTreeAsNodeNumber(tree * A){
    /* Loop all array */
    char c;
    int leftChildFlag=1;
    int rightChildFlag=1;
    listPointer * stack;
    for(int i=1;i<=A->tree[0];i++){
        if(i==1){
            printf("Do you have a root node ?[y/Y/1/n/N/0]:");
            scanf("%c",&c);
            if(checkPositive(c)){
                printf("Enter a value for the root node [integer]:");
                scanf("%d",A->tree + 1);
            }
            else if(checkPositive(c)==Error){
                printf("%sInvalid input try again!\n%s",RED,RESET);
                i=0;                                                        // Reset i value to account for i++
            }
            else{
                printf("%sWarning:%s Tree is a null tree!%s\n",BLU,RED,RESET);
                break;
            }
        }
        else {
            if(checkEven(i))                                                 // Just for letting user know
                printf("Entering left node\n");
            else
                printf("Entering right node\n");
            printf("Do this node %d, exist?[y/Y/1/n/N/0]:",i);               // Get from user if the present node exists
            scanf("%d",&c);
            if(checkPositive(c)){                                            // Node exists
                printf("Enter a value for the %d node [integer]:",i);
                scanf("%d",A->tree + 1);                                     // Get data
                if(checkEven(i))                                             // Push left child to stack if there is no right child
                    push(&stack,i+1);
                i=i*2;                                                       // Go to child of current child aka parent
            }
            else if(checkPositive(c)==Error){                                // Input was invalid
                printf("%sInvalid input try again!\n%s",RED,RESET);
                i--;                                                         // Reset i value to account for i++
            }
            else{                                                            // {True, False, Error} - {True,Error} = {False}
                if(checkEven(i)){                                            // If its a leftChild push right child to stack to continue
                    leftChildFlag=0;
                    push(&stack,i+1);
                }
                else
                    rightChildFlag=0;
                int temp=0;
                temp=pop(&stack);                                            // Temp variable so that we dont lose that value
                if(temp!=Error){
                    i=temp-1;
                }
                printf("%sWarning:%s Some space will be null%s\n",BLU,RED,RESET);
                break;
            }
            if(i>A->tree[0]){
                printf("%sWarning:%s Max value of array aka tree reached continuing with stack value if there is any.%s\n",BLU,RED,RESET);
                int temp=pop(&stack);
                if(temp!=Error){
                    i=temp-1;
                }
            }
        }
    }
    return A;
}
/*
getTreeAsArray(tree *A, int n){

}*/
 
/* Checks if tree is a mirror */
int checkMirror(Node *tree1, Node *tree2){

    if (tree1 == NULL && tree2 == NULL)                                         // Check if tree  itself is a null tree then no need to check
        return True;
    if (tree1 && tree2 && tree1->key == tree2->key)                            // If everything is valid and is equal
        return (checkMirror(tree1->left, tree2->right) && checkMirror(tree1->right, tree2->left));                          // Recoursevly call itslf with next node as root on 2 children
    return False;
}
 
int main(){
    Node *tree = createNode(12);
    tree->left = createNode(13);
    tree->right = createNode(15);
    tree->left->left = createNode(16);
    tree->left->right = createNode(3);
    tree->right->left = createNode(3);
    tree->right->right = createNode(1);
    printf("So is it symmentric?...");
    if(checkMirror(tree,tree)){
        printf("Yup!\n");
    }
    else{
        printf("Not really!");
    }
    return 0;
}
