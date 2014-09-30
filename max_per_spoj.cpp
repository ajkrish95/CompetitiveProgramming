#include<stdio.h>
#include<iostream>

using namespace std;

int abst(int a)
{
	if(a<0)
	a=-a;
	
	return a;
}

int main()
{
	int i,n,a[1010][2],ans[1010][2];	
	
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	
	ans[0][0] = a[0][0];
	ans[0][1] = a[0][1];
	for(i=1;i<n;i++)
	{
		ans[i][0] = max((abst(a[i][1] - a[i-1][1]) + a[i][0] + ans[i-1][0]),(abst(a[i][1] - a[i-1][0]) + a[i][0] + ans[i-1][1]));
		ans[i][1] = max((abst(a[i][0] - a[i-1][1]) + a[i][1] + ans[i-1][0]) ,(abst(a[i][0] - a[i-1][0]) + a[i][1] + ans[i-1][1]));	
		
	}
	
	
	cout<<max((ans[n-1][0]),(ans[n-1][1]))<<endl;
	
	return 0;
}
