void bfs (node *n)
{
	queue <node*> queue;
	queue..push(n);
	node* temp;
	
	while(!queue.empty())
	{
		temp = queue.front();
			
		if(temp->left!=NULL)
		{
			queue.push(temp->left);
		}

		if(temp->right!=NULL)
		{
			queue.push(temp->right);
		}
		
		queue.pop();
	}
	
	return;
}

void bfs(int a[100][100])
{
	queue <int> queue;
	vis[100];
	
	memset(vis,0,sizeof(vis));
	
	queue.push(0);
	
	while(!queue.empty())
	{
		temp = queue.front();
		
		for(i=0;i<100;i++)
		{
			if(a[temp][j]==1&&vis[j]==0)
			{
				vis[j]=1;
				queue.push(j);
			}
		}
		
		queue.pop();
	}
	
	return;
} 

void dfs(node* n)
{
	stack<node*> stack;
	set <node*> set;
	node *temp;
	int ct;
	
	
	stack.push(n);
	
	while(!stack.empty())
	{
		ct=0;
		temp = stack.top();
		if(set.find(temp)!=set.end())
		{
			stack.pop();
		}
		
		else
		{
			set.insert(temp);
			
			if(temp->left!=NULL && set.find(temp->left)==set.end())
			{
				stack.push(temp->left);
				ct = 1;
			}
	
			if(temp->right!=NULL && set.find(temp->right)==set.end())
			{
				stack.push(temp->right);
				ct=1;
			}
		}
	}
}

int vis[i];

void dfs(int a[10][10],int node)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		if(a[node][i]==1&&vis[i]==0)
		{
			vis[i]==1;
			dfs(a,i);
		}
	}
}

void dijkstras(int a[10][10],int node1,int node2)
{
	int b[] = {};
	
}
