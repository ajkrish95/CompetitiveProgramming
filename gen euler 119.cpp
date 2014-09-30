#include<iostream>
#include<math.h>
using namespace std;


int main()
{
	unsigned long long int tmp,temp,o=0,t,i,j,sum,k;
	for(i=10;i<10000000000000000;i++)
	{
		t=i;
		sum=0;
		while(t!=0)
		{
		sum=sum+t%10;
		t=t/10;	
		}
		tmp=sum%10;
		temp=i%10;
		if((tmp==0&&temp==0)||(tmp==1&&temp==1)||(tmp==9&&((temp==9)||(temp==1)))||((tmp==6)&&temp==6)||(tmp==5&&temp==5)||(tmp==4&&((temp==4)||(temp==6)))||(tmp==3&&((temp==3)||(temp==9)||(temp==1)||(temp==7)))||(tmp==7&&((temp==7)||(temp==9)||(temp==1)||(temp==3)))||(tmp==2&&((temp==2)||(temp==4)||(temp==8)||(temp==6)))||(tmp==8&&((temp==8)||(temp==4)||(temp==2)||(temp==6))))
		{
		for(j=1;j<1000;j++)
		{
			k=pow(sum,j);
			if(k==i)
			{
				++o;
				cout<<o;
				cout<<" ";
				cout<<i;
				cout<<endl;
				break;
			}	
			if(k>i)
				break;
			}
		}
		}
	}
	
