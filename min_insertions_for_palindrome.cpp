#include<stdio.h>
#include<string>
#include<iostream>
#include<string.h>

using namespace std;

int count=0,pal[100][100];

int func(int beg,int end,string a)
{
	count++;
	
	if(beg==end)
	{
		pal[beg][end] = 0;
		return pal[beg][end];
	}
	
	if(beg>end)
	{
		return 0;
	}
	
	if(pal[beg][end]!=-1)
	{
		return pal[beg][end];
	}
	if(a[beg]==a[end])
	{
		pal[beg][end] = func(beg+1,end-1,a);
	}
	
	else
	{
		pal[beg][end] = min(func(beg+1,end,a),func(beg,end-1,a)) + 1;
	}
	
	return pal[beg][end];
}


int main()
{
	int *p,beg, end, ans,i,j;
	string a;
	
	cin>>a;
		
	end = a.length();
	beg = 0;
	
	memset(pal,-1,sizeof(pal));
	
	p = &pal[i][j];
	
	/*
	for(i=0;i<end;i++)
	{
		for(j=0;j<end;j++)
		{
			cout<<i<<" "<<j<<" "<<&pal[i][j]<<" "<<pal[i][j]<<endl;
		}
	}

	cout<<endl<<endl;
	for(i=0;i<end;i++)
	{
		for(j=0;j<end;j++)
		{
			cout<<i<<" "<<j<<" "<<p++<<" "<<pal[i][j]<<endl;
		}
	}
	*/
	
	ans = func(beg,end-1,a);
	cout<<ans;
	
	
}
