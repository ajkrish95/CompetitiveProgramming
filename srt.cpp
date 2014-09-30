#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stack>
#include<bitset>
#include<string>
using namespace std;
int main()
{
	//bool myfunction (int i,int j) { return (i<j); }
	//std::sort (myvector.begin()+4, myvector.end(), myfunction); 
	//if (std::binary_search (v.begin(), v.end(), 3))
	std::bitset<5> foo (std::string("01011"));
	std::vector<int> myvector;
	std:: bitset<10> bits;
	
	bits[0]=0;
	bits[1]=2;
	bits[2]=int('k');
	cout<<bits[0]<<endl;
	cout<<bits[1]<<endl;
	cout<<bits[2]<<endl;
	myvector.push_back (100);
	myvector.push_back (200);
	
	cout<<myvector[0]<<endl;
	queue <int> queue;
	queue.push(10);
	queue.push(20);
	queue.push(30);
	
	cout<<queue.front()<<endl;
	cout<<queue.back()<<endl;
	queue.pop();
	
	cout<<queue.front()<<endl;
	queue.pop();
	queue.pop();
	
	stack<int> stack;
	stack.push(1000);
	cout<<stack.top()<<endl;
			
	if(!queue.empty())
	{
		cout<<"eafsdf\n";
	}
	int a[5];
	a[0]=5;
	a[1]=4;
	a[2]=3;
	a[3]=2;
	a[4]=1;
	
	sort(a,a+5);
	
	cout<<a[0]<<endl;
	cout<<a[1]<<endl;
	cout<<a[2]<<endl;
	cout<<a[3]<<endl;
	cout<<a[4]<<endl;
}


