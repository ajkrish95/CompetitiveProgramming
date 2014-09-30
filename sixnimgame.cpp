#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	int a,b,c,d,e,f;
	
	cin>>a>>b>>c>>d>>e>>f;
	
	if(((a+b)==(d+e))&&((b+c)==(e+f)))
	{
		cout<<"Losing"<<endl;
	}
	
	else
	{
		cout<<"Winning"<<endl;
	}
}
