#include<stdio.h>
#include<algorithm>

using namespace std;

int main()
{
	int n,t,a[100010],i,k,ans;
	
	scanf("%d",&t);
	
	while(t--)
	{
		ans=0;
		
		scanf("%d %d",&n,&k);
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		
		sort(a,a+n);
		
		if(k<=n/2)
		{
			for(i=0;i<k;i++)
			{
				ans=ans+a[i];
			}
			
			for(i=k;i<n;i++)
			{
				ans=ans-a[i];
			}
			
			ans=-ans;
		}
		else
		{
			for(i=0;i<n-k;i++)
			{
				ans=ans+a[i];
			}
			
			for(i=n-k;i<n;i++)
			{
				ans=ans-a[i];
			}
			
			ans=-ans;
		}
		printf("%d\n",ans);
	}
}
