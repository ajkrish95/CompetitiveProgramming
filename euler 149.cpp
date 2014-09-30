#include<iostream>
#include<math.h>
using namespace std;
long long int a[2001][2001],b[4000001];

long long int func(long long int n,long long int i)
{
	int j,er,sum=0,max=0;
	if(n==1)
	{
		for(j=1;j<2001;j++)
		{
			er=sum+a[i][j];
			
			if(er<=0)
			sum=0;
			
			else
			{
			sum=er;
			if(sum>max)
			max=sum;
			}
		}	
	}
	
	if(n==2)
	{
		for(j=1;j<2001;j++)
		{
			er=sum+a[j][i];
			
			if(er<=0)
			sum=0;
		
			else
			{
			sum=er;
			if(sum>max)
			max=sum;
			}
		}	
	}

	if(n==3)
	{
		if(i<=2000)
		{
		for(j=1;j<i;j++)
		{
			er=sum+a[j][j+2000-i];
			
			if(er<=0)
			sum=0;
		
			else
			{
			sum=er;
			if(sum>max)
			max=sum;
			}
		}	
	}
	if(i>2000)
		{
		for(j=2000;j>=i-1999;j--)
		{
			er=sum+a[j][j+n-i];
			
			if(er<=0)
			sum=0;
		
			else
			{
			sum=er;
			if(sum>max)
			max=sum;
			}
		}	
	}
}
	if(n==4)
	{
		if(i<=2000)
		{
		for(j=1;j<=i;j++)
		{
			er=sum+a[j][i-j+1];
			
			if(er<=0)
			sum=0;
		
			else
			{
			sum=er;
			if(sum>max)
			max=sum;
			}
		}	
	}
	if(i>2000)
	{
		for(j=2000;j>=i-1999;j--)
		{
			er=sum+a[j][i-j+1];
			
			if(er<=0)
			sum=0;
		
			else
			{
			sum=er;
			if(sum>max)
			max=sum;
			}
		}		
	}
}
return max;
}
int main()
{
long long int max,er,i,j,k,temp,tmp;	
	
for(k=1;k<56;k++)
{
temp=pow(k,3);
temp=300007*temp;
tmp=200003*k;
b[k]=100003-tmp+temp;
b[k]=b[k]% 1000000;
b[k]=b[k]-500000;
}

for(k=56;k<4000001;k++)
{
b[k]= b[k-24]+b[k-55]+1000000; 
b[k]=b[k]%1000000;
b[k]=b[k]-500000;
}
for(i=1;i<2001;i++)
for(j=1;j<2001;j++)
{
	a[i][j]=b[2000*(i-1)+j];
	
}
max=0;
for(i=1;i<2001;i++)
{
er=func(1,i);	
if(er>max)
max=er;
}
for(i=1;i<2001;i++)
{
er=func(2,i);	
if(er>max)
max=er;
}
for(i=1;i<4000;i++)
{
er=func(3,i);
if(er>max)
max=er;
}
for(i=1;i<4000;i++)
{
er=func(4,i);
if(er>max)
max=er;

}
cout<<max;
return 0;
}

