#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long int sum=0,tmp,n,i;
	for(i=3;i<1001;i++)
	{
		tmp=i*i;
		if(i%4==0)
		sum=sum+tmp-2*i;
		if(i%4==1)
		sum=sum+tmp-i;
		if(i%4==2)
		sum=sum+tmp-2*i;
		if(i%4==3)
		sum=sum+tmp-i;
		}
	cout<<sum;
	return 0;
}
