#include<stdio.h>
#include<string.h>
#include<malloc.h>

int main()
{
	int i,j,*a,n,temp,*sum,ans;
	
	scanf("%d",&n);
	
	a = (int*)malloc(sizeof(int)*n);
	sum = (int*)malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
		
	for(i=0;i<n;i++)
	{
		sum[i] = a[i];
	}
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[i]>a[j])
			{
				temp = sum[j] + a[i];
				
				if(sum[i] < temp)
				{
					sum[i] = temp;
				} 
			}	
		}
	}
	
	ans = sum[0];
	
	for(i = 0;i<n;i++)
	{
		if(ans<sum[i])
		{
			ans = sum[i];
		}
	}
	
	printf("%d\n",ans);
}
