#include<iostream>
#include<queue>
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
    node* head;
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
}


void print(tree* bin)
{
    queue <node*> q;
 
    node *dummy;
    dummy = (node*) malloc(sizeof(node));
    dummy->value=-1;
    dummy->left=NULL;
    dummy->right=NULL;
    
    q.push(bin->head);
    
    
    while(!q.empty())
    {
        q.push(dummy); 
		while(q.front()->value!=-1)
        {  
			if(q.front()->left!=NULL)
            {
                q.push(q.front()->left);
            }
 
            if(q.front()->right!=NULL)
            {
                q.push(q.front()->right);
            }
                        
            cout<<q.front()->value<<" ";  
            q.pop(); 
       }
        
        cout<<endl;
        q.pop();
    }
}

int main()
{
	 
	tree* bin;
	bin = (tree*) malloc(sizeof(tree));
	 
	node*n;
	n = (node*) malloc(sizeof(node));
	 
	n->value = 3;
	n->left =NULL;
	n->right = NULL;
	 
	bin->head = n;
	 
	node*m;
	m = (node*) malloc(sizeof(node));
	
	m->value = 2;
	m->left =NULL;
	m->right = NULL;
	
	n->left = m;
	
	node*b;
	b = (node*) malloc(sizeof(node));
	
	b->value = 4;
	b->left =NULL;
	b->right = NULL;
	
	n->right = b;
	
	node*c;
	c = (node*) malloc(sizeof(node));
	
	c->value = 5;
	c->left =NULL;
	c->right = NULL;
	
	b->right = c;
	
	print(bin);
	return 0;
}                       
