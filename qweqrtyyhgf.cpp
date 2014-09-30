#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>

#define EPS 1e-10
using namespace std;
double x[2502][2502];
int vis[2502][2502];
int N,M,tc=1;

double calc(int koyta,int jani){
	//cout<<x[koyta][jani]<<endl;
	if(koyta<0 || jani<0)return 0;
	if((2*jani)>=koyta) return (koyta/2.);
	if((vis[koyta][jani])==tc) return x[koyta][jani];
	vis[koyta][jani]=tc;
	//cout<<koyta<<" k,j "<<jani<<endl;

	double res=0;
	double tp;double tp2;
	double td;
	{
		tp=(double) jani*1.0f/(koyta-jani);
		if(fabs(tp)>EPS) res+= tp*(calc(koyta-2,jani-1)+1);
		tp2=(1-tp)*jani*1.0f/(koyta-jani-1);
		if(fabs(tp2)>EPS) res+= tp2*(calc(koyta-2,jani)+2);
	}
	tp=tp+tp2;tp=1-tp;
	if(fabs(tp)>EPS){
		td=(calc(koyta-2,jani)+1)/(koyta-jani-jani-1);
		td+=(calc(koyta,jani+2)+1)*(koyta-jani-jani-2)/(koyta-jani-jani-1);
		res+=tp*td;
	}
	x[koyta][jani]=res;
	return res;
}


int main(){

	//freopen("standUp.in","rt",stdin);
	//freopen("out2.txt","wt",stdout);


	while(cin>>N>>M){
		//memset(x,0,sizeof(x));
		int tot=N*M;
		//x[2][0]=1;
		//tc++;


		printf("%0.4f\n", calc(tot,0));


	}
	return 0;
}
