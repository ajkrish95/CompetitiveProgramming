#include<stdio.h>
#include<iostream>
#include<malloc.h>

using namespace std;
struct node
{
	int value;
	node* left;
	node* right;
};

struct tree
{
	node* root;
};

void inorder(node * n)
{	
	if(n->left!=NULL)
	{
		inorder(n->left);
	}

	cout<<n->value<<" ";
	
	if(n->right!=NULL)
	{
		inorder(n->right);
	}	
	
	cout<<endl;
}

void preorder(node * n)
{	
	
	cout<<n->value<<endl;
	
	if(n->left!=NULL)
	{
		cout<<"hhh\n";
		preorder(n->left);
	}
	
	if(n->right!=NULL)
	{
		cout<<"jjj\n";
		preorder(n->right);
	}	
}

void postorder(node * n)
{	
	if(n->left!=NULL)
	{
		postorder(n->left);
	}
	
	if(n->right!=NULL)
	{
		postorder(n->right);
	}	

	cout<<n->value<<endl;
}

tree* insert(tree* tree,int num)
{
	int ct;
	node* n= tree->root;
	node* m,*rem;
	m= (node*) malloc(sizeof(node));
	m->left=NULL;
	m->right=NULL;
	m->value = num;

	if(n==NULL)
	{
		tree->root=m;
		return tree;		
	}
	
	while(n!=NULL)
	{
		if(n->value > num)
		{
			rem = n;
			n=n->left;
			ct = -1;
			
		}
		
		else
		{
			rem = n;
			n=n->right;
			ct=1;
		}
	}
	
	if(ct==1)
	{
		rem->right = m;
	}
	
	else
	{
		rem->left = m;
	}
	
	
	return tree;
}
int main()
{
	tree* tre;
	tre = (tree*)malloc(sizeof(tree));
	tre->root = NULL;
	
	tre=insert(tre,10) ;

	tre=insert(tre,9) ;
	

	tre=insert(tre,12) ;

	tre=insert(tre,0) ;

	tre=insert(tre,-2);

	inorder(tre->root); 
	
}

