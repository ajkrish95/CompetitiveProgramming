#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	unsigned long long int q[10],z[10],x[10],w[10],v[10],n[10],k[10],a,b,m=0,t=0,c,d,e,f,sum,num;
	for(a=0;a<10;a++)
	{
	q[a]=pow(a,5);
	z[a]=100000*a;	
	x[a]=10000*a;
	w[a]=1000*a;
	v[a]=100*a;
	n[a]=10*a;
	k[a]=a;
}
	for(a=0;a<3;a++)
	for(b=0;b<10;b++)
	for(c=0;c<10;c++)
	for(d=0;d<10;d++)
	for(f=0;f<10;f++)
	{
		if(((a+b+c+d)%10)!=0)
		e=10-((a+b+c+d)%10);	
		else
		e=0;
		num=z[a]+x[b]+w[c]+v[d]+n[e]+k[f];
		sum=q[a]+q[b]+q[c]+q[d]+q[e]+q[f];
		if(num==sum&&num>1)
		{
		++t;
		cout<<sum;
		m=m+num;
		cout<<endl;
	}
	}

cout<<t;
cout<<endl;
cout<<m;

return 0;
}
