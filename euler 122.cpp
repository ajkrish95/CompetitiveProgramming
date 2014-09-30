#include<iostream>
#include<math.h>
using namespace std;

int func(int i)
{
	int j=-1,sum=-1;;
	while(i!=0)
	{
	j=j+i%2;
	i=i/2;
	sum++;
	}
return (j+sum);
}


int main()
{
	int e=0,a[200],i,j,k;
	a[0]=0;
	a[1]=0;
	a[2]=1;
	for(i=3;i<201;i++)
	{
	k=0;
	for(j=2;j<i;j++)
	if(j%i==0)
	k=1;
	if(k==0)
	{
	a[i]=func(i);	
	}
	}
	for(i=4;i<201;i++)
	{
		for(j=2;j<i;j++)
		if(i%j==0)
		{
		a[i]=a[i/j]+a[j];
		break;
	}
	}
for(i=1;i<201;i++)
{
	cout<<i<<" "<<a[i];
	cout<<endl;
}
for(i=1;i<201;i++)
e=e+a[i];
cout<<e;
}
