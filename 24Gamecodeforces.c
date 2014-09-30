#include<stdio.h>

void func(int n)
{
	if(n==4)
	{
		printf("4 * 3 = 12 \n1 * 2 = 2\n12 * 2 = 24\n");
		return;
	}		
	
	if(n==5)
	{
		printf("4 * 5 = 20 \n3 + 20 = 23\n2 +  23 = 25\n25 - 1 = 24\n");
		return;
	}	
	
	printf("%d - %d = 1\n1 * 1 = 1\n",n,n-1);
	func(n-2);	
	
}


int main()
{
	int n;
	scanf("%d",&n);
	
	int i;
	
	if(n<4)
	{
		printf("NO\n");
		return 0;
	}
	
	if(n%2==0)
	{
		printf("YES\n");
		
		func(n);	
	}
	
	else
	{
		printf("YES\n");
		
		func(n);		
	}
	
}
