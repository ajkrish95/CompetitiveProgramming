#include<iostream>
#include<math.h>
using namespace std;
int main()
{
float g=2.0,a,b,c;
int n,sum=9,i,j,num;
for(i=2;i<23;i++)
{
	g=2.0;
	for(j=1;j<20;j++)
	{
		a=(i-1)*g;
		b=pow(g,i-1);
		b=1/b;
		b=b*10;
		g=a+b;
		g=g/i;
	}
cout<<g;
cout<<endl;
g=10/g;
n=g;
num=9-n;
cout<<num;
cout<<endl;
sum=sum+num;
}
cout<<sum;
}
