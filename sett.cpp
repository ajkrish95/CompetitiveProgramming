#include<set>
#include<iostream>

using namespace std;

int main()
{
	int i,j;
	
	set <int> set;
	set.insert(7);
	
	if(set.find(8)==set.end())
	{
		cout<<"ghgfh\n";
	}
	
		int a[5] = {1,1,2,2,2};
	int *beg,*end;
	
	beg = lower_bound(a,a+5,2);
	end = upper_bound(a,a+5,2);
	
	int b = end - beg;
	cout<<b;Z
}
