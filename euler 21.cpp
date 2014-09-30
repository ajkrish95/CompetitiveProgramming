#include<iostream>
#include<math.h>
using namespace std;
long long int a[2000001],b[100000],c[2000000];
long long int func (long long int i,long long int q,long long int p)
{
	long long int y,w=0;
	while(q%p==0)
	{
	q=q/p;
	++w;
	}
	y=pow(p,w+1);
	y=y-1;
	y=y/(p-1);
	c[i]=c[i]*y;
	return q;
}
int main()
{
	long long int q,k=1,s=2,i,j,n;
	n=50000;
	for(i=0;i<200000;i++)
	c[i]=1;	
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
	b[k]=2*i +1 ;
	s+=b[k];
	++k;
	}
	cout<<k;
for(i=1;i<n;i++)
	{
	q=i;
	for(j=0;j<k;j++)
	{
	if(q==1)
	break;
	if(q%b[j]==0)
	q=func(i,q,b[j]);
}
}
s=0;
for(i=2;i<50000;i++)
{
j=c[i]-i;
if(c[j]-j==i&&i!=j)
{
cout<<i;
s=s+i;
cout<<endl;
}
}
cout<<s;
}

