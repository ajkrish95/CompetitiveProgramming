#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>

using namespace std;
struct node
{
	int a,b,weight;
}arr[100010];

bool compare(node x,node y)
{
	return x.weight < y.weight;
}

bool operator < (node x,node y)
{
	return x.weight < y.weight;
}

int comp[100010];
int m,n;

int findcomp(int x)
{
	if(comp[x] == x)
	{
		return x;
	}
	return comp[x] = findcomp(comp[x]);
}

void merge(int x,int y)
{
	comp[findcomp(x)] = findcomp(y);
}

int kruskal()
{
	int i;
	for(i=0;i<100010;i++)
	{
		comp[i] = i;
	}
	
	sort(arr,arr+m);
	
	int no = 0; // number of edges added till now
	int ret = 0; // cost of the minimum spanning tree
	
	i=0;

	while(no < n-1)
	{
		int x1 = arr[i].a,y1 = arr[i].b;
		if(findcomp(x1)!=findcomp(y1))
		{
			merge(x1,y1);
			ret += arr[i].weight;
			no++;
		}
		i++;
	}
	
	return ret;
	
}

int main()
{
	long long int a=1;
	int c,x,y,ans;
	int i=0,t;
	map<long long int,int> mp;
	
	while(i<=64)
	{
		mp[a]=i;
		i++;
		a*=2;
	}	
	
	cin>>t;
	
	while(t--)
	{
		cin>>n>>m;
		
		for(i=0;i<m;i++)
		{
			cin>>arr[i].a>>arr[i].b;
			cin>>a;
			a=mp[a];
			
			arr[i].weight = a;
		}
		
		ans = kruskal();
		
		cout<<ans+1<<endl;
	}
}
