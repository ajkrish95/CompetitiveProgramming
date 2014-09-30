#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	unsigned long long int w,e,sum,i,q,t=0,j,k,a[100000],temp;
	q=1000000000000000;
	for(i=1;i<70;i++)
	{
		w=i%10;
		for(j=1;j<100;j++)
		{
			sum=0;
			k=pow(i,j);
			temp=k;
			e=k%10;
			if((w==0&&e==0)||(w==1&&e==1)||(w==9&&((e==9)||(e==1)))||((w==6)&&e==6)||(w==5&&e==5)||(w==4&&((e==4)||(e==6)))||(w==3&&((e==3)||(e==9)||(e==1)||(e==7)))||(w==7&&((e==7)||(e==9)||(e==1)||(e==3)))||(w==2&&((e==2)||(e==4)||(e==8)||(e==6)))||(w==8&&((e==8)||(e==4)||(e==2)||(e==6))))
			{
			while(temp!=0)
			{
			sum=sum+temp%10;
			temp=temp/10;	
			}
			if(i==sum)
			{
			a[t]=k;
			++t;
			}
			if(k>q)
			break;
	}
	
}
}
for(i=0;i<t;i++)
for(j=i+1;j<t;j++)
{
	if(a[j]<a[i])
	{
		temp=a[j];
		a[j]=a[i];
		a[i]=temp;
	}
}
temp=1;
for(i=0;i<t;i++)
{
	if(a[i]>9)
	{
	cout<<temp;
	++temp;
	cout<<" ";
	cout<<a[i];
	cout<<endl;
}
}

return 0;
}
