#include<stdio.h>
#include<algorithm>
using namespace std;
long long int c[120000];
long long int a[120000];
int main()
{
		long long int min,temp,e=0;
		int  n,i,k;
		scanf("%d",&n);
		scanf("%d",&k);
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);	
		c[0]=0;
		sort(a,a+n);
		for(i=0;i<k-1;i++)
		c[0]=c[0]+a[i];
		for(i=1;i<(n-k+2);i++)
		{
		c[i]=c[i-1]-a[i-1]+a[i+k-2]	;
		}
		temp=k-1;
		for(i=k-1;i>=0;i--)
		{
		e=e+(temp*a[i]);
		temp=temp-2;
		}
		min=e;
		for(i=1;i<n-k+1;i++)
		{
			e=e+((k-1)*(a[i+k-1]+a[i-1]))-2*c[i];
			if(e<min)
			min=e;
		}
printf("%lld\n",min);
return 0;
}




