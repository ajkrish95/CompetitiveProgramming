#include<iostream>
#include<math.h>
using namespace std;
unsigned long long int b[10000000],a[100000001];
int main()
{
	unsigned long long int temp,tmp,er,k=1,s=2,i,j,n;
	n=100000000;
	for(i=0;i<n/2;i++)
	a[i]=1;
	for(i=3;i<=sqrt(n);i+=2)
	{
	if(a[(i-1)/2]==1)
	{
	for(j=i;(i*j)<=n;j+=2)
	a[((i*j)-1)/2]=0;
}
}
	b[0]=2;
	for(i=1;i<n;i++)
	if(a[i]==1)
	{
	b[k]=2*i+1;
	++k;
	s+=(2*i+1);
	}
	cout<<s;
	cout<<endl;
	cout<<k;
	cout<<endl;
	
	
