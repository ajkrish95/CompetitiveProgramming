#include<stdio.h>
int main()
{
	long long int a[3],p,tmp,count,t,x;
	fscanf(stdin,"%lld",&t);
	for(i=0;i<15;i++)
	{
		p=b[i];
		count=1;
		a[0]=0;
		a[1]=1;
		while(a[1]!=x)
		{
			++count;
			tmp=a[1];
			a[1]=a[0]+a[1];
			a[0]=tmp;
			a[0]=a[0]%p;
			a[1]=a[1]%p;
			printf("%d",a[1]);
			if((count>p)||(a[0]==0&&a[1]==1))
			break;
		}
		
	}
}
}
return 0;
}

