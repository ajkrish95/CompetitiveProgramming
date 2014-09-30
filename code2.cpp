#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

long long int a[310005],b[310005];
int n,m;
long long int temp,ans;
int check(long long int u);
int binary(int len)
{
	int lo = 0,hi = len,mid,flag;
	while(lo<=hi)
	{
		mid = hi+lo>>1;
		(flag = check(mid))?lo = mid+1:hi = mid-1;
	}
	int temp = mid-1+flag; 
	return temp;
}

int check(long long int u)
{
	int i=0;
	int j=0;
	
	while((i<n)&&(j<m))
	{
		if(((a[i]-b[j])<=u)&&((b[j]-a[i])<=u))
			i++;
		j++;
	}
	
	if(i==n)
		return 0;
	
	else
		return 1;
}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	
	while(t--)
	{	
		scanf("%d",&n);
		scanf("%d",&m);
		
		ans =0 ;
		
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		
		for(i=0;i<m;i++)
		{
			scanf("%lld",&b[i]);
		}	
		
		sort(a,a+n);
		sort(b,b+m);
		printf("%lld\n",binary(2*100000002)+1);
	}
}
