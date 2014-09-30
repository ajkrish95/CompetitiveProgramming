/* 
 * A AJAY KRISHNA
 * IIT-M
 * CS12B001
 * INDIX -CODING CHALLENGE
*/

#include<stdio.h>
#include <stdlib.h>

int start,end,blks,chns,*a,*b,*bl,*cum_dis,*inc,*dec,ans,present_back1,present_back2;
int next_back1,next_back2,next_back3,i,first,last,emp[3],temp[3],present_back3;

//comments for what the different variables hold are written as and when they are used.

//I have not made any assumptions which are not clear from the question.

/* I have used an algorithm which keeps track of the best possible solution at every stage for three possible back channels 
 * and then computes the best possible solution for the three possible future back channels.
 */
 
int min(int f,int g)//Function which returns minimum of two integers.
{
	if(f<g)
	{
		return f;
	}	
	
	else
	{
		return g;
	}
}

void input()//Function which takes input for this code.
{	
	scanf("%d",&start);	//stores the lowest channel available.
	scanf("%d",&end); //stores the lowest channel available.
	
	scanf("%d",&blks); //blks stores the number of blocked channels.
	
	a=(int*)malloc(sizeof(int)*(end+2));
	b=(int*)malloc(sizeof(int)*(end+2));
	bl=(int*)malloc(sizeof(int)*(end+2));
	cum_dis=(int*)malloc(sizeof(int)*(end+2));
	inc=(int*)malloc(sizeof(int)*(end+2));
	dec=(int*)malloc(sizeof(int)*(end+2));

		
	for(i=0;i<blks;i++)
	{
		scanf("%d",&a[i]);// The array a stores the blocked channels.
	}

	scanf("%d",&chns);// chns stores the number of channels to be visited.
	
	for(i=0;i<chns;i++)
	{
		scanf("%d",&b[i]);// The array b stores the channels which are to be visited in order.
	}	
}

void init()//Initialising various parameters and arrays for future use.
{
	int next,prev;
	
	for(i=0;i<=end;i++)
	{
		bl[i]=1;//Bl[i] tells us which a particular channel is blocked or not.bl[i]=1 <=> channel i is not blocked.
		cum_dis[i]=0;//cum_dis[i] tells us how many ups from the first unblocked channel will get us to i.
		inc[i]=0;// inc[i] stores the channel which we get when we press an up when we are in channel i.
		dec[i]=0;// inc[i] stores the channel which we get when we press a down when we are in channel i.
	}
	
	for(i=0;i<blks;i++)
	{
		bl[a[i]]=-1;// Blocked channels are initialised to -1.
	}
	
	for(i=start;i<=end;i++)
	{
		if(bl[i]==1)
		{
			first=i;// 'first' stores the first unblocked channel's number.
			break;
		}
	}
	
	for(i=end;i>=start;i--)
	{
		if(bl[i]==1)
		{
			last=i;// 'last' stores the last unblocked channel's number.
			break;
		}
	}
	
	for(i=first+1;i<=end;i++)// for loop to initialise the array cum_dis.
	{
		if(bl[i]==1)
		{
			cum_dis[i]=cum_dis[i-1]+1;
		}
		
		else
		{
			cum_dis[i]=cum_dis[i-1];
		}
	}
		
	inc[last]=first;
	dec[first]=last;

	prev=first;
	
	for(i=first+1;i<=end;i++)// for loop to initialise the array dec.
	{
		if(bl[i]==1)
		{
			dec[i]=prev;
			prev=i;
		}
	}	
	
	next=last;
	
	for(i=last-1;i>=start;i--)// for loop to initialise the array dec.
	{
		if(bl[i]==1)
		{
			inc[i]=next;
			next=i;
		}	
	}
	
}

int comp_forw_dist(int st,int en)// Function that tells us how many ups we need to press to go from channel st to channel en.
{
	if(st==en)
	{
		return 0;
	}
	
	if(st<en)
	{
		return cum_dis[en]-cum_dis[st];
	}

	return cum_dis[last]-cum_dis[st]+cum_dis[en]+1; 	
}

int comp_back_dist(int st,int en)// Function that tells us how many downs we need to press to go from channel st to channel en.
{
	if(st==en)
	{
		return 0;	
	}
	
	if(st<en)
	{
		return cum_dis[st]+cum_dis[last]-cum_dis[en]+1;
	}
	
	return cum_dis[st]-cum_dis[en];
}

int size(int n)// function that returns the number of digits in a channel number.
{
	int size=0;
	
	while(n!=0)
	{
		size=size+1;
		n=n/10;
	}
	
	return size;
}

int compute_min_back1()// function that returns the fastest way to go from present channel to the increment of the next channel.
{
	int tmp;
	
	tmp=temp[0]+comp_back_dist(next_back1,present_back1)+1;
	
	if(temp[1]+1+comp_back_dist(next_back1,present_back2)<tmp)
	{
		tmp=temp[1]+comp_back_dist(next_back1,present_back2)+1;
	}

	if(temp[2]+1+comp_back_dist(next_back1,present_back3)<tmp)
	{
		tmp=temp[2]+comp_back_dist(next_back1,present_back3)+1;
	}

	if(min(min(temp[0],temp[1]),temp[2])+comp_back_dist(b[i-1],next_back2)<tmp)
	{
		tmp=min(min(temp[0],temp[1]),temp[2])+comp_back_dist(b[i-1],next_back2);	
	}
	
	if(temp[0]+comp_forw_dist(next_back1,present_back1)+1<tmp)
	{
		tmp=temp[0]+comp_forw_dist(next_back1,present_back1)+1;
	}

	if(temp[1]+comp_forw_dist(next_back1,present_back2)+1<tmp)
	{
		tmp=temp[1]+comp_forw_dist(next_back1,present_back2)+1;
	}

	if(temp[2]+comp_forw_dist(next_back1,present_back3)+1<tmp)
	{
		tmp=temp[2]+comp_forw_dist(next_back1,present_back3)+1;
	}

	if(min(min(temp[0],temp[1]),temp[2])+comp_forw_dist(b[i-1],next_back1)<tmp)
	{
		tmp=min(min(temp[0],temp[1]),temp[2])+comp_forw_dist(b[i-1],next_back1);
	}
	
	if(min(min(temp[0],temp[1]),temp[2])+size(next_back1)<tmp)
	{
		tmp=min(min(temp[0],temp[1]),temp[2])+size(next_back1);
	}
	
	if(min(min(temp[0],temp[1]),temp[2])+size(inc[next_back1])+1<tmp)
	{
		tmp=min(min(temp[0],temp[1]),temp[2])+size(inc[next_back1])+1;
	}
	
	return tmp;	
}

int compute_min_back2()// function that returns the fastest way to go from present channel to the decrement of the next channel.
{
	int tmp;
	
	tmp=temp[0]+comp_back_dist(next_back2,present_back1)+1;
	
	if(temp[1]+1+comp_back_dist(next_back2,present_back2)<tmp)
	{
		tmp=temp[1]+comp_back_dist(next_back2,present_back2)+1;
	}

	if(temp[2]+1+comp_back_dist(next_back2,present_back3)<tmp)
	{
		tmp=temp[2]+comp_back_dist(next_back2,present_back3)+1;
	}

	if(min(min(temp[0],temp[1]),temp[2])+comp_back_dist(b[i-1],next_back2)<tmp)
	{
		tmp=min(min(temp[0],temp[1]),temp[2])+comp_back_dist(b[i-1],next_back2);	
	}
	
	if(temp[0]+comp_forw_dist(next_back2,present_back1)+1<tmp)
	{
		tmp=temp[0]+comp_forw_dist(next_back2,present_back1)+1;
	}

	if(temp[1]+comp_forw_dist(next_back2,present_back2)+1<tmp)
	{
		tmp=temp[1]+comp_forw_dist(next_back2,present_back2)+1;
	}

	if(temp[2]+comp_forw_dist(next_back2,present_back3)+1<tmp)
	{
		tmp=temp[2]+comp_forw_dist(next_back2,present_back3)+1;
	}

	if(min(min(temp[0],temp[1]),temp[2])+comp_forw_dist(b[i-1],next_back2)<tmp)
	{
		tmp=min(min(temp[0],temp[1]),temp[2])+comp_forw_dist(b[i-1],next_back2);
	}
	
	if(min(min(temp[0],temp[1]),temp[2])+size(next_back2)<tmp)
	{
		tmp=min(min(temp[0],temp[1]),temp[2])+size(next_back2);
	}

	if(min(min(temp[0],temp[1]),temp[2])+size(inc[next_back2])+1<tmp)
	{
		tmp=min(min(temp[0],temp[1]),temp[2])+size(inc[next_back2])+1;
	}

	return tmp;	
}


/*
 *function that returns the fastest way to go from present channel to the next channel keeping the present channel as the new back.
*/
int compute_min_back3()
{
	int tmp;
	
	tmp=min(min(temp[0],temp[1]),temp[2])+size(b[i]);
					
	if(b[i]==present_back1)
	{
		if(temp[0]+1<tmp)
		{
			tmp=temp[0]+1;
		}	
	}
					
	if(b[i]==present_back2)
	{
		if(temp[1]+1<tmp)
		{
			tmp=temp[1]+1;
		}		
	}

	if(b[i]==present_back3)
	{
		if(temp[2]+1<tmp)
		{
			tmp=temp[2]+1;
		}	
	}
	
	if(b[i]==inc[b[i-1]]||b[i]==dec[b[i-1]])
	{
		if(min(min(temp[0],temp[1]),temp[2])+1<tmp)
		{
			tmp=min(min(temp[0],temp[1]),temp[2])+1;
		}	
	}

	return tmp;
}

void compute()// function in which all the computations for the problem are done.
{
	ans=size(b[0]);// Initially the answer is the number of digits of the first channel to be pressed.
	
	if(size(inc[b[0]])+1<ans)
	{
		ans=size(inc[b[0]])+1;
	}
	
	if(size(inc[inc[b[0]]])+2<ans)
	{
		ans=size(inc[inc[b[0]]])+2;
	}	
			
	if(chns>1)
	{
		if(b[1]!=b[0])
		{
			temp[0]=ans+min(comp_forw_dist(b[0],inc[b[1]]),comp_back_dist(b[0],inc[b[1]]))+1;
			temp[1]=ans+min(comp_forw_dist(b[0],dec[b[1]]),comp_back_dist(b[0],dec[b[1]]))+1;
			temp[2]=ans+size(b[1]);
			
			if(inc[b[0]]==b[1]||dec[b[0]]==b[1])
			{
				temp[2]=ans+1;
			}
			
			if(ans+size(inc[b[1]])+1<temp[0])
			{
				temp[0]=ans+size(inc[b[1]])+1;
			}
			
			if(ans+size(inc[inc[b[1]]])+2<temp[0])
			{
				temp[0]=ans+size(inc[inc[b[1]]])+2;
			}
			
		}	
		
		else
		{
			temp[0]=ans;
			temp[1]=ans;
			temp[2]=ans;			
		}
		
		if(chns>2)
		{		
			present_back1=inc[b[1]];// stores one of the three possible present back channels(increment of the present channel). 
			present_back2=dec[b[1]];// stores one of the three possible present back channels(decrement of the present channel).
		    present_back3=b[0];/*stores one of the three possible present back channels(the previous channel to be visited according 
								to the ques).*/

			for(i=2;i<chns;i++)
			{
				next_back1=inc[b[i]]; // stores one of the three possible next back channels(increment of the next channel). 
				next_back2=dec[b[i]]; // stores one of the three possible next back channels(increment of the next channel). 
				next_back3=b[i-1]; //stores one of the three possible next back channels(the present channel.
			
				if(b[i]!=b[i-1])
				{

					emp[0]=compute_min_back1()+1;/*emp[0] temporarily stores the number of clicks uptill now assuming the back channel is 
												the increment of the next channel*/	
					emp[1]=compute_min_back2()+1;/*emp[1] temporarily stores the number of clicks uptill now assuming the back channel is 
												the decrement of the next channel*/	
					emp[2]=compute_min_back3();/*emp[2] stores the number of clicks with assuming the back channel is the previous channel
												to be visited.*/
				
					temp[2]=emp[2];
					temp[1]=emp[1];
					temp[0]=emp[0];
				
					present_back1=next_back1;
					present_back2=next_back2;
					present_back3=next_back3;
				}
				
				else
				{
					present_back1=b[i];
					present_back2=b[i];
					present_back3=b[i];					
				}
			}
		}
		
		ans=min(min(temp[0],temp[1]),temp[2]); // ans is the minimum of the three posibilities.
	}
}

void output()// function that ouutputs the answer to the screen.
{
	printf("%d\n",ans);	
}

int main()
{
	input();
	init();
	compute();
	output();	
}

