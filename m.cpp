#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

long long int a[100010];

int main()
{
int i,t,n,k;
long long int temp,ans;
cin>>t;

while(t--)
{
cin>>n>>k;

for(i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);

ans=10000000000;

for(i=0;i+k-1<n;i++)
{
temp = a[i+k-1]-a[i];

if(temp<ans)
ans=temp;
}
cout<<ans<<endl;
}
}
