#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int b[1002][1002],a[1002][1002],c[1002][1002];


int main()
{
	int i,j,count,k,t,n,ans;
	char ch;
	string e;
	scanf("%d",&t);
	
	while(t--)
	{
		count = 0;
		scanf("%d",&n);
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j]=b[i][j]=c[i][j]=0;
			}
		}		
		for(i=0;i<n;i++)
		{
			cin>>e;
			for(j=0;j<n;j++)
			{
				ch = e[j];
				
				if(ch=='.')
				{
					a[i][j] = 1;
				}
				
				else
				{
					a[i][j] = 0;
				}
			}
			
			scanf("%c",&ch);
		}
		
		for(i=n-1;i>=0;i--)
		{
			ans = 1;
			
			for(j=n-1;j>=0;j--)
			{
				if(ans == 0)
				{
					b[i][j] =0;
				}
				
				if(a[i][j]==0&&ans==1)
				{
					ans=0;
					b[i][j]=0;
				}
				
				if(ans==1&&a[i][j]==1)
				{
					b[i][j]=1;
				}
			}
		}
		
		for(j=0;j<n;j++)
		{
			ans = 1;
			
			for(i=n-1;i>=0;i--)
			{
				if(ans == 0)
				{
					c[i][j] =0;
				}
				
				if(a[i][j]==0&&ans==1)
				{
					ans=0;
					c[i][j]=0;
				}
				
				if(ans==1&&a[i][j]==1)
				{
					c[i][j]=1;
				}
			}
		}
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				
				if(b[i][j]*c[i][j]==1)
				{
					count++;
				}
			}
		}
		
		printf("%d\n",count);
	}	
}
