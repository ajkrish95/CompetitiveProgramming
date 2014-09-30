#include<iostream>
#include<stdio.h>
#include<stack>
#include<string.h>
#include<fstream>

using namespace std;

class Matrix
{
	
public:
	
	int size;
	int mat[100][100];

	Matrix(int N)
	{
		int i,j;
		for(i=0;i<N;i++)
		for(j=0;j<N;j++)
		mat[i][j]=0;
	}
	
    void matrix(int N, int arr[100][100])
    {
    	size = N;
    	int i,j;
    	
		for (i = 0; i<N; i++)
    	{
        	for (j=0; j<N; j++)
			{
        		mat[i][j] = arr[i][j];
    		}
		}
    }

    Matrix multiply( Matrix m )
    {
		int i,j,k;
		
		Matrix ans(m.size);
		
		ans.size = m.size;
		
		for (i=0; i<size; i++)
		{
			for (j=0; j<size; j++)
			{
				for (k=0; k<size; k++)
				{	
					ans.mat[i][j] = ans.mat[i][j] + m.mat[i][k]*mat[k][j];
				}
			}
		}
		
		return ans;
    }

    Matrix const_multiply(int constant)
    {
		Matrix ans(size);
		
		for (int i=0; i<size; i++)
		{
			for (int j=0; j<size; j++)
			{
					ans.mat[i][j] = constant * mat[i][j];
			}
		}
		
		return ans;
    }

    Matrix add(Matrix m)
    {

		Matrix ans(size);
		
		for (int i=0; i<size; i++)
		{
			for (int j=0; j<size; j++)
			{
				ans.mat[i][j] = m.mat[i][j] + mat[i][j];
			}
		}
		return ans;	
    }
};

class token
{
	public:
	Matrix m = NULL;
	int n;
	char ch;
	int i;
};

int main(int argc, char** argv)
{
	ifstream fp(argv[1]);
	ifstream fp2(argv[2]);
	int l,o,error,i,j,k,num,n,b[100][100];
	char  str[100];
	//fp>>str;
	fp>>n;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	fp>>b[i][j];
	
	while (fp2 >> str)
	{
	
	Matrix m(n);
	
	m.matrix(n,b);
	
	token a,c,d,an;
	
	stack <token> stk,stk2,stk3;
	
	error = 0;
	
	
	for(i=0;i<strlen(str);i++)
	{
		if(str[i]=='('&& (i+1)<strlen(str)&&((str[i+1]==')')||(str[i+1]=='*')||(str[i+1]=='+')))
		error = 1;
		
		if(str[i]=='+'&&(i+1)<strlen(str)&&((str[i+1]=='*')||(str[i+1]=='+')||(str[i+1]==')')))
		error =1;
		
		if(str[i]=='*'&&(i+1)<strlen(str)&&((str[i+1]=='*')||(str[i+1]=='+')||(str[i+1]==')')))
		error =1;
		
		if(str[i]==')'&&(i+1)<strlen(str)&&((str[i+1]=='(')||(str[i+1]=='A')||(isdigit(str[i+1]))||(str[i+1]=='(')))
		error =1;

		if(str[i]=='A'&&(i+1)<strlen(str)&&((str[i+1]=='A')||(str[i+1]=='(')||isdigit(str[i])))
		error =1;
		
		if(str[i]=='+'&&(i+1==strlen(str)))
		error=1;

		if(str[i]=='('&&(i+1==strlen(str)))
		error=1;

		if(str[i]=='*'&&(i+1==strlen(str)))
		error=1;	
		
		if(isdigit(str[i]))
		{
			while(isdigit(str[i]))
			{
				i++;
			}
			
			i--;
			if((i+1)<strlen(str)&&((str[i+1]=='A')||(str[i+1]=='(')))
			{
				error =1;
			}
		}	
	
	}
	
	
	
	if(error==0)
	{
		for(i=0;i<strlen(str);i++)
		{
			
			if(str[i]=='A')
			{
				(a.m).matrix(n,b);
				
				a.i=1;
				stk2.push(a);
			}
			
			if(str[i]=='(')
			{
				a.i= 3;
				a.ch = '(';
				stk.push(a);
			}
			
			if(str[i] == '+')
			{
				a.i=3;
				a.ch='+';
				
				if((!stk.empty())&&((stk.top()).i == 3) && (((stk.top()).ch == '+')||((stk.top()).ch == '*')))
				{
					stk2.push(stk.top());
					stk.pop();
					stk.push(a);
				}
				
				else
				{
					stk.push(a);
				}
			}
	
			if(str[i] == '*')
			{
				a.i=3;
				a.ch='*';
				
				if((!stk.empty())&&((stk.top()).i == 3) && (((stk.top()).ch == '*')))
				{
					stk2.push(stk.top());
					stk.pop();
					stk.push(a);
				}
				
				else
				{
					stk.push(a);
				}
			}
			
			if(isdigit(str[i]))
			{
				num = str[i] - '0';
				k=i+1;
				while(k<strlen(str) && isdigit(str[k]))
				{
					num = 10*num + str[k]-'0';
					k++;
				}
				i=k-1;
				
				a.i = 2;
				a.n = num;
				stk2.push(a);
				
			}
			
			if(str[i]==')')
			{
				k=i;
				
				while((stk.top().i!=3) || (stk.top().ch!='('))
				{
					stk2.push(stk.top());
					stk.pop();				
				}
				
				if(!stk.empty()&&stk.top().i==3&&stk.top().ch=='(')
				{
					stk.pop();
				}
			}
		}
		
		while(!stk.empty())
		{
			a = stk.top();
			stk2.push(a);
			stk.pop();
		}	
			
		while(!stk2.empty())
		{
			stk3.push(stk2.top());
			stk2.pop();	
		}
	   
	int count = 0;
	
		while(!stk3.empty())
		{

			if(stk3.top().i == 1)
			{
				stk2.push(stk3.top());
				stk3.pop();
			}
			
			else
			{
				if(stk3.top().i == 2)
				{
					stk2.push(stk3.top());
					stk3.pop();
				}
				
				else
				{
					if(stk3.top().i == 3 )
					{
						d = stk3.top();
						stk3.pop();
						
						if(stk2.empty())
						{
							error = 1;
							break;
						}
						
						else
						{
							a = stk2.top();
							stk2.pop();
							
							if(stk2.empty())
							{
								error =1;
								break;
							}
							
							else
							{
								c = stk2.top();
								stk2.pop();
								
								if(d.i==3 && d.ch == '+')
								{
									
									if(!((a.i==2 &&c.i==2)||(a.i==1)&&(c.i==1)))
									{
										error =1;
										break;
									}
									
									else
									{
										if((a.i==2)&&c.i==2)
										{
											an.i = a.i;
											an.n = a.n+c.n;
											stk2.push(an);
										}
										
										if(a.i==1&&c.i==1)
										{
											an.m = a.m.add(c.m);
											an.i = a.i;
											stk2.push(an);
										}
										
									}
								}
								
								else
								{
									if((a.i==2)&&c.i==1)
									{
										error = 1;
										break;
									}
									
									if((a.i==2)&&c.i==2)
									{
										an.i = a.i;
										an.n = a.n*c.n;
										stk2.push(an);
									}
										
									if(a.i==1&&c.i==1)
									{
										an.m = a.m.multiply(c.m);
										an.i = a.i;
										stk2.push(an);
									}
									
									if(a.i==1&&c.i==2)
									{
										an.i=a.i;
										an.m=a.m.const_multiply(c.n);
										stk2.push(an);
									}
									
								}
							}
						}
					}
				}
			}
		}
		
		if(error==0)
		{
			if(!stk2.empty())
			{
				if(stk2.top().i==1)
				{
					
					for(i=0;i<n;i++)
					{
						for(j=0;j<n-1;j++)
						{
							cout<<stk2.top().m.mat[i][j]<<" ";
						}
						
						cout<<stk2.top().m.mat[i][n-1]<<endl;
					}
				}
				
				else
				{
					cout<<stk2.top().n;
				}
			}
			
		}
		
		else
		{
			cout<<"error\n\n";
		}

	}
	
	else
	{
		cout<<"error\n\n";
	}
}
}

	
