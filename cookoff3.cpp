#include<stdio.h>
#include<string>
#include<iostream>
#include<string.h>

using namespace std;

int p[1001000],a[100100],c[1001000],t1[1001000];

int main()
{
	int i,j,count,k,n,ans,t,num,len,rem1,rem,beg;
	char ch;
	scanf("%d",&t);

	for(i=0;i<=1000000;i++)
	{
		p[i]=0;
		c[i]=-1;
		t1[i]=i;
	}	
	
	for(i=2;i<=1000;i++)
	{
		if(p[i]==0)
		{
			for(j=i;i*j<=1000000;j++)
			{
				p[i*j]=1;
				t1[i*j]=i;
			}
		}
	}
	
	while(t--)
	{
		scanf("%d",&n);
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		
		num = a[0];
		
		memset(c,-1,sizeof(c));
		
		while(num!=1)
		{
			c[t1[num]] = 0;
			num=num/t1[num];
		}
		
		len =1;
		rem =0;
		
		for(i=1;i<n;i++)
		{
			num=a[i];
			rem1=rem;
			
			while(num!=1)
			{
				if(c[t1[num]] !=-1&&c[t1[num]]!=i)
				{
					beg = c[t1[num]]+1;
					c[t1[num]]=i;	
					if(rem1<beg)
					{
						rem1 = beg;
					}
				}
				
				if(c[t1[num]]==-1)
				{
					c[t1[num]]=i;
				}
				
				num = num/t1[num];
			}
			
			for(j=rem;j<rem1;j++)
			{
				num=a[i];
				
				while(num!=1)
				{
					if(c[t1[num]] !=i)
					{
						c[t1[num]]=-1;
					}
					
					num = num/t1[num];
				}				
			}
			
			
			rem = rem1;
			
			if(len<(i-rem+1))
			{
				len=i-rem+1;
			}
		}
		
		if(len==1)
		{
			printf("-1\n");
		}
		else
		printf("%d \n",len);
	}
}
