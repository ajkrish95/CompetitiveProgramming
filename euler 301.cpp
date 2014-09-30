#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long int a,b,c,i,sum=0,max;
	max=pow(2,30);
	cout<<max;
	cout<<endl;
	for(i=1;i<=max;i++)
	{
	b=2*i;
	c=3*i;
	a=i^b;
	a=a^c;	
	if(a==0)
	++sum;
	}
cout<<sum;
}
