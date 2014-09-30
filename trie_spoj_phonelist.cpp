#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct node
{
	int end;
	node*children[10];	
};


int main()
{
	int et,i,j,n,k,t;

	cin>>t;
	
	while(t--)
	{
		node* root = new node;
		string a;

		for(i=0;i<10;i++)
		{
			root->children[i] = NULL;
		}
		
		cin>>n;
		
		et=1;
		for(i=0;i<n;i++)
		{
			cin>>a;
		
			node* now =  root;
			
			for(j=0;j<a.size();j++)
			{
				if(now->children[a[j]-'0']==NULL)
				{
					node *n =new node;
					now->children[a[j]-'0'] = n;
					now->end=0;
					for(k=0;k<10;k++)
					{
						n->children[k] = NULL;
					}
				}
				
				now = now->children[a[j]-'0'];					 
				
				if(now->end==1)
				{
					et=0;
				}
			}
			
			now->end=1;
			for(j=0;j<10;j++)
			{
				if(now->children[j]!=NULL)
				{
					et = 0;
					break;
				}
			}
		}
	
		if(et==0)
		{
			printf("NO\n");
		}
		
		else
		{
			printf("YES\n");
		}		
	}		
}
