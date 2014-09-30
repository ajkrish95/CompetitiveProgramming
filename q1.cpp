#include<stdio.h>
#include<algorithm>
#include<iostream>

using namespace std;

int main()
{
	int i,j,k,n,m;
	
	scanf("%d",&n);
	scanf("%d",&m);
	
	int a[n];
	
	a[1] = 1;
	a[0] = 1;
	
	for(i=2;i<=n;i++)
	{
		a[i]=0;
		for(j=1;j<=m;j++)
		{
			if(i-j >=0)
			{
				a[i] = a[i] + a[i-j];
			}
		}
	}
	
	printf("%d\n",a[n]);					
	return 0;
}
