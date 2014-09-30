#include<stdio.h>
#include<iostream>

using namespace std;

long long int n,x;

long long int mult(long long int a,long long int b)
{
	long long int i,ans = 0,temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9;
	
	temp1 = a%(100000000);
	temp2=a/100000000;
	temp3 = b%(100000000);
	temp4=b/100000000;
	
	temp5 = temp1*temp3;
	temp6 = temp1*temp4;
	temp7 = temp2*temp3;
	temp8 = temp2*temp4;
	
	for(i=0;i<16;i++)
	{
		temp7=(temp7*10)%n;
	}

	for(i=0;i<8;i++)
	{
		temp6=(temp6*10)%n;
	}

	for(i=0;i<8;i++)
	{
		temp8=(temp8*10)%n;
	}

	temp9 = temp5+temp6+temp7+temp8;
	
	return (temp9)%n;
}

long long int poww(long long a, long long b)
{
	if(b==0)return 1;
	if(b==1)return a;
	long long temp = poww(a,b/2);
	if(b%2 == 0)
	{
		return mult(temp,temp)%n;
	}	
	return mult(mult(temp,temp),a)%n;
}

long long int solve(long long int m)
{
	long long int temp1,temp2,temp3,temp4;
	
	
	if(m==0)
	{
		return 0;
	}
	
	if(m==1)
	{
		return (x)%n;
	}
	if(m%2==0)
	{
		temp1 = solve(m/2)%n;
		temp2 = poww(x,m/2)%n;
		temp3 = (mult((temp1),(temp2+1)))%n;
	//	cout<<m<<" "<<temp1<<" "<<temp2<<" "<<temp3<<endl;
		return temp3;
	}
	
	else
	{
		temp1 = solve(m/2)%n;
		temp2 = poww(x,m/2)%n;
		temp3 = (mult((temp1),(temp2+1)))%n;		
		temp4 = (temp3 + poww(x,m))%n;
	//	cout<<m<<" "<<temp4<<endl;
		return temp4;
	}
}

int main()
{
	int t;
	long long ans, m;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d%d%d",&x,&m,&n);
		
		ans = solve(m)+1;
		ans %= n;
		
		printf("%lld\n",ans);
	}
	
	
}
