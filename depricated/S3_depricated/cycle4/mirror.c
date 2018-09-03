//created by Abin Shoby,R3,31006
//MIRROR OF A TREE

#include<stdio.h>
#include<stdlib.h>

/**Data Structure Declarations**/
typedef struct node{//node of the tree
	int key;
	struct node *l;
	struct node *r;
}node;
node *root;//root of a tree
node *q[10];//queue for storing the nodes upto full binary tree level

/**initialization**/
int front=0;
int rear=0;

/***Operations on datastructures***/
void inorder(node *nd){//for inorder traversal
	if(nd){
		inorder(nd->l);
		printf("\n %d",nd->key);
		inorder(nd->r);
	}
}
void preorder(node *nd){//for preorder traversal
	if(nd){
		printf("\n %d",nd->key);
		preorder(nd->l);
		preorder(nd->r);
	}
}
node* create_node(int key)//to create a node and initialize with key value
{
    node* nd = (node*)malloc(sizeof(node));
    nd->key = key;
    nd->l  =  nd->r  = NULL;
    return(nd);
}

void enq(node *x){//for inserting to queue
	if((rear%9+1==front)){
		printf("\n full");
	}
	else{
		rear=rear%9+1;
		if(front==0)
			front=1;
		q[rear]=x;
	}
}
node * deq(){//for deletion in a queue
	node *x;
	if(front==0)
		return NULL;
	else{	x= q[front];
		if(front==rear)
			front=rear=0;
		else
			front=front%9+1;//max index 9
		return x;
	}
}
	
void insert( node* temp, int key)//for insertion in a binary tree
{
	if(root==NULL){
		root=create_node(key);//no element so insert as root
	}
	else{
   
    		enq(temp);
   
    		while (front) {//stores the level upto full binary tree state
        		 node* temp = deq();
       			 if (!temp->l) {
           			 temp->l = create_node(key);//insert node
           			 break;
       			 } 
			else
          		  enq(temp->l);
 
      		       if (!temp->r) {
           			 temp->r = create_node(key);
           			 break;
       			 } 
			else
            			enq(temp->r);
   		 }
	}
}

/**  Implementation of target **/
int check_mirror(node *l,node *r){//check whether the tree and its mirror image are same
	if(l==NULL &&r==NULL)
		return 1;
	if(l==NULL || r==NULL)
		return 0;
	if(l->key==r->key &&check_mirror(l->l,r->r) && check_mirror(l->r,r->l))
		return 1;
	else
		return 0;
}


void main(){
	int f,ch,key;
	
	do{
		printf("\n 1.Insert 2.check mirror 3.exit \n Enter your choice:");
		scanf("%d",&ch);
		if(ch==1){
			printf("\n Enter the key value:");
			scanf("%d",&key);
			insert(root,key);
			printf("\n Current status:");
			printf("\n Inorder traversal");
			inorder(root);
			printf("\n Preorder traversal");
			preorder(root);
		}
		else if(ch==2){
			
 			f=check_mirror(root->l,root->r);
			printf("\n The tree and it's image are");
			if(f==1)
				printf(" same");
			else
				printf(" not same");
		}
		else;
	}while(ch!=3);
}
