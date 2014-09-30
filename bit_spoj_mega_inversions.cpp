#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<string.h>

using namespace std;

// BIT can only be used for inverse operations like +, XOR and *

long long int a[100010],bit[100010],b[100010],n,ans[100010],ans1[100010];

void update(long long int pos,long long int val)
{
	if(pos>n)
	{
		return;
	}
	
	bit[pos]+=val;
	pos=pos+(pos&(-pos));
	update(pos,val);
}

long long int query(long long int pos)
{	
	if(pos==0)
	{
		return 0;
	}
	
	return bit[pos] + query(pos-(pos&(-pos)));
}

int main()
{
	long long int i,j;
	const long long int k = 1; // k cant be modified

	cin>>n;
	
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i] = a[i];
	}
	
	sort(b+1,b+n+1);
	
	map<long long int,long long int> mp;
	
	for(i=1;i<=n;i++)
	{
		mp[b[i]]=i;
	}
	
	for(i=1;i<=n;i++)
	{
		a[i] = mp[a[i]];
	}
	
	for(i=1;i<=n;i++)
	{
		ans[i]=query(n)-query(a[i]);
		update(a[i],1);
	}

	memset(bit,0,sizeof(bit));
	
	long long int y =0 ;
	for(i=1;i<=n;i++)
	{
		ans1[i]=query(n)-query(a[i]);
		update(a[i],ans[i]);
		y= y +ans1[i];
	}
	
	cout<<y<<endl;
}
