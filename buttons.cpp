#include<stdio.h>
 
#define get getchar_unlocked
 
int a[1001][1001],b[1001][1001],temp[1001][1001];
 
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
	int i,j,k,n,t,ans,ct,ctt,ct1,ctt1,pos,rea,real,row[1001],col[1001],row1[1001],col1[1001];
	
	t = scan();
	
	while(t--)
	{
		n = scan();
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j] = scan();
				temp[i][j] = a[i][j];			
			}
		}
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				b[i][j] = scan();			
			}
		}
		
		ct = 0;
		ctt = 0;
		
		for(i=0;i<n;i++)
		{
			if(temp[0][i]!=b[0][i])
			{
				col[ct] = i;
				ct++;
				
				for(j=0;j<n;j++)
				{
					if(temp[j][i]==0)
					{
						temp[j][i] = 1;
					}
					
					else
					{
						temp[j][i] = 0;	
					}
				}
			}
		}
				
		for(i=1;i<n;i++)
		{
			if(temp[i][0]!=b[i][0])
			{
				ans  = ans + 1;
				row[ctt] = i;
				ctt++;
				
				for(j=0;j<n;j++)
				{
					if(temp[i][j]==0)
					{
						temp[i][j] = 1;
					}
					
					else
					{
						temp[i][j] = 0;	
					}
				}
			}
		}	
		
		pos = 0;
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(temp[i][j]!=b[i][j])
					pos = -1;
			}
		}
		
		if(pos == -1)
			rea = -1;
		
		else
			rea = ct + ctt; 
			
			
			
		ans = 1;
		ct1 = 0;
		ctt1 = 1;
		row1[0] = 0;
		
		
		for(i=0;i<n;i++)
		{
			if(a[0][i]==0)
			{
				a[0][i] = 1;
			}
			
			else
			{
				a[0][i] = 0;	
			}
		}
		
		for(i=0;i<n;i++)
		{
			if(a[0][i]!=b[0][i])
			{
				col1[ct1] = i;
				ct1  = ct1 + 1;
				
				
				for(j=0;j<n;j++)
				{
					if(a[j][i]==0)
					{
						a[j][i] = 1;
					}
					
					else
					{
						a[j][i] = 0;	
					}
				}
			}
		}

		for(i=1;i<n;i++)
		{
			if(a[i][0]!=b[i][0])
			{
				row1[ctt1] = i;
				ctt1  = ctt1 + 1;
				
				for(j=0;j<n;j++)
				{
					if(a[i][j]==0)
					{
						a[i][j] = 1;
					}
					
					else
					{
						a[i][j] = 0;	
					}
				}
			}
		}	
		
		pos = 0;
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]!=b[i][j])
					pos = -1;
			}
		}
		
		if(pos == -1)
			real = -1;
		
		else
			real = ct1+ctt1; 			
		
		if(rea==-1&&real==-1)
		{
			putchar_unlocked('-');
			putchar_unlocked('1');
			putchar_unlocked('\n');
		}
		
		else
		{
			if(rea==0||real==0)
			{
				putchar_unlocked('0');
				putchar_unlocked('\n');
			}
			
			else
			{
				if(rea<=real)
				{
					print(ctt);
					putchar_unlocked('\n');
					for(i=0;i<ctt;i++)
					{
						print(row[i]);
						putchar_unlocked('\n');
					}

					print(ct);
					putchar_unlocked('\n');
					for(i=0;i<ct;i++)
					{
						print(col[i]);
						putchar_unlocked('\n');
					}
				}
				
				else
				{
					print(ctt1);
					putchar_unlocked('\n');
					for(i=0;i<ctt1;i++)
					{
						print(row1[i]);
						putchar_unlocked('\n');
					}
					print(ct1);
					putchar_unlocked('\n');
					for(i=0;i<ct1;i++)
					{
						print(col1[i]);
						putchar_unlocked('\n');
					}					
				}
			}
		}
	}	
}
