#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a[10000],diff,sum1,b[10000],i,j,k,sum,t=1;
	b[0]=1;
	a[0]=1;
	sum1=0;
	for(i=1;i<500;i++)
	{
		sum=0;
		for(j=1;j<i+1;j++)
		{
			a[j]=(b[j-1]+b[j])%7;
		}
	for(j=1;j<i+1;j++)
		{
			b[j]=a[j];
		}
	for(j=0;j<i+1;j++)
		{
			if(a[j]==0)
			++sum,++t;
		}
	cout<<i<<" "<<sum;
	cout<<endl;
	sum1=sum;
	}
cout<<" "<<t;
}

