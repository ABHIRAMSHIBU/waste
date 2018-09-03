/* No copyright info
 * Owner Abhiram Shibu
 */
#include<stdio.h>
#include<stdlib.h>
#include "color.h"
/* Type definition of node */
typedef struct node{
	int key;
	struct node *l;
	struct node *r;
}node;

node *root;

/* Display function */
void display(node *nd){

	if(nd){
		printf("\n %d \n",nd->key);
		if(nd->l)
			display(nd->l);
		if(nd->r)
			display(nd->r);
	}
	else
		printf("\n%sWarning:%sTree is NULL%s\n",BLU,RED,RESET);
}

/* Fuction to search */
node * search(int x,node *nd,node *parent){//search the parent of inserting element
	
	if(nd==NULL){
		return parent;
	}
	parent=nd;
	if(nd->key>x){   //the key can be either less than or greater than root
		search(x,nd->l,parent);
	}
	else 
		search(x,nd->r,parent);
	
}

/* Function to insert an element to a tree */
void insert(int x){//insert an element
	node *temp;
	if(root==NULL){//initial state when tree empty
		root=(node*)malloc(sizeof(node));
		root->key=x;
	}
	else{
		node *p=search(x,root,root);
		temp=(node*)malloc(sizeof(node));
		temp->key=x;
		if(p->key>x){//check for left or right position
			
			
			p->l=temp;
		}
		else{
			p->r=temp;
		}
	}
}

/* Returns the index of a key */
node *find_pos(node *nd,int x){
	if(nd){	
		if(nd->key==x)
			return nd;
		if(nd->l && x<nd->key)
			return(find_pos(nd->l,x));
		
		if(nd->r && x>nd->key)
			return(find_pos(nd->r,x));
	}
	else
		return NULL;
}

/* Returns inorder predecessor */
node * find_ip(node *nd){
	node *temp=nd;
	if(nd->l){
		temp=nd->l;
		while(temp->r){
			temp=temp->r;
		}
	}
	else
		temp=nd;
	return temp;
}

/* Returns parent of a child */
node *find_parent(node *start,node *x){
	node *temp=start;
	if(x==start)
		return NULL;
	if(temp->l==x || temp->r==x)
		return temp;
	if(x->key<temp->key)
		find_parent(temp->l,x);
	if(x->key>temp->key)				
		find_parent(temp->r,x);
}
	
	
/* Removes a node */
void remove_bst(node *nd){
	int temp;
	node *par;
	
	if(nd==root&& root->l==NULL && root->r==NULL){//single node case
		free(root);
		root=NULL;
	}
	else{
		
		node *ip=find_ip(nd);
		
	 	temp=nd->key;       //swap inorder predecessor and the element
		nd->key=ip->key;
		ip->key=temp;
		par=find_parent(root,ip);
		if(ip->r){                  //check if the inorder predecessor has a right node
			temp=ip->r->key;
			ip->key=temp;
			free(ip->r);        //swap right node with inorder predecessor and free the right node
			ip->r=NULL;
		}
		else{
		
			
			if(par)
			 {
				if(par->r==ip)
					par->r=NULL;
				else
					par->l=NULL;
			}
	
			free(ip);
		}
	}
	
}

/* Driver Main */
void main(){
	int ch,key;
	node *p,*k;
	do{
                printf("%s------------------MAIN MENU------------------%s",RED,RESET);
		printf("%s\n1)Insert \n2)Remove \n3)Search \n4)Exit%s\n",GRN,RESET);
                printf("%s---------------------------------------------%s\n",RED,RESET);
                printf("Enter an option:");
		scanf("%d",&ch);
		if(ch==1){
			printf("\nEnter an element:");
			scanf("%d",&key);
			insert(key);
			printf("\nCurrent Status\n   ");
			display(root);
		}
		else if(ch==2){
			printf("\nEnter an element to remove:");
			scanf("%d",&key);
			p=find_pos(root,key);
			
			if(p)
				remove_bst(p);
			else
				printf("\nKey not found");
			printf("\nCurrent Status\n");
			display(root);

		}
		else if(ch==3){
			printf("\nEnter an element to search:");
			scanf("%d",&key);
			p=find_pos(root,key);
		
			if(p)
				printf("%s\nKey found%s\n",GRN,RESET);
			else
				printf("%s\nKey not found%s\n",RED,RESET);

		}
		else;
	}while(ch!=4);
}
