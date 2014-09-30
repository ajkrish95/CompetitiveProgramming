#include<iostream>
#include<malloc.h>

using namespace std;

struct node1
{
    int value;
    node1* next;
    node1* prev;
};

struct node2
{
    int value;
    node2* left;
    node2* right;
};

struct dll
{
    node1* start;
} ;   

struct tree
{
    node2* head;
};

node1 *p1,*p2;

using namespace std;

dll* inorder(node2* n)
{
	node1 *temp; 
	dll *l,*l1;
	
	node1 *n2;
    n2 = (node1*)malloc(sizeof(node1));
    n2->value = n->value;
    
    if(n->left!=NULL)
    {
        l = inorder(n->left);
    	p2->next = n2;
    	n2->prev= p2;
	}
    
	else
	{
		l=(dll*)malloc(sizeof(dll));
		l->start=n2;
		n2->prev = NULL;
		n2->next=NULL;
		p1 = n2;
		p2 = n2;
	}
	
	temp = p1;	
	
    if(n->right!=NULL)
    {
	    l1 = inorder(n->left);
		n2->next=p1;
		p1->prev=n2;
	}
    
    p1 = temp;
    
    return l;
}

int main()
{
	tree* bin;
	bin = (tree*) malloc(sizeof(tree));
	 
	node2*n;
	n = (node2*) malloc(sizeof(node2));
	 
	n->value = 3;
	n->left =NULL;
	n->right = NULL;
	 
	bin->head = n;
	 
	node2*m;
	m = (node2*) malloc(sizeof(node2));
	
	m->value = 2;
	m->left =NULL;
	m->right = NULL;
	
	n->left = m;
	
	node2*b;
	b = (node2*) malloc(sizeof(node2));
	
	b->value = 4;
	b->left =NULL;
	b->right = NULL;
	
	n->right = b;
	
	node2*c;
	c = (node2*) malloc(sizeof(node2));
	
	c->value = 5;
	c->left =NULL;
	c->right = NULL;
	
	b->right = c;
	
    dll * l;
	l = inorder(bin->head);
	
	node1* st;
	st = l->start;
	
	while(st!=NULL)
	{
		cout<<st->value<<" ";
		st=st->next;
	}
	
	cout<<endl;
}
