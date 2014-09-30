#include<stdio.h>
int main( int argc, char* argv[] )
{
	int a[121],k,b,i,j;
FILE* fp=fopen(argv[1],"r");
for(i=1;i<121;i++)
fscanf(fp,"%d",&a[i]);	
	k=92,b=14;
	while(b>0)
	{
	for(i=k;i<k+b;i++)
	if(a[i+b]>=a[i+b+1])
	a[i]=a[i]+a[i+b];
	else
	a[i]=a[i]+a[i+b+1];
	k=k-b+1;
	b=b-1;
	}
printf("%d\n",a[1]);
}
