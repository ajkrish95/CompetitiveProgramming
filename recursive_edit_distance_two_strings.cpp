#include<stdio.h>
#include<string.h>

int c[2100][2100];
char a[2100],b[2100];

int func(int beg1,int beg2,char a[2100],char b[2100])
{
	int temp1,temp2,temp3,mini;
	
	if(beg1==strlen(a) && beg2 == strlen(b))
	{
		return 0;
	}
	
	if(beg1==strlen(a))
	{
		return strlen(b) - beg2;
	}
	
	if(beg2==strlen(b))
	{
		return strlen(a) - beg1;
	}
	
	if(c[beg1][beg2]!=-1)
	{
		return c[beg1][beg2];
	}
	
	if(a[beg1]==b[beg2])
	{
		temp1 = func(beg1+1,beg2+1,a,b);
		c[beg1][beg2] = temp1;
		return temp1;
	}
		
	temp1 = func(beg1+1,beg2+1,a,b) + 1;		
	temp2 = func(beg1+1,beg2,a,b) + 1;
	temp3 = func(beg1,beg2+1,a,b) + 1;
	
	mini = temp1;
	if(temp2<mini)
	mini=temp2;
	if(temp3<mini)
	mini=temp3;

	c[beg1][beg2] = mini;
	
	return c[beg1][beg2];
}

int main()
{
	int i,t,j,ans;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%s",a);
		scanf("%s",b);
		
		memset(c,-1,sizeof(c));	
		
		ans = func(0,0,a,b);
	
		printf("%d\n",ans);
		
	}
	return 0;
}
