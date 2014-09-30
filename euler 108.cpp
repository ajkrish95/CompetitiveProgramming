#include<iostream>
#include<math.h>
using namespace std;
	
int k;

int func(int q,int j)
{
	int w=0;
	while(q%j==0)
	{
	q=q/j;
	++w;
	}
	k=k*((2*w)+1);
	return q;
}



int afunc(int i)
{
	int j,w=0,t=i;
	for(j=2;j<t;j++)
	{
		w=0;
		if(i%j==0)
		{
			while(i%j==0)
			{
				i=i/j;
				++w;
			}		
		cout<<w<<" ";
		
		}
	}

}



int main()
{
	int i,j,q,m=1; 
	for(i=2;i<3000000;i++)
	{
	k=1;	
	q=i;
	for(j=2;j<200000;j++)
	{
	if(q==1)
	break;
	else
	if(q%j==0)
	q=func(q,j);
	}
	
	if(((k+1)/2)>((m+1)/2))
	{
	afunc(i);
	cout<<endl;
	cout<<m;
	cout<<endl;
	m=k;
}	
	}
	}

