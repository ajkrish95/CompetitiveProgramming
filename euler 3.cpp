#include<iostream>
#include<math.h>
using namespace std;
long long int b[1000000],a[7000001];
int main()
{
	long long int max,er=600851475143,k=1,s=2,i,j,n;
	n=1000000;
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
	}
for(i=0;i<(k-1);i++)
if(er%b[i]==0)
max=b[i];
cout<<max;
}
