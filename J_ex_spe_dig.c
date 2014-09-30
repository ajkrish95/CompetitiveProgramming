#include<stdio.h>
#include<math.h>
long int func(long int n)
{
	long int temp;
	while(n>0)
	{
	temp=n%10;
	if((temp==3)||(temp==5)||(temp==6))
	{
		return 1;
	}
	n=n/10;
}
return 0;
}
int main()
{
	long int er,i,t,n,temp,count;
	scanf("%ld",&t);
	while(t>0)
	{
		--t;
	count =0;
	scanf("%ld",&n);
	if(func(n)==1)
	++count;
	for(i=2;i<=sqrt(n);i++)
	{
		if((n%i)==0)
		{
		er=n/i;
		{
			if(func(i)==1)
			++count;
		}
		if(er!=i)
		{
			if(func(er)==1)
			++count;
		}
	
	}
	}printf("%ld\n",count);
	}
return 0;
}
