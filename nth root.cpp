#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n;
	float q;
	//Code to find nth root of q;
	
	cin>>q;
	cin>>n;
	
	float guess=q/2,a,b,c;
	int j,suit_num=100;
	
	for(j=1;j<suit_num;j++)
	{
		a=(n-1)*guess;
		b=pow(guess,n-1);
		b=1/b;
		b=b*q;
		guess=a+b;
		guess=guess/n;
	}
	cout<<guess;
}
