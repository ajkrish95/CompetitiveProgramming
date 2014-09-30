#include<stdio.h>
long long int a[100000];
long long int gcd(long long int b,long long c)
{
	long long int tmp;
	if((c%b)==0)
	return b;
	else
	{
		tmp=c;
		c=c%b;
		b=tmp;
	}
}

int main()
{
long long int temp,i,b,c,k,t=1;
while(t==1)
{
	k=0;
	scanf("%lld",&b);
	scanf("%lld",&c);
	if((b==1)&&(c==1))
	break;
	
	while(b>0)
		{
		if((c%b)==0)
		{
		a[k]=c/b;
		++k;
		break;
		}
		i=c/b;
		++i;
		b=(b*i)-c;
		c=c*i;
		a[k]=i;
		++k;
		temp=gcd(b,c);
		b=b/temp;
		c=c/temp;
}
for(i=0;i<k;i++)
printf("%lld ",a[i]);
printf("\n");
}
return 0;
}
