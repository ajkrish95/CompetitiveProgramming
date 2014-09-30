#include<stdio.h>
#include<algorithm>

using namespace std;
long long  MOD = int(1e9) + 7;

int a[25][25];
int dp[1025][25];int n,k;
int s[25][25];

int solve(int bm,int over)
{
	if(over == n)
	{
		return 0;
	}
	
	if(bm == ((1<<k) -1) )
	{
		return MOD;
	}
	
	if(dp[bm][over] != -1)
	{
		return dp[bm][over];
	}
	
	int ret = -1;
	int can = 100000000;
	int i,j;
	for(i=0;i<k;i++)
	{
		if(!( bm & ( 1<<i ) ))
		{	
			for(j= over + 1;j <= n;j++)
			{
				int l;
				can = min( can, s[i][j] - s[i][over] + solve(bm + (1<<i) , j) );
	
			}
			ret = can;
		}
	}

	dp[bm][over] = ret;
	return ret;
}
int main()
{
      int i,j,t;
      scanf("%d%d",&n,&k);
      
      for(i=0;i<k;i++)
      {
      	for(j=0;j<n;j++)
      	{
      		scanf("%d",&a[i][j]);
      	}
      }
      
      for(i=0;i<1025;i++)
      {
      	for(j=0;j<25;j++)
      	{
      		dp[i][j] = -1;
      	}
      }
   
      for(i=0;i<k;i++)
      {
      	for(j=0;j<n;j++)
      	{
      		s[i][j+1] = s[i][j] + a[i][j];
      	}
      }
    
      printf("%d\n",solve(0,0));

}
