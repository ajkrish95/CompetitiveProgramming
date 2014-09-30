#include<iostream>
#include<math.h>
using namespace std;
	
int main()
{
	int a[10],i,n,er,max=-1000,sum=0;
	for(i=0;i<10;i++)
	{
	cin>>a[i];
	}
	for(i=0;i<10;i++)
	{
		er=sum+a[i];
		
		if(er<=0)
		sum=0;
		
		else
		{
			sum=er;
			if(sum>max)
			max=sum;
		}
	}	
cout<<max;
return 0;	
}

