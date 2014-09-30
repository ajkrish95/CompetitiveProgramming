/*
 * A AJAY KRISHNA
 * CS12B001
 * REGULAR EVALUATION EVALUATION 
 * CS2200 - LANGUAGES, MACHINES AND COMPUTATIONS 
 * LANGUAGE USED : C++
*/
 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stack>

using namespace std;


// state stores the start and end state of an automation.
// Our automation has at every stage only one start and one final state.

struct state{
	int start;
	int end;
};

char b[10000]; //b stores the regular expression after modification.
char ch[1000][1000]; // The 2-D character array ch stores the transitons between different states.
char post[10000]; // The string post stores the evaluated postfix expression of the given regular expression.

int node; // node stores the number of states  in the state machine.
int sr; // sr stores the name of the start state.
int en; // en stores the name of the end state.

void evaluate() //The function evaluate evaluates the regular expresion an creates the required NFA.
{
	stack <state> er; // The stack er is used to evaluate the postfix expression to get the NFA.	
	int i,start1,n,start2,end1,end2,start,end,j;
	state tm;
	
	for(i=0;i<990;i++) // Initially none of the states are not connected.
	{
		for(j=0;j<990;j++)
		{
			ch[i][j]='-';//States which have no transitions between them are marked by - .
		}
	}
	
	n=strlen(post);

	for(i=0;i<n;i++) // For loop to evaluate the regular expression to find the NFA.
	{
		if(isalpha(post[i])) // If we see an alphabet just make two new states and push it into the stack.
		{
			ch[node][node+1]=post[i];
			tm.start=node;
			tm.end=node+1;
			er.push(tm);			
			node=node+2;

		}
		
		else
		{
			if(post[i]=='#') //If we see the empry string we create a new node and make it both the initial and the final state and push it into the stack.
			{
				tm.start=node;
				tm.end=node;
				er.push(tm);
				node++;
			}
		
			else
			{	
				if(post[i]=='.') //Concatenation
				{
					
					tm=er.top();
					start2=tm.start;
					end2=tm.end;
					er.pop();
					tm=er.top();
					start1=tm.start;
					end1=tm.end;
					er.pop();
					
					ch[end1][start2]='0';
					tm.end=end2;
					tm.start=start1;
					er.push(tm);
			
				}
				
				else
				{
					if(post[i]=='*') // Kleene closure
					{
						tm=er.top();
						er.pop();
						start=tm.start;
						end=tm.end;
						
						ch[end][node]='0';
						ch[node][start]='0';
						tm.start=node;
						tm.end=node;
						er.push(tm);
						node++;	
						
					}
					
					else
					{
						if(post[i]=='+') // Union
						{
	
							tm=er.top();
							start2=tm.start;
							end2=tm.end;
							er.pop();
							tm=er.top();
							start1=tm.start;
							end1=tm.end;
							er.pop();

							ch[node][start1]='0';							
							ch[node][start2]='0';
							tm.start=node;
							++node;
							ch[end1][node]='0';
							ch[end2][node]='0';
							tm.end=node;
							++node;
							er.push(tm);
						}
					}
				}
			}
		}
	}
	
	tm=er.top();
	sr=tm.start;
	en=tm.end;
	
}

int check_input(char w[10000])// The function check_input checks whether the given input string is accepted by the NFA.
{
	int temp,val,j,k,i,l=1,n,imp,visit[100000],curr[100000];
	
	n=strlen(w);
	
	curr[0]=sr;
	
	for(i=0;i<node;i++)
	{
		if(ch[sr][i]=='0')
		{
			curr[l]=i;
			++l;
		}
	}
	
	imp=1;

	for(j=0;j<node;j++)
	{
		visit[j]=0;
	}
	
	val=l;
			
	while(imp==1) // Collecting the set of all nodes with which we can start off with.
	{
		imp=0;
		
		for(j=0;j<val;j++)
		{
			temp=curr[j];
			
			for(k=0;k<node;k++)
			{
				if(ch[temp][k]=='0'&&visit[k]==0)
				{
					curr[l]=k;
					visit[k]=1;
					++l;
					imp=1;
				}
			}	
		}
		
		val=l;
	}
		
	for(i=0;i<n;i++)//At every stage an array curr is maintained whcih tells us which of the states the given input string reaches at any stage.
	{
		if(w[i]!='#')
		{
		
			l=0;
			
			for(j=0;j<node;j++)
			{
				visit[j]=0;
			}
		
			for(j=0;j<val;j++)
			{
				temp=curr[j];
				
				for(k=0;k<node;k++)
				{
					if(ch[temp][k]==w[i]&&visit[k]==0)
					{
						curr[l]=k;
						visit[k]=1;
						++l;
					}
				}
			}
			
			val=l;
			imp=1;
			
			while(imp==1)
			{
				imp=0;			

				for(j=0;j<val;j++)
				{
					temp=curr[j];
					
					for(k=0;k<node;k++)
					{
						if(ch[temp][k]=='0'&&visit[k]==0)
						{
							curr[l]=k;
							visit[k]=1;
							++l;
							imp=1;
						}
					}	
				}
			
				val=l;
			}
		}
	}
	
	int o=0;
	
	for(i=0;i<l;i++) // If one of the states reached at the end is the final state then it is accepted.
	{
		if(curr[i]==en)
		{
			printf("Yes\n");
			o=1;
			break;
		}
	}	
	
	if(o==0)
	{
		printf("No\n");
	}
}

int check(char a[10000]) //The function check checks whether the input regular expression is a valid one.
{
	int i,count,n;

	n=strlen(a);
	
	for(i=0;i<n;i++)
	{
		if(!isalpha(a[i]))
		{
			if(a[i]!='#'&&a[i]!='*'&&a[i]!='('&&a[i]!=')'&&a[i]!='+')
			{
				return 0;
			}
		}
	}
	
	count=0;
	
	for(i=0;i<n;i++)
	{
		if(a[i]=='(')
		{
			count++;
		}
		
		else
		{
			if(a[i]==')')
			{
				count--;
			}
		}
		
		if(count>1||count<0)
		{
			return 0;
		}
	}
	
	if(count!=0)
	{
		return 0;
	}
	
	for(i=0;i<n-1;i++)
	{
		if(a[i]=='*'&&a[i+1]=='*')
		{
			return 0;
		}

		if(a[i]=='+'&&a[i+1]=='+')
		{
			return 0;
		}
		
		if(a[i]=='('&&a[i+1]==')')
		{
			return 0;
		}
				
		if(a[i]=='('&&a[i+1]=='*')
		{
			return 0;
		}
			
		if(a[i]=='+'&&a[i+1]=='*')
		{
			return 0;
		}

		if(a[i]=='+'&&a[i+1]==')')
		{
			return 0;
		}

		if(a[i]=='('&&a[i+1]=='+')
		{
			return 0;
		}
		
	}
	
	return 1;	
}

void convert() //The function convert converts the given regular expression into postfix form using stacks.
{
	stack <char> st,st1;
	
	int n,i,k=0,val1,val2;
	
	n=strlen(b);
	
	for(i=0;i<n;)
	{
		if(b[i]=='(')
		{
			++i;
			while(b[i]!=')')
			{
				if(isalpha(b[i])||b[i]=='#')
				{
					post[k]=b[i];
					++i;
					++k;
				}		
				
				else
				{
					if(st1.empty())
					{
						st1.push(b[i]);
						++i;
					}
								
					else
					{					
						
						if(b[i]=='+')
						{
							val1=1;
						}
	
						if(b[i]=='.')
						{
							val1=2;
						}
	
						if(b[i]=='*')
						{
							val1=3;
						}
											
						if(st1.top()=='+')
						{
							val2=1;
						}	
	
						if(st1.top()=='.')
						{
							val2=2;
						}
		
						if(st1.top()=='*')
						{
							val2=3;
						}
						
					
						while(val1<val2)
						{
							post[k]=st1.top();
							k++;
							st1.pop();
							
							if(st1.empty())
							{
								break;
							}	
										
							if(st1.top()=='+')
							{
								val2=1;
							}			
	
							if(st1.top()=='.')
							{
								val2=2;
							}
				
							if(st1.top()=='*')
							{
								val2=3;
							}							
						}
							
						st1.push(b[i]);
						++i;
					}
				}
			}
			++i;
				
			while(!st1.empty())
			{
				post[k]=st1.top();
				++k;
				st1.pop();
			}
		}
		
		else
		{		
			while(b[i]!='(')
			{
				
				if(isalpha(b[i])||b[i]=='#')
				{
					post[k]=b[i];
					++i;
					++k;
				}
				
						
				
				else
				{
					if(st.empty())
					{
						st.push(b[i]);
						++i;
					}
								
					else
					{					
						
						if(b[i]=='+')
						{
							val1=1;
						}
	
						if(b[i]=='.')
						{
							val1=2;
						}
	
						if(b[i]=='*')
						{
							val1=3;
						}
											
						if(st.top()=='+')
						{
							val2=1;
						}	
	
						if(st.top()=='.')
						{
							val2=2;
						}
		
						if(st.top()=='*')
						{
							val2=3;
						}
						
					
						while(val1<val2)
						{
							post[k]=st.top();
							k++;
							st.pop();
								
							if(st.empty())
							{
								break;
							}	
				
							if(st.top()=='+')
							{
								val2=1;
							}			
	
							if(st.top()=='.')
							{
								val2=2;
							}
				
							if(st.top()=='*')
							{
								val2=3;
							}							
						}
							
						st.push(b[i]);
						++i;
					}
				}
				
				if(i==n)
				{
					break;
				}
			}
		}
	}
	
	while(!st.empty())
	{
		post[k]=st.top();
		++k;
		st.pop();
	}
	
	post[k]='\0';
		
}

int main()
{
	
	char a[10000],p[10000];
	
	int y,i,k,n;
	
	scanf("%s",a); // a is the input for the regular expression.
	
	k=0;
		
	y=check(a);
		
	if(y==1)
	{
		
		for(i=0;i<strlen(a)-1;i++) //This for loop is used to add .'s to the expression to make evaluation of it easier. 
		{
			if((isalpha(a[i])||a[i]=='#')&&(isalpha(a[i+1])||a[i+1]=='#'))
			{
				b[k]=a[i];
				++k;
				b[k]='.';
				++k;
			}
				
			else
			{
				if(a[i]=='*'&&a[i+1]=='(')
				{
					b[k]=a[i];
					++k;
					b[k]='.';
					++k;
				}
						
				else
				{
					if(a[i]=='*'&&(isalpha(a[i+1])||a[i+1]=='#'))
					{
						b[k]=a[i];
						++k;
						b[k]='.';
						++k;			
					}
				
					else
					{
					
						if((isalpha(a[i])||a[i]=='#')&&a[i+1]=='(')
						{
							b[k]=a[i];
							++k;
							b[k]='.';
							++k;
						}
			
						else
						{
							if(a[i]==')'&&(isalpha(a[i+1])||a[i+1]=='#'))
							{
								b[k]=a[i];
								++k;
								b[k]='.';
								++k;
							}
								
							else
							{
								if(a[i]==')'&&a[i+1]=='(')
								{
									b[k]=a[i];
									++k;
									b[k]='.';
									++k;	
								}
							
								else
								{
									b[k]=a[i];
									++k;
								}
							}
						}
					}	
				}
			}
		}
	
		b[k]=a[i];//The string b stores the new easier to evaluate regular expression.
		++k;
		
		b[k]='\0';
	
		convert();
		
	    evaluate();
	}

	else
	{
		printf("INVALID INPUT\n");
	}
	
	if(y==1)
	{
		scanf("%d",&n);
		
		while(n--)
		{	
			scanf("%s",p);	
			check_input(p);
		}
	}
	
	return 0;
}
