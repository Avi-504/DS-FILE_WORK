#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node*link;
}node;
void create(node* head)
{   printf("Enter no. of element\n"); 
	int n;
	scanf("%d",&n);
	 for (int i=0;i<n-1;i++)
	 {  printf("enter your %d element\n",i+1);	 	
	 	scanf("%d",&head->data);
	 	head->link=(node*)malloc(sizeof(node));
	 	head=head->link;
	 }
	 printf("enter your %d element\n",n);
	 scanf("%d",&head->data);
	 head->link=NULL;
}
void traverse(node*head)
{

	if(head)
	{
		printf("%d ",head->data);
		traverse(head->link);
		printf("\n");
	}

	
}
void instnode_at_p(node*head)
{
	node* new=NULL;
	node*temp;
	temp=head;
	new=(node*)malloc(sizeof(node));
	printf("Enter position of new element\n");
	int pos;
	scanf("%d",&pos);
	if(pos==1)
	{
		
		printf("enter new element\n");
		scanf("%d",&new->data);
		new->link=temp;
		head=new;
		temp=NULL;
	}
	else{
	for(int i=1;i<pos-1;i++)
		{
			temp=temp->link;
		}	
	
	printf("enter new element\n");
	scanf("%d",&new->data);
	new->link=temp->link;
	temp->link=new;
	}traverse(head);		
}
void instnode_af_data(node*head)
{
	node*temp=head;
	printf("ENTER ELEMENT AFTER WHICH A NEW ELEMENT IS TO BE ADDED FOLLOWED BY NEW ELEMENT\n");
	int old;
	scanf("%d",&old);
	while(temp->data!=old)
	{
		temp=temp->link;
		
	}
	if(temp)
	{
	node*new1=(node*)malloc(sizeof(node));
	printf("enter new element");
	scanf("%d",&new1->data);
	new1->link=temp->link;
	temp->link=new1;
	traverse(head);
	}
}
int main()
{
	node*head=NULL;
	head=(node*)malloc(sizeof(node));
	create(head);
	traverse(head);
	instnode_at_p(head);
	instnode_af_data(head);
	return 0;
}