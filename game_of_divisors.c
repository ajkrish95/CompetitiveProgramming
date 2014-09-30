#include<stdio.h>

#define get getchar_unlocked

inline int scan()
{
    int n=0,s=1;
    char p=get();
    if(p=='-')  s=-1;
    while((p<'0'||p>'9')&&p!=EOF&&p!='-') p=get();
    if(p=='-') s=-1,p=get();
    while(p>='0'&&p<='9') { n = (n<< 3) + (n<< 1) + (p - '0'); p=get(); }
    return n*s;
}
 
void print(int X)
{
  if(X<0) { putchar_unlocked('-');  X=-X;  }
  int Len=0,Data[40];
  while(X) { Data[Len++]=X%10; X/=10; }
  if(!Len) Data[Len++]=0;
  while(Len--) putchar_unlocked(Data[Len]+48);
}

int main()
{
	int p[10010],a[10010],i,j,k,t,b,n;
		
	for(i=0;i<=10000;i++)
	{
		p[i] = 0;
	}

	k=0;
	
	for(i=2;i<=10000;i++)
	{
		if(p[i]==0)
		{
			a[k] = i;
			++k;
			for(j=i;i*j<=10000;j++)
			{
				p[i*j] = 1;
			}
		}
	}

	t = scan();
	
	while(t--)
	{
		n = scan();
		
		if(n==2||n==17)
		{
			putchar_unlocked('M');
			putchar_unlocked('i');
			putchar_unlocked('k');
			putchar_unlocked('e');
			putchar_unlocked('\n');
		}
		
		else
		{
			if(n==16||n==34||n==289)
			{
				putchar_unlocked('T');
				putchar_unlocked('o');
				putchar_unlocked('m');
				putchar_unlocked('\n');	
			}
			
			else
			{
				if(n<=10000)
				{
					if( p[n] == 0 )
					{
						putchar_unlocked('T');
						putchar_unlocked('o');
						putchar_unlocked('m');
						putchar_unlocked('\n');	
					}
					
					else
					{
						putchar_unlocked('M');
						putchar_unlocked('i');
						putchar_unlocked('k');
						putchar_unlocked('e');
						putchar_unlocked('\n');
					}					
				}
				
				else
				{
					b = 0;
					
					for(i=0;a[i]*a[i]<=n&&i<k;i++)
					{
						if(n%a[i]==0)
						{
							b = 1;
							break;
						}
					}
					
					if( b == 0 )
					{
						putchar_unlocked('T');
						putchar_unlocked('o');
						putchar_unlocked('m');
						putchar_unlocked('\n');	
					}
					
					else
					{
						putchar_unlocked('M');
						putchar_unlocked('i');
						putchar_unlocked('k');
						putchar_unlocked('e');
						putchar_unlocked('\n');
					}
				}
			}
		}
		
		
	}
	
}
