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
int no_lf(node*temp)
{
	if(temp==NULL)
		return 0;
	if (temp->left==NULL && temp->right==NULL)
	{
		return 1;
	}
	
	else
		return no_lf(temp->left)+no_lf(temp->right);
}
int no_nlf(node*temp)
{
	if(temp==NULL)
		return 0;
	if (temp->left!=NULL || temp->right!=NULL)
	{		
		return 1+no_nlf(temp->left)+no_nlf(temp->right);
	}
	else
		return 0;	
}
int main()
{
	node *mroot=crt_tree();
	node *temp=mroot;
	printf("No.of leaf nodes in tree is \n");
	int num=no_lf(temp);
	printf("%d\n",num);
	printf("No. of Non leaf nodes in tree is\n");
	int num1=no_nlf(temp);
	printf("%d\n",num1);
	return 0;
}