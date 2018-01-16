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
node *insert_into_depricated(node *A,int key)
{
	node *temp,*temp2;
	temp=A->next;
	A->next=malloc(sizeof(node));
	printf("\nMemory saved:%p and %p \n",temp,A->next);
	A=insert_key(A->next,key);
	temp2=A->next;
	free(temp2->next);
	temp2->next=temp;
	printf("\n New Memory allocated : %p  Old memory :%p\n",A->next,temp2->next);
	return A;
}
node *insert_into(node *A,int key)
{
	node *temp,*temp2;
	temp=malloc(sizeof(node));
	temp=insert_key(temp,key);
	free(temp->next);
	temp2=A;
	A=temp;
	A->next=temp2;
	return A;
}
node *delete(node *A)
{
	node *temp;
	temp=A->next;
	free(A);
	A=temp;
	return A;
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
node *search(node *A,node *B,int key)
{
	//printf("Output starts!\n");
	node *current_node=A;
	node *next_node=NULL;
	int count=0;
	node *return_node=B;
	node *return_head=return_node;
	node *temp;
	while(1)
	{
		count++;
		if(current_node->next==NULL)
		{
			return_node->next=NULL;
			break;
		}
		if(current_node->key==key)
		{
			//printf("\nRAN\n");
			return_node->key=count;
			return_node->next=malloc(sizeof(node));
			temp=return_node->next;
			return_node=temp;
		}
		//printf("\n Memory address of return :%p, count :%d\n",return_node,count);
		//printf("%d\n",current_node->key);
		next_node=current_node->next;
		current_node=next_node;
	}
	return(return_head);
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
	head->next=insert_into(head->next,200);
	print_all(head);
	printf("\nDeleting first element\n");
	head=delete(head);
	print_all(head);
	temp=malloc(sizeof(node));
	printf("Enter key to search:");
	scanf("%d",&key);
	printf("Searching for all occurences of %d\n",key);
	temp=search(head,temp,key);
	print_all(temp);
	//printf("%p",head);
	return 0;
}
