#include<iostream>
#include<math.h>
using namespace std;
int main()
{	
unsigned long long int a,b,c,n;
n=100;
a=n*n*(n+1)*(n+1);
a=a/4;
b=n*(n+1)*((2*n)+1);
b=b/6;
c=a-b;
cout<<c;
return 0;
}

