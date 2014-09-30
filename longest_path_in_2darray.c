#include<stdio.h>

int n,a[20][20],vis[20][20],count;

void dfs(int x,int y)
{
	count++;
	//printf("%d %d \n",count,a[x][y]);
	vis[x][y]=1;
	
	if(x-1>=0&&vis[x-1][y]==0&&(a[x-1][y]==a[x][y]+1||a[x-1][y]==a[x][y]-1))
	{
		dfs(x-1,y);
	}

	if(y-1>=0&&vis[x][y-1]==0&&(a[x][y-1]==a[x][y]+1||a[x][y-1]==a[x][y]-1))
	{
		dfs(x,y-1);
	}

	if(x+1<n&&vis[x+1][y]==0&&(a[x+1][y]==a[x][y]+1||a[x+1][y]==a[x][y]-1))
	{
		dfs(x+1,y);
	}
	
	if(y+1<n&&vis[x][y+1]==0&&((a[x][y+1]==a[x][y]+1)||(a[x][y+1]==a[x][y]-1)))
	{
		dfs(x,y+1);
	}
	
	
}

int main()
{
	int ans,i,j,k;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	ans =0;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			count = 0;
			if(vis[i][j]==0)
			{
				dfs(i,j);
			}
			
			if(count>ans)
			{
				ans = count;
			}
		}
	}
	
	printf("%d\n",ans);
	
}
