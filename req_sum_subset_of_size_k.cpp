#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int a[100],n,b[100][100][100];

int checksum(int start,int sum,int k)
{
	int ans = 0,i;
	
	if(k==1)
	{
		for(i=start;i<n;i++)
		{
			if(a[i]==sum)
			{
				ans++;
			}
		}
		b[start][sum][k]=ans;

		return ans;
	}
	
	for(i=start;i<n-k+1;i++)
	{
		if(b[i+1][sum-a[i]][k-1]==-1)
			ans = ans + checksum(i+1,sum-a[i],k-1);
		else
			ans = ans + b[i+1][sum-a[i]][k-1];
	}

	b[start][sum][k]=ans;

	return ans;
}

int main()
{
	int i,sum,k,ans=0;
	cin>>k>>sum>>n;
	
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	sort(a,a+n);
	
	for(i=0;i<n-k+1;i++)
	{
		ans = ans + checksum(i+1,sum-a[i],k-1);
	}
	
	cout<<ans<<endl;
}


