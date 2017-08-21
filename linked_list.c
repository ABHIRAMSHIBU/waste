#include<stdio.h>
#include<malloc.h>
typedef struct 
{
	int key;
	struct node *next;
}node;
node * create_head()
{
	node *head;
	head=malloc(sizeof(node));
	head->next=NULL;
	//printf("%p",head);
	return head;
}
node *insert_key(node *A, int key)
{
	node *temp;
	temp=malloc(sizeof(node));
	temp->next=NULL;
	A->next=temp;
	A->key=key;
	return A;
}
node *insert_into(node *A,int key)
{
	
}
void print_all(node *A)
{
	printf("Output starts!\n");
	node *current_node=A;
	node *next_node=NULL;
	while(1)
	{
		if(current_node->next==NULL)
		{
			break;
		}
		printf("%d\n",current_node->key);
		next_node=current_node->next;
		current_node=next_node;
	}
}
int main()
{
	node *head;
	node *temp;
	int key;
	head=create_head();
	temp=head;
	for(int i=0;i<5;i++)
	{
		printf("\nEnter the key :");
		scanf("%d",&key);
		temp=insert_key(temp,key);
		temp=temp->next;
	}
	print_all(head);
	//printf("%p",head);
	return 0;
}
