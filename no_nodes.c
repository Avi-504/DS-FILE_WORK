#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;
struct node* crt_tree()
{
	int x;
	node *root=(node*)malloc(sizeof(node));
	printf("Enter the data for the nodes(-1 if it is a leaf node)\n");
	scanf("%d",&x);
 	if(x==-1)	
    	 return NULL;
  	root->data=x;
    printf("Enter the left child data for node named %d \n",root->data);
    root->left=crt_tree();
    printf("Enter the right child data for node named %d\n",root->data);      
    root->right=crt_tree();
    return root;

}
int no_nodes(node*temp)
{
	if (temp)
	{
		return 1+no_nodes(temp->left)+no_nodes(temp->right);
	}
	else
		return 0;
}
int main()
{
	node *mroot=crt_tree();
	node *temp=mroot;
	printf("No. of nodes in tree is \n");
	int num=no_nodes(temp);
	printf("%d\n",num);
	return 0;
}