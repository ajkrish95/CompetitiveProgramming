#include<stdio.h>
#include<string.h>

int c[2100][2100];

int main()
{
	int i,t,j,ans,temp1,temp2,temp3,mini;
	char a[2100],b[2100];

	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%s",a);
		scanf("%s",b);
		
		memset(c,-1,sizeof(c));	
		
		for(i=0;i<strlen(a);i++)
		{
			c[i][strlen(b)] = strlen(a)-i;
		}

		for(i=0;i<strlen(b);i++)
		{
			c[strlen(a)][i] = strlen(b)-i;
		}
		
		c[strlen(a)][strlen(b)]=0;
		
		for(i=strlen(a)-1;i>=0;i--)
		{
			for(j=strlen(b)-1;j>=0;j--)
			{
				if(a[i]==b[j])
				{
					c[i][j]=c[i+1][j+1];
				}
				
				else
				{
					temp1 = c[i+1][j+1] + 1;		
					temp2 = c[i+1][j] + 1;
					temp3 = c[i][j+1] + 1;
					
					mini = temp1;
					if(temp2<mini)
					mini=temp2;
					if(temp3<mini)
					mini=temp3;
				
					c[i][j] = mini;					
				}
			}
		}

		
		ans = c[0][0];
	
		printf("%d\n",ans);
		
	}
	return 0;
}
