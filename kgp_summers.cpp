#include<stdio.h>
#include<algorithm>
long int d[3000][3000];
using namespace std;
int main()
{
	long int i,j,t,n,min,a[3000][2],c[3000],b[3000],temp,tmp,er;
	scanf("%ld",&t);
	while(t>0)
	{
		--t;
		scanf("%ld",&n);
		for(i=1;i<n+2;i++)
		for(j=0;j<2;j++)
		scanf("%ld",&a[i][j]);
		scanf("%ld",&a[0][0]);
		scanf("%ld",&a[0][1]);
		c[0]=0;
		for(i=1;i<n+2;i++)
		{
			b[i]=((a[i][0]-a[0][0])*(a[i][0]-a[0][0])) + ((a[i][1]-a[0][1])*(a[i][1]-a[0][1]));
			c[i]=i;
		}
		for(i=0;i<n+2;i++)
		for(j=0;j<n+2;j++)
		{
			d[i][j]=((a[i][0]-a[j][0])*(a[i][0]-a[j][0])) + ((a[i][1]-a[j][1])*(a[i][1]-a[j][1]));
		}
		for(i=1;i<n+2;i++)
		{
			for(j=i+1;j<n+2;j++)
			{
				if(b[i]>b[j])
				{
					temp=b[i];
					b[i]=b[j];
					b[j]=temp;
					tmp=c[i];
					c[i]=c[j];
					c[j]=tmp;
										
				}
			}
		}
		for(i=0;i<n+2;i++)
		for(j=0;j<n+2;j++)
		{
		printf("%ld\n\n\n",d[i][j]);
		}
		for(i=1;i<n+2;i++)
		{
		printf("%ld\n\n",c[i]);
		}
		c[0]=0;
		b[0]=0;
		for(i=2;i<n+2;i++)
		{
			er=c[i];
			min=d[er][0];
			for(j=i-1;j>0;j--)
			{
			tmp=c[j];
			temp=b[j]+d[er][tmp];
			if(temp<min)
			min=temp;
			}
		b[i]=min;
		if(c[i]==(n+1))
	
		break;}
		
		printf("%ld\n",b[i]);
	}
}
