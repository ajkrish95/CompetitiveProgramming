#include<stdio.h>
#include<queue>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main()
{
	int i,n,**a,**vis,m,x,j;
	int y;
	vector<int> v[100];
	scanf("%d",&n);
	
	a=(int**)malloc(sizeof(int*)*n);
	
	for(i=0;i<n;i++)
	{
		a[i] = (int*)malloc(sizeof(int)*n);
	}
	
	vis = new int*[n];
	
	for(i=0;i<n;i++)
	{
		vis[i] = new int[n];
	}
	
	scanf("%d",&m);
	
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		
		if(find(v[x].begin(),v[x].end(),y)==v[i].end()){
		v[x].push_back(y);
		cout<<"nice "<<x<<" "<<y<<endl;
		}
	}
	
	vector<int> :: iterator it;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		
			vis[i][j]=0;
		}
	}
	
	int ans=0,count;
	queue< pair<int,int> > q;
	pair<int,int> foo;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(vis[i][j]==0)
			{
				foo = make_pair(i,j);
				q.push(foo);
				
				count=0;
				while(!q.empty())
				{
					foo=q.front();
					vis[foo.first][foo.second]=1;
					x=foo.first;
					y=foo.second;
					if(x-1>=0&&vis[x-1][y]==0&&(a[x-1][y]==a[x][y]+1||a[x-1][y]==a[x][y]-1))
					{
						q.push(make_pair(x-1,y));
					}
					if(x+1<n&&vis[x+1][y]==0&&(a[x+1][y]==a[x][y]+1||a[x+1][y]==a[x][y]-1))
					{
						q.push(make_pair(x+1,y));
					}
					if(y-1>=0&&vis[x][y-1]==0&&(a[x][y-1]==a[x][y]+1||a[x][y-1]==a[x][y]-1))
					{
						q.push(make_pair(x,y-1));
					}
					if(y+1<n&&vis[x][y+1]==0&&(a[x][y+1]==a[x][y]+1||a[x][y+1]==a[x][y]-1))
					{
						q.push(make_pair(x,y+1));
					}
					q.pop();
					count++;
				}
				
				if(count>ans)
				{
					ans= count;
				}
			}
		}
	}
	
	cout<<ans<<endl;
	
}
