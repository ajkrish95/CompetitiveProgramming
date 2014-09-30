#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<algorithm>

int a[200000],b[200000],c[200000];
using namespace std;

int main() {
    
    int ans=0,max,i,n,t,ct,temp;
	scanf("%d",&t);
	
    
    while(t--)
    {
		scanf("%d",&n);
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
		
		sort(a,a+n);
		sort(b,b+n);
		for(i=0;i<n;i++)
		{
			temp = a[i] - b[i];
			
			if(temp<0)
			{
				c[i] = -temp;
			}
			
			else
			{
				c[i] = temp;
			}
		}	
		
		max = c[0];
		for(i=0;i<n;i++)
		{
			if(c[i]>max)
			{
				max= c[i];
			}
			
			
		}
		
		printf("%d\n",max);
	}

    return 0;
}

