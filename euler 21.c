#include<iostream>
#include<math.h>
using namespace std;
int a[2000001];
int main()
{
	long long int s=2,i,j,n;
	n=2000000;
	for(i=0;i<n/2;i++)
	a[i]=1;
	for(i=3;i<=sqrt(n);i+=2)
	{
	if(a[(i-1)/2]==1)
	{
	for(j=i;(i*j)<=2000000;j+=2)
	a[((i*j)-1)/2]=0;
}
}
	for(i=1;i<n;i++)
	if(a[i]==1)
	{
	s+=(2*i+1);
	}cout<<s;
}

