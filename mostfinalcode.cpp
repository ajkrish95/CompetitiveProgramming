#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include <time.h> 
#include <algorithm>  

using namespace std;

char square[10][10];

char boom(char a){
	if(a=='X'||a=='O')
	return a;
	else
	return ' ';
}
char boom1(char a){
	if(a=='X'||a=='O')
	return a;
	else
	return '.';
}

char y[5][5][5][5];

void convert()
{
	int i,j,k,q,w,e,r;
	for(i=1;i<4;i++)
	{
	for(j=1;j<4;j++)
	{
	cout<<boom1(square[i][j]);
	q=(i-1)%3;
	w=i/3;
	e=(j-1)%3;
	r=j/3;
	y[w][q][r][e]=boom1(square[i][j]);
}
}
	cout<<"\n";
	for(i=1;i<4;i++)
	{
	for(j=4;j<7;j++)
	{
	cout<<boom1(square[i][j]);
	q=(i-1)%3;
	w=i/3;
	e=(j-1)%3;
	r=j/3;
	y[w][q][r][e]=boom1(square[i][j]);
		}
}
	cout<<"\n";
	for(i=1;i<4;i++)
	{
	for(j=7;j<10;j++)
	{
	cout<<boom1(square[i][j]);
	q=(i-1)%3;
	w=i/3;
	e=(j-1)%3;
	r=j/3;
	y[w][q][r][e]=boom1(square[i][j]);
	}

}
	cout<<"\n";
		for(i=4;i<7;i++)
	{
	for(j=1;j<4;j++)
	{
	cout<<boom1(square[i][j]);
	q=(i-1)%3;
	w=i/3;
	e=(j-1)%3;
	r=j/3;
	y[w][q][r][e]=boom1(square[i][j]);
	}
}
	cout<<"\n";
	for(i=4;i<7;i++)
	{
	for(j=4;j<7;j++)
	{
	cout<<boom1(square[i][j]);
	q=(i-1)%3;
	w=i/3;
	e=(j-1)%3;
	r=j/3;
	y[w][q][r][e]=boom1(square[i][j]);
	}
}
	cout<<"\n";
	for(i=4;i<7;i++)
	{
	for(j=7;j<10;j++)
	{
	cout<<boom1(square[i][j]);
	q=(i-1)%3;
	w=i/3;
	e=(j-1)%3;
	r=j/3;
	y[w][q][r][e]=boom1(square[i][j]);
	}

}
	cout<<"\n";
		for(i=7;i<10;i++)
	{
	for(j=1;j<4;j++)
	{
	cout<<boom1(square[i][j]);
	q=(i-1)%3;
	w=i/3;
	e=(j-1)%3;
	r=j/3;
	y[w][q][r][e]=boom1(square[i][j]);
	}
}
	cout<<"\n";
	for(i=7;i<10;i++)
	{
	for(j=4;j<7;j++)
	{
	cout<<boom1(square[i][j]);
	q=(i-1)%3;
	w=i/3;
	e=(j-1)%3;
	r=j/3;
	y[w][q][r][e]=boom1(square[i][j]);
	}
}
	cout<<"\n";
	for(i=7;i<10;i++)
	{
	for(j=7;j<10;j++)
	{
	cout<<boom1(square[i][j]);
	q=(i-1)%3;
	w=i/3;
	e=(j-1)%3;
	r=j/3;
	y[w][q][r][e]=boom1(square[i][j]);
	}
}
	cout<<"\n";

}

bool myfunction (int i,int j) { 
	return (i<j); 
}


/*
 * Board is a structure which stores information about the board.
 * out store whether a particular grid has been won by someone.
 * b stores whether a particular coordinate is occupied by someone.
 * filled stores whether a particular grid is complete.
 * 
 */
struct board{
	int out[10];
	int b[10][10];
	int filled[10];
	vector<int> proper[10];
	vector<int> pell;
} d;

/*
 * The function boom converts the board into the required format.
 */

/*
 * The function print prints the board in the required format.
 */
//int print(board d);

/*
 * The function possible checks if a particular move is possible or not.
 */
int possible(int i,int choice,board d){
	if( (d.out[choice]!=choice) || (d.filled[choice]==1) )
	return -1;
	
	else if( d.b[choice][i]!=i )
	return 0;
	
	return 1;
	
}

/*
 * The function search checks if a particular element is there in the vector.
 */
int linear_search( vector<int> d, int a ){
	int i;
	for(i=0;i<d.size();i++){
		if(d.at(i)==a){
			return i;
		}
	}
	return -1;
}

int isfilled(board d);



/*
 * The function checkwin checks if after a certain stage anyone has won the game.
 */
int checkwin(int *square);

int play(int n,board s,int player,int choose){
	int iter,p,win,i,countwin=0;
	char mark;
	board d;
	int choice[2],original;
	choice[0]=choose;
	original=player;
	for(iter=1;iter<=n;iter++)
	{
		d=s;
		choice[0]=choose;
		do
		{
			player=(player%2)?1:2;
			p=rand()%9+1;
				//wanted=bot(d,choice[0],player);
				if(possible(p,choice[0],d)!=-1)
				{	
					p=rand()%(d.proper[choice[0]].size()-1)+1;
					choice[1]=d.proper[choice[0]].at(p);	
				}
				else
				{
					p=rand()%(d.pell.size()-1)+1;
					choice[0]=d.pell.at(p);
					p=rand()%(d.proper[choice[0]].size()-1)+1;
					choice[1]=d.proper[choice[0]].at(p);
				}
			mark=(player == 1) ? 'X' : 'O';
			d.b[choice[0]][choice[1]]=(mark=='X') ? -1 : 0;
			int m=linear_search (d.proper[choice[0]], choice[1]);
			d.proper[choice[0]].erase(d.proper[choice[0]].begin()+m);
			d.out[choice[0]]=checkwin(d.b[choice [0]]);
			if(d.out[choice[0]]==-1)
			d.out[choice[0]]=choice[0];
			else if(d.out[choice[0]]==0)
			{
				d.filled[choice[0]]=1;
				d.out[choice[0]]=choice[0];
				int n=linear_search (d.pell, choice[0]);
				d.pell.erase(d.pell.begin()+n);
			}
			else
			{
				d.out[choice[0]]=(player==1)? -1:0;
				d.filled[choice[0]]=1;
				win=checkwin(d.out);
				int n=linear_search (d.pell, choice[0]);
				d.pell.erase(d.pell.begin()+n);
				if(win==1)
				{
					//printf("Player %d wins",player);
					break;
				}	
				if(win==0)
				{
				//printf("DRAW!!!!!!!!!");
				break;
				}		
			}
			if(isfilled(d))
			{
				//printf("Draw!!!!!!\n");
				break;
			}
		choice[0]=choice[1];	
		i=-1;
		player++;	
	}
	while(i==-1);
	if(player==original)
	countwin++;
	}
	return countwin;
}

int bot(board s,int choice,int player)
{
	int k=0,max=-1,l=0,pos=0,i=1,j,ch=0,m=0,max1=-1,ch1=0,pos1=0,e[100][3];
	board d;
	d=s;
	ch=choice;
	//cout<<d.out[choice]<<" "<<choice<<"\n";
	if(possible(i,choice,d)!=-1)
	{
		ch=choice;
		for(i=2;i<=9;i+=2)
		{
			d=s;
			if(possible(i,choice,d))
			{
				d.b[choice][i]=(player == 1) ? -1 : 0;
				if(checkwin(d.b[choice])==1)//change
				{
					return choice*10+i;
				}
			}
		}
		for(i=1;i<=9;i+=2)
		{
			if(i!=5)
			{
			d=s;
			if(possible(i,choice,d))
			{
				d.b[choice][i]=(player == 1) ? -1 : 0;
				if(checkwin(d.b[choice])==1)//change
				{
					return choice*10+i;
				}
			}
		}
		}
		i=5;
		d=s;
		if(possible(i,choice,d))
		{
			d.b[choice][i]=(player == 1) ? -1 : 0;
			if(checkwin(d.b[choice])==1)//change
			{
				return choice*10+i;
			}
		}		
		for(i=1;i<=9;i++)
		{
			d=s;
			if(possible(i,choice,d))
			{
				d.b[choice][i]=(player == 1) ? -1 : 0;
				{
				int m=linear_search (d.proper[choice], i);
				d.proper[choice].erase(d.proper[choice].begin()+m);
				}
				if(checkwin(d.b[i])==-1)
				{
					if(i==choice)
					return 10*choice+i;
					l=play(1000,d,player,i);
					if(i==5)//change
					l=l-400;//change
					if(i==2||i==4||i==6||i==8)//change
					l=l+30;//change
					if(max<l)
					{
						max=l;
						pos=i;
					}
				}
				else
				{
					m=play(1000,d,player,j);
					if(max1<m)
					{
						max1=m;
						pos1=j;
						ch1=i;
					}
				}
			}
		}
	}
	else
	{
		for(i=1;i<=9;i++)
			for(j=1;j<=9;j++)
			{
				d=s;
				if(possible(j,i,d)==1)
				{	
					d.b[i][j]=(player == 1) ? -1 : 0;
					if(checkwin(d.b[i])==1)
					{
						//e[k][0]=i;
						//e[k][1]=j;
						//++k;
						d.out[i]=(player == 1) ? -1 : 0;
						if(checkwin(d.out)==1)
						return i*10+j;
					}
				}
			}
			i=5;
			for(j=1;j<=9;j++)
			{
				d=s;
				if(possible(j,i,d)==1)
				{	
					d.b[i][j]=(player == 1) ? -1 : 0;
					if(checkwin(d.b[i])==1)
					{
						//e[k][0]=i;
						//e[k][1]=j;
						//++k;
						return i*10+j;
					}
				}
			}
		i=5;
		for(j=1;j<=9;j++)
			{
				d=s;
				if(possible(j,i,d)==1)
				{	
					d.b[i][j]=(player == 1) ? -1 : 0;
					if(checkwin(d.b[i])==1)
					{
						//e[k][0]=i;
						//e[k][1]=j;
						//++k;
						return i*10+j;
					}
				}
			}		
		for(i=1;i<=9;i+=2)
			for(j=1;j<=9;j++)
			{
				if(i!=5)
				{
				d=s;
				if(possible(j,i,d)==1)
				{	
					d.b[i][j]=(player == 1) ? -1 : 0;
					if(checkwin(d.b[i])==1)
					{
						//e[k][0]=i;
						//e[k][1]=j;
						//++k;
						return i*10+j;
					}
				}
			}
			}
		for(i=2;i<=9;i+=2)
			for(j=1;j<=9;j++)
			{
				d=s;
				if(possible(j,i,d)==1)
				{	
					d.b[i][j]=(player == 1) ? -1 : 0;
					if(checkwin(d.b[i])==1)
					{
						//e[k][0]=i;
						//e[k][1]=j;
						//++k;
						return i*10+j;
					}
				}
			}
		for(i=1;i<=9;i++)
			for(j=1;j<=9;j++)
			{
				d=s;
				if(possible(j,i,d)==1)
				{
					d.b[i][j]=(player == 1) ? -1 : 0;
					{
						int m=linear_search (d.proper[i], j);
						d.proper[i].erase(d.proper[i].begin()+m);
					}
					if(checkwin(d.b[j])==-1)
					{
						l=play(1000,d,player,j);
						if(j==5)//change
						l=l-400;//change
						if(j==2||j==4||j==6||j==8)//change
						l=l+30;//change
						if(max<l)
						{
							max=l;
							pos=j;
							ch=i;
						}
					}
					else
					{
						m=play(1000,d,player,j);
						if(j==5)//change
						l=l-200;//change
						if(j==2||j==4||j==6||j==8)//change
						l=l+35;//change
						if(max1<m)
						{
							max1=m;
							pos1=j;
							ch1=i;
						}
					}
				}
			}
	}
	cout <<"max="<<max<<"\n";
	if(max==-1)
	return ch1*10+pos1;
	return ch*10+pos;
}
//int checkwin(char *square);

/*********************************************

	FUNCTION TO RETURN GAME STATUS
	1 FOR GAME IS OVER WITH RESULT
	-1 FOR GAME IS IN PROGRESS
	O GAME IS OVER AND NO RESULT
	2 FOR GAME IS IN PROGRESS
**********************************************/
int isfilled(board d)
{
	for(int i=1;i<10;i++)
	if(d.filled[i]==0)
	return 0;
	return 1;
}
int checkwin (int* square)
{
	if (square[1] == square[2] && square[2] == square[3] )

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != 1 && square[2] != 2 && square[3] != 3 
                    && square[4] != 4 && square[5] != 5 && square[6] != 6 
                  && square[7] != 7 && square[8] != 8 && square[9] != 9)

		return 0;
	/*for(i=1;i<=9;i++)
	{
		if(square[i]==i)
		break;
	}
	if(i==10)
	return 2;
	*/
	else
	return -1;
}
void board()
{
	int t=3,i,p;
	system("cls");
	for(p=0;p < t;p++)
	{
	//cout << "\n\n\tTic Tac Toe\n\n";

	//cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	//cout << endl;
	cout<<endl;
	for(i=1;i<3;i++)
	cout << "     |     |     "<<"|" ;
	cout << "     |     |     "<<" " ;
	cout<<endl;
	for(i=1;i<3;i++)
	cout << "  " << boom(square[3*p+i][1]) << "  |  " << boom(square[3*p+i][2]) << "  |  " << boom(square[3*p+i][3]) << "  |";
	cout << "  " << boom(square[3*p+i][1]) << "  |  " << boom(square[3*p+i][2]) << "  |  " << boom(square[3*p+i][3]) << "   ";
	cout<<endl;
	for(i=1;i<3;i++)
	cout << "_____|_____|_____" <<"|" ;
	cout << "_____|_____|_____" <<" " ;
	cout<<endl;
	for(i=1;i<3;i++)
	cout << "     |     |     " <<"|";
	cout << "     |     |     " <<" ";
	cout<<endl;
	for(i=1;i<3;i++)
	cout << "  " << boom(square[3*p+i][4]) << "  |  " << boom(square[3*p+i][5]) << "  |  " << boom(square[3*p+i][6]) << "  |";
	cout << "  " << boom(square[3*p+i][4]) << "  |  " << boom(square[3*p+i][5]) << "  |  " << boom(square[3*p+i][6]) << "   ";
	cout<<endl;
	for(i=1;i<3;i++)
	cout << "_____|_____|_____" <<"|";
	cout << "_____|_____|_____" <<" ";
	cout<<endl;
	for(i=1;i<3;i++)
	cout << "     |     |     " <<"|";
	cout << "     |     |     " <<" ";
	cout<<endl;
	for(i=1;i<3;i++)
	cout << "  " << boom(square[3*p+i][7]) << "  |  " << boom(square[3*p+i][8]) << "  |  " << boom(square[3*p+i][9]) <<"  |";
	cout << "  " << boom(square[3*p+i][7]) << "  |  " << boom(square[3*p+i][8]) << "  |  " << boom(square[3*p+i][9]) <<"   ";
	cout<<endl;
	for(i=1;i<3;i++)
	cout << "     |     |     " <<"|"; 
	cout << "     |     |     " <<" ";
	cout<<endl;
	if(p!=2)
	{
	for(i=1;i<3;i++)
	cout << "_________________" <<"|"; 
	cout << "_________________" <<" ";
	
	cout<<endl;
	for(i=1;i<3;i++)
	cout << "                 " <<"|"; 
}

}
convert();
}
int main(){
	
	int win=0,player = 1,i,choice[2],j;
	
	/*
 	 * Initialising the arrays and vectors of the structure board..
 	 */
	for(i=0;i<10;i++){
		d.out[i]=i;
		d.filled[i]=0;
		for(j=0;j<10;j++){
			square[i][j]= '0'+j;
			d.b[i][j]=j;
		}
	}
	
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			d.proper[i].push_back(j);
		}
	}
	
	for(i=0;i<10;i++){
		d.pell.push_back(i);
	}
	
	//cout<<d.pell.size()<<"\n";
	char mark;
	int wanted,p;
	board();
	player =1;
	int overall;
	printf("\nChoose 1 or 2 : ");
	scanf("%d",&overall);
	printf("\n");
	while(overall!=1&&overall!=2)
	{
		printf("Wrong input.\n\n");
		printf("\nChoose 1 or 2 : ");
		scanf("%d",&overall);
		printf("\n");	
	}
		
	if(overall==2){
		d.b[5][5]=-1;
		square[5][5]='X';
		board();
		player=2;
		choice[0]=5;
		choice[1]=5;
		int m;
		m=linear_search (d.proper[choice[0]], choice[1]);
		d.proper[choice[0]].erase(d.proper[choice[0]].begin()+m);
	/*
		for(i=0;i<d.proper[choice[0]].size();i++)
		cout<<d.proper[choice[0]].at(i)<<" ";
		cout<<"\n";
		cout<<d.proper[choice[0]].size()<<"\n";
	*/
	}
	
	else{
		if(overall==1){
			printf("Player %d: Enter two coordinates: ",player);
			//cout << "Player " << player << ": Enter two coordinates:  ";
			scanf("%d%d",&choice[0],&choice[1]);
			//cin>>choice[0]>>choice[1];
			d.b[choice[0]][choice[1]]=-1;
			square[choice[0]][choice[1]]='X';
			player=2;
			board();
			int m=linear_search (d.proper[choice[0]], choice[1]);
			d.proper[choice[0]].erase(d.proper[choice[0]].begin()+m);
			choice[0]=choice[1];
		}

	}
	
	do{
		printf("\n");
		//cout<<endl;
		player=(player%2)?1:2;
		if(overall==player){
			if(d.out[choice[0]]==choice[0]){
				printf("Player %d: Enter a number in box %d: ",player,choice[0]);
				//cout << "Player " << player << ": Enter a number in box "<<choice[0]<<": ";
				scanf("%d",&choice[1]);
				//cin >>choice[1];
				printf("\n");
				//cout<<"\n";
				while(d.b[choice[0]][choice[1]]!=choice[1]){
					//cout<<"Invalid input.\n\n";
	                printf("Invalid input.\n\n");
					printf("Player %d: Enter a number in box %d: ",player,choice[0]);
			        scanf("%d",&choice[1]);
					printf("\n");
			        //cout << "Player " << player << ": Enter a number in box "<<choice[0]<<": ";
					//cin >>choice[1];
					//cout<<"\n";
				}
			}
			else{
				cout << "Player " << player << ": Enter two coordinates: ";
				cin>>choice[0]>>choice[1];
				while((d.b[choice[0]][choice[1]]!=choice[1])||(d.out[choice[0]]!=choice[0])){
					cout<<"Invalid input.\n\n";
					cout << "Player " << player << ": Enter two coordinates: ";
					cin>>choice[0]>>choice[1];
					cout<<"\n";
				}			
			}
		}
		
		else{
			wanted=bot(d,choice[0],player);
			/*if(possible(p,choice[0],d)!=-1)
			{	
				p=rand()%(d.proper[choice[0]].size()-1)+1;
				cout<<d.proper[choice[0]].size()<<"\n"<<p<<"\n";
				choice[1]=d.proper[choice[0]].at(p);	
			}
			else
			{
				p=rand()%(d.pell.size()-1)+1;
				choice[0]=d.pell.at(p);
				p=rand()%(d.proper[choice[0]].size()-1)+1;
				choice[1]=d.proper[choice[0]].at(p);
			}*/
			choice[0]=wanted/10;
			//cout<<choice[0]<<"\n";
			choice[1]=wanted%10;
		}
		
		mark=(player == 1) ? 'X' : 'O';
		square[choice[0]][choice[1]]=mark;
		//cout<<"HERE\n";
		d.b[choice[0]][choice[1]]=(mark=='X') ? -1 : 0;
		int m=linear_search (d.proper[choice[0]], choice[1]);
		d.proper[choice[0]].erase(d.proper[choice[0]].begin()+m);
		d.out[choice[0]]=checkwin(d.b[choice [0]]);
		
		if(d.out[choice[0]]==-1)
		d.out[choice[0]]=choice[0];
		else if(d.out[choice[0]]==0)
		{
			d.filled[choice[0]]=1;
			d.out[choice[0]]=choice[0];
			int n=linear_search (d.pell, choice[0]);
			d.pell.erase(d.pell.begin()+n);
		}
		else
		{
			d.out[choice[0]]=(player==1)? -1:0;
			d.filled[choice[0]]=1;
			win=checkwin(d.out);
			int n=linear_search (d.pell, choice[0]);
			d.pell.erase(d.pell.begin()+n);
			if(win==1)
			{
				board();
				printf("Player %d wins!!!!!!! \nCongraulations player %d. :D",player,player);
				return 0;
				break;
			}	
			if(win==0)
			{
				board();
				printf("DRAW!!!!!!!!!");
				return 0;
				break;
			}		
		}
		if(isfilled(d))
		{
			board();
			printf("Draw!!!!!!\n");
			break;
		}
	choice[0]=choice[1];	
	i=-1;
	player++;	
	//system("cls");
	board();
	/*
	for(i=0;i<d.pell.size();i++)
	{
	cout<<"\n";
		for(j=0;j<d.proper[d.pell[i]].size();j++)
			cout<<d.proper[d.pell[i]].at(j)<<" ";
	}*/
	i=-1;
	}
	while(i==-1);
//	board();
	
	cin.ignore();
	cin.get();
	return 0;
}
/*
int checkwin(int* square)
{
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != 1 && square[2] != 2 && square[3] != 3 
                    && square[4] != 4 && square[5] != 5 && square[6] != 6 
                  && square[7] != 7 && square[8] != 8 && square[9] != 9)

		return 0;
	for(i=1;i<=9;i++)
	{
		if(square[i]==i)
		break;
	}
	if(i==10)
	return 2;
	else
		return -1;
}

*/
/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/
/*******************************************************************
				END OF PROJECT
********************************************************************/
