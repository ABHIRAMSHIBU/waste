//created by Abin Shoby R3,31006
//Binary search tree
#include<stdio.h>
#include<stdlib.h>
typedef struct node{//definition of node
	int key;
	struct node *l;
	struct node *r;
}node;

node *root;//root node
void display(node *nd){//display the status

	if(nd){
		printf("\n %d ",nd->key);
		if(nd->l)
			display(nd->l);
		if(nd->r)
			display(nd->r);
	}
	else
		printf("\n Tree has no element");
}
	
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
node *find_pos(node *nd,int x){//finds the adress of a key
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
node * find_ip(node *nd){//find inorder predecessor if present otherwise return the same
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
node *find_parent(node *start,node *x){//find parent of a child
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
	
	

void remove_bst(node *nd){//removes a node
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

			
		
void main(){
	int ch,key;
	node *p,*k;
	do{
		printf("\n 1.insert 2.remove 3.search 4.exit");
		scanf("%d",&ch);
		if(ch==1){
			printf("\n Enter the element:");
			scanf("%d",&key);
			insert(key);
			printf("\n current status");
			display(root);
		}
		else if(ch==2){
			printf("\n Enter the element to remove:");
			scanf("%d",&key);
			p=find_pos(root,key);
			
			if(p)
				remove_bst(p);
			else
				printf("\n key not found");
			printf("\n current status");
			display(root);

		}
		else if(ch==3){
			printf("\n Enter the element to search:");
			scanf("%d",&key);
			p=find_pos(root,key);
		
			if(p)
				printf("\n key found");
			else
				printf("\n key not found");

		}
		else;
	}while(ch!=4);
}
			
