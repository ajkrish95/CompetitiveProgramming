#include<iostream>

using namespace std;

class line
{
	int length;
	
	public:
		
	friend int blah(line small)
	{
		cout<<small.length;
		return 67;
	}	
	line()
	{
		cout<<"suck it bitches\n";
		length = 101;
	}
	int lines()
	{
		cout<<"suck it bitches\n";
	}	
	
};

int main()
{
	int a = 5 , b =5 , c= 5;
	
	cout<<(a+a<<b);
}
