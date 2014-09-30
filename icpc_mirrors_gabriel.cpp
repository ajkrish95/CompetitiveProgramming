#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	char a[100];
	int er,len,t,i,temp;
	scanf("%d",&t);
	while(t>0)
	{
		--t;
		temp=0;
		scanf("%s",&a);
		len=strlen(a);
		er=len/2;
		er=len+1;
		for(i=0;i<len,i<er;i++)
		{
			if(a[i]!=a[len-i-1])
			{
				temp=1;
				break;
			}
		}
		if(temp==0)
		printf("YES\n");
		else
		printf("NO\n");
	}
return 0;
}
