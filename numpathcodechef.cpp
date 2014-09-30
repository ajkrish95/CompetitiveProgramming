#include<stdio.h>
#include<iostream>

using namespace std;

long long int ans[300000],s[300000],a[300000],p = 1000000007 ;

int main()
{
	int n,k,b,i,j,q;
	
	cin>>n>>b;
	
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	s[b]=1;
	ans[b]=1;
	ans[b+1]=0;
	
	for(i=b-1;i>=1;i--)
	{
		ans[i] = s[i+1] - s[i+a[i]+1];
		ans[i]=ans[i]%p;
		if(ans[i]<0)
		ans[i]=ans[i]+p;
		s[i] = s[i+1] + ans[i];
		s[i]=s[i]%p;
	}
	
	cin>>q;
	
	for(i=0;i<q;i++)
	{
		cin>>k;
		cout<<ans[k]%p<<endl;
	}
	
}
