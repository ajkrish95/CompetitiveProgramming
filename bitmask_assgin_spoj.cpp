#include<stdio.h>
#include<string.h>

int a[30][30],n;

long long int mem[21][1100000];


long long int func(int start,int bitmask)
{
	int i;
	
	if(mem[start][bitmask]!=-1)
	{
		return mem[start][bitmask];
	}
	
	long long int count = 0;
	
	if(start==n)
	{
		return 1;	
	}
	
	for(i=0;i<n;i++)
	{
		if(((bitmask & (1<<i))==0)&&(a[start][i]==1))
		{
			count  = count + func(start+1,bitmask|(1<<i)); 
		}	
	}
	
	mem[start][bitmask] = count;

	return count;
}

int main()
{
	int c,i,j,start,bitmask;
	long long int ans;
	
	scanf("%d",&c);
	
	while(c--)
	{
		scanf("%d",&n);
		
		memset(mem,-1,sizeof(mem));
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		
		start = 0;
		bitmask = 0;
		
		ans = func(start,bitmask);
		
		printf("%lld\n",ans);
	}
}
