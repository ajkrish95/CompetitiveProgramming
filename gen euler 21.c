#include<stdio.h>
int main()
{
	long long int a[200003],sum=0,i,j;
	for(i=3;i<100003;i++)
	{
	a[i]=0;
}
a[0]=0;
	a[1]=1;
	a[2]=1;
	for(i=3;i<50000;i++)
	{
		sum=1;
		for(j=2;j<i;j++)
		if(i%j==0)
		sum=sum+j;
	a[i]=sum;
	}
	sum=0;
	for(i=1;i<50000;i++)
	{
	j=a[i];
	if(a[j]==i&&i!=j)
	{
	sum=sum+i;
	printf("%d %d \n",i,j);
}
}
printf("%d",sum);
return 0;
}
