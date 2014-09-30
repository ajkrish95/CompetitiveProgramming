#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
//char e[110000];

int func(int n,int k)
{
	int tmp,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,p[100],a[100],b[100],c[100],d[100],i,j,t=0;
	tmp=n;
	for(i=0;i<100;i++)
	{
		cout<<i<<" "<<tmp<<endl;
		a[i]=0;
	}
	for(i=2;i<=tmp;i++)
	{
		cout<<"sdfsf";
		if((n%i)==0)
		{
			cout<<i<<endl;
			p[t]=i;
			while((n%i)==0)
			{
				++a[t];
				n=n/i;
			}
			++t;
		}
		if(n==1)
		break;
	}
	
	for(a0=0;a0<=a[0];a0++)
	for(a1=0;a1<=a[1];a1++)
	for(a2=0;a2<=a[2];a2++)
	for(a3=0;a3<=a[3];a3++)
	for(a4=0;a4<=a[4];a4++)
	for(a5=0;a5<=a[5];a5++)
	for(a6=0;a6<=a[6];a6++)
	for(a7=0;a7<=a[7];a7++)
	for(a8=0;a8<=a[8];a8++)
	for(a9=0;a9<=a[9];a9++)
	{
		n=n;
	}
	
	for(i=0;i<t;i++)
	{
		cout<<p[i]<<" "<<a[i]<<endl;
	}
}
int main()
{
	int n=121334,k=100;
	func(n,k);
}
