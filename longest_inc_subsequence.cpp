#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int end,i,n,j,a[100],b[3][3],c[100];
	
	cin>>n;
	
	
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}	

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			b[i][j] = i;
			cout<<&b[i][j]<<endl;
		}
	}	
	
	cout<<endl;
	vector<int> v;
	
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	cout<<&v[0]<<endl;
	cout<<&v[1]<<endl;
	cout<<&v[2]<<endl;
	cout<<&v[3]<<endl;
	
	end =0;
	c[0] = a[0];
	for(i=1;i<n;i++)
	{
		if(lower_bound(c,c+end+1,a[i])==c+end+1)
		{
			cout<<c[end]<<" "<<a[i]<<endl;
			end++;
			c[end]=a[i];
		}
		
		else
		{
			c[lower_bound(c,c+end+1,a[i])-c] = a[i];
		}
	}
	
	cout<<end+1<<" jkjk"<<endl;
}
