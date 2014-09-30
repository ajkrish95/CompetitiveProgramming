#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int t,ans,min,i,n,count,sum,temp;
    char s1[1000],s2[1000],a[100],b[100];
	scanf("%d",&t);
    
    while(t--)
    {
    	count = 0;
    	scanf("%s",s1);
		scanf("%s",s2);
    	
    	for(i=0;i<100;i++)
    	{
    		a[i]=0;
    		b[i]=0;
    	}
    	for(i=0;s1[i]!='\0';i++)
    	{
    		temp = s1[i] - 'a';
    		a[temp] = 1;
    	}

    	for(i=0;s2[i]!='\0';i++)
    	{
    		temp = s2[i] - 'a';
    		b[temp] = 1;
    	}
    	
    	for(i=0;i<100;i++)
    	{
    		if(a[i]==1 && b[i]==1)
    		{
    			count++;
    		}
    	}
    	
    	printf("%d\n",count);
    	
	}

    return 0;
}

