#include<stdio.h>
#include<algorithm>
using namespace std;
long long int a[120000];
int main()
{
		long long int min,temp;
		int  n,i,k;
		scanf("%d",&n);
		scanf("%d",&k);
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);	
		sort(a,a+n);
		min=a[k-1]-a[0];
		for(i=0;i<n-k+1;i++)
		{
		temp=a[i+k-1]-a[i];
		if(temp<min)
		min=temp;
		}
printf("%lld\n",min);
return 0;
}




