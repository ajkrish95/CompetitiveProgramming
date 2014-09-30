#include<stdio.h>
#include<malloc.h>
#include<iostream>

using namespace std;


//typedef struct Node node;
struct node
{
	int value;
	node* next;
};

struct dllist
{
	node* head;
};



struct llist
{
	node* head;
};

struct stack
{
	node* head;
};

void print(llist* list)
{
	node* a = list->head;
	cout<<endl;
	while(a!=NULL)
	{
		cout<<a->value<<endl;
		a=a->next;		
	}
}


node* new_node(int value,node* next)
{
	node* a;
	a = (node*) malloc(sizeof(node));
	a->value = value;
	a->next = next;
	return a;
}

node* new_node(int value)
{
	return new_node(value, NULL);
}

llist* remove_duplicates(llist* list)
{
	node *tmp,*b ;

	if (list == NULL || list -> head == NULL)
	{
		return list;
	}
	node *a = list->head;
	int temp;

	while(a->next!=NULL)
	{
		temp = a->value;
		
		b = a->next;
		
		while(b!=NULL)
		{
			if(b->value == temp)
			{
				tmp = b->next;
				delete(b);
				b = tmp;
			}
			b=b->next;
		}	
		
		a=a->next;	
	}
	
	return list;
} 
 
stack* push(stack *a,int value)
{	
	if(a==NULL || a->head==NULL)
	{
		a->head = new_node(value,NULL);
	}	
	
	else
	{
		node *c;
		c = a->head; 
		node *b;
		b = new_node(value,a->head);
		a->head=b;
	}
}

llist* reverse(llist* list)
{
	if(list==NULL || list->head == NULL || list->head->next == NULL)
	{
		return list;
	}	
	
	else
	{
		node* last = list->head;
		list->head = list->head->next;
		list = reverse(list);
		node* a = list->head;
		last->next = NULL;
		
		while( a->next != NULL )
		{
			a=a->next;
		}
		
		a->next = last;
	}
	
	return list;
} 

llist* new_llist()
{
	llist *list = (llist*) malloc(sizeof(llist));
	list->head=NULL;
	return list;
}

llist* append( llist* lst, int data ){
	
	node *a,*b;
	b = new_node( data, NULL );
		
	a=lst->head;
	
	if( a == NULL )
	{
		lst->head = b;
	}
	
	else
	{	
		while(a->next!= NULL)
		{
			a=a->next;
		}
		
		a->	next=b;
	}
	
	return lst;
}

void remove_loop(llist* list)
{
	node *p1,*p2;
	p1=p2=list->head;
	
	do
	{
		p1=p1->next;
		p2=p2->next;
		p2=p2->next;
	}while(p1!=p2);
	
	p1=list->head;
	
	while(p1!=p2)
	{
		p1=p1->next;
		p2=p2->next;
	}
	
	cout<<p1->value<<endl;
}

int nth_from_end(llist* list,int n)
{
	node *p1,*p2;
	p2=list->head;
	p1=list->head;

	int count =1;
	
	while(p2->next!=NULL && count !=n)
	{
		count = count + 1;	
		p2=p2->next;
	}
	
	if(count<n)
	{
		printf("insufficient size of list");
	}
	
	else
	{
		while(p2->next!=NULL)
		{
			p1=p1->next;
			p2=p2->next;
		}
		
		cout<<p1->value<<endl;
	}
	return p1->value;
}

/*dllist* append(dllist* list,int value)
{
	if(list==NULL || list->head==NULL)
	{
		list->
	}	
}
*/
llist* delete_this_node(llist* list,node* p)
{
	if(list->head==p)
	{
		list->head=p->next;
		delete(p);
	}
	else
	{
		if(p->next==NULL)
		{
			cout<<"äbra\n";
			node* b=p;
			p=NULL;	
			
			cout<<b->value;
		}
		
		
		else
		{
			node* b=p->next;
			p->value = b->value;
			p->next=b->next;
			delete(b);
		}
	}
	return list;
}

int main()
{
	stack* stk = NULL;
//	stk = (stack*) malloc(sizeof(stk));
	
//	push(stk,40);
//	push(stk,90);
	
	llist *list;
	list = new_llist();
	
	append(list,6);
	append(list,5);
	append(list,4);
	append(list,3);
	append(list,2);
	append(list,1);
	
	//node*p1=list->head;
	//node*p2=list->head->next->next->next->next->next;
	//p2->next=p1;
	
	//remove_loop(list);	
	
	//cout<<nth_from_end(list,6);
	node* b;
	b= new_node(6,NULL);
	
	llist *ans;
	print(list);
	delete_this_node(list,list->head->next->next->next->next->next);
	print(list);
	
	ans = reverse(list);
	
	print(ans);

}
