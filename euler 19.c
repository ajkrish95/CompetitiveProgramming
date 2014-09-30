#include<stdio.h>
int main()
{
	int a[101],i,j,sum=0;
	a[0]=1;
	sum=0;
	for(i=0;i<100;i++)
	{
	if((((1900+i)%4)!=0)||(((1900+i)%100)==0&&((1900+i)%400)!=0))
	a[i+1]=a[i]+1;
	else
	a[i+1]=a[i]+2;
	if(a[i+1]>7)
	a[i+1]=a[i+1]-7;
	if(a[i+1]>4)
	sum=sum+5;
	else
	sum=sum+4;
	printf("%d %d \n",a[i+1],sum);
	}
	printf("%d",sum);
	return 0;
}
