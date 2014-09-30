#include<stdio.h>

int main()
{
	int i,ans,a[100],n,beg,mid,end;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	beg = 0;
	end = n-1;
	
	ans= -1;
	while(end!=beg+1)
	{
		if(a[beg]<a[beg+1]){
			ans = a[beg];
			break;
		}
		
		if(a[end]<a[end-1])
		{
			ans = a[end];
			break;
		}
		
		mid  = (beg+end)/2;
		
		if(a[mid]<a[mid-1]&&a[mid]<a[mid+1])
		{
			ans = a[mid];
			break;
		}
		
		if(a[mid]>a[mid-1])
		{
			end =mid-1;
			continue;
		}
		
		else
		{
			beg = mid+1;
		}
	}
	
	if(ans==-1)
	{
		if(a[beg]<a[end])
		ans = a[beg];
		
		else
		ans = a[end];
	}
	
	printf("%d\n",ans);
	return 0;
}
