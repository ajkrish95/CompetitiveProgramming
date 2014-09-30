#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int n,q,temp,j,i,ans[1000];
	
	ans[0]=0;
	ans[1]=1;
	
	for(i=2;i<1000;i++)
	{
		ans[i]=i;
		for(j=1;j*j<=i;j++)
		{
			temp = ans[i-j*j] + 1;
			if(temp<ans[i])
			ans[i]=temp;
		}
	}
	
	cin>>q;
	
	for(i=0;i<q;i++)
	{
		cin>>n;
		cout<<ans[n]<<endl;
	}
}
