/* No copyright info
 * Owner Abhiram Shibu
 */
#include<stdio.h>
#include<stdlib.h>
#include "color.h"
typedef struct node{
	int key;
	int v;
}node;

node *adjl[100][100];

int q[100];

int head=-1;int tail=-1;

int n=0;

/* Enquee */
void enq(int el){
	tail++;
	if(tail==99){
		printf("\n full");
		tail--;
	}
	else{

		if(head==-1){
			head=0;
		}
		q[tail]=el;
	}
}

/* Dequee */
int dequeue(){
	int x;
	if(head==-1)
		printf("\n empty");
	else{
		x=q[head];
		if(head==tail)
			head=tail=-1;
		else
			head++;
		return x;
	}
}

/* Enforce relation */
void set_conn(){
	int i,j,c;
	
	printf("\nEnter 0 for no relation and 1 for relation\n");
	for(i=1;i<=n;i++)
		printf("\t%d",adjl[0][i]->key); //display the vertices at header
	for(i=1;i<=n;i++){
		printf("\n%d",adjl[i][0]->key);
		for(j=1;j<=n;j++){
			printf("\t");
			
			scanf("%d",&c);
			if(c==1)
				adjl[i][j]=adjl[i][0];//store the adress for the relation
			else
				adjl[i][j]=NULL;//make null for non related
			
		}
	}
}

/* Insert into graph */
void insert(int key){//adding vertices to adjacency matrix
	node *temp;
	n++;
	if(n<100){
		temp=(node *)malloc(sizeof(node));
		temp->key=key;
		adjl[n][0]=temp;
		adjl[0][n]=temp;
	}
	else{
		n--;
		printf("\n%sFull!%s",RED,RESET);
	}
	
	
}

/* DFS Visit function */
void dfsvisit(int u){
	int i;
	adjl[u][0]->v=1;//mark visited
	printf("\n %d",adjl[u][0]->key);
	for(i=1;i<=n;i++){
		if(adjl[u][i]){
			if(adjl[0][i]->v==0)
				dfsvisit(i);
			adjl[u][0]->v=2;//sub graph of the vertex completed
		}
	}
}


/* DFS For REAL! */
void dfs(){ 
	int i;
	for(i=1;i<=n;i++)
		adjl[i][0]->v=0;         //Did not visit
	for(i=1;i<=n;i++)
	{
		if(adjl[i][0]->v==0)
			dfsvisit(i);
	}
}

/* BFS */
void bfs(int s){
	int i,u;
	for(i=1;i<=n;i++){
		if(i!=s)
			adjl[i][0]->v=0;
	}
	printf("\n %d",adjl[s][0]->key);
	adjl[s][0]->v=1;//mark visited 
	enq(s);
	
	while(tail>=0){
		u=dequeue();
		for(i=1;i<=n;i++){
			if(adjl[u][i]!=NULL){
				if(adjl[0][i]->v==0){
					printf("\n %d",adjl[0][i]->key);
					adjl[0][i]->v=1;//mark visited
					enq(i);
				}
				adjl[u][0]->v=2;//sub graph of the vertex complete
			}
		}
	}
}

/* Find id */
int find_sourceid(int key){
	int i;
	for(i=1;i<=n;i++){
		if(adjl[i][0]->key==key)
			return i;
	}
}

void main(){
	int ch,key,no,i,j,s;
	do{
                printf("\n%s-----------------MAIN MENU----------------",RED);
		printf("\n%s1)Insert \n2)DFS \n3)BFS \n4)exit \n",GRN);
                printf("%s------------------------------------------\n%s",RED,RESET);
                printf("Enter an option:");
		scanf("%d",&ch);
		if(ch==1){
			printf("\nEnter no of keys:");
			scanf("%d",&no);
			for(i=0;i<no;i++){
				printf("\nEnter key:");
				scanf("%d",&key);
				insert(key);
			}
			set_conn();
			
			
		}
		else if(ch==2)
			dfs();
		else if(ch==3){
			printf("\nEnter source:");
			scanf("%d",&key);
			s=find_sourceid(key);
			bfs(s);
		}
		else
			;
	}while(ch!=4);
}

