#include<stdio.h>


int main()
{
	int a[100][100],b[100];
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	
	for(i=0;i<n;i++)
	{
		a[0][i] = b[i];
	}	
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j+1)
			{
				a[i][i-1] = 1;
			}
			
			else
			{
				a[i][j] = 0;
			}
		}
	}
	
	int answer = func(a,k)
}
