#include<stdio.h>

int gcd(int a,int b)
{
	if(b<a)
	{
		return gcd(b,a);
	}
	
	if(a==0)
	{
		return b;
	}
	
	return gcd(b%a,a);
}

int main()
{
	int i,j,t,gd,lmax,n,len,a[120000];
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		
		lmax = 1;
		len =1 ;
		gd = a[0];
		
		for(i=1;i<n;i++)
		{
			gd = gcd(gd,a[i]);
		}
		
		if(gd==1)
		{
			printf("%d\n",n);
		}
		
		else
		{
			printf("-1\n");
		}
	}
}
