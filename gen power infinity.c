#include<stdio.h>
#include<math.h>
int main()
{
unsigned long long int max=0,j,k=0,a,i;
a=1000000000000000000;
printf("%llu",a);
for(i=1;i<a;i++)
{
k=0;
for(j=0;j<sqrt(i);j++)
{
if(a%i==0)
++k;
}
if(k>max)
max=k;
}
printf("%llu",max);
}
