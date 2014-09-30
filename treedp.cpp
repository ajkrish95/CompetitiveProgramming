#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define pb push_back
#define ss second
#define ff first
#define vi vector<int>
#define vl vector<ll>
#define s(n) scanf("%d",&n)
#define ll long long
#define mp make_pair
#define PII pair <int ,int >
#define PLL pair<ll,ll>
#define inf 1000*1000*1000+5
#define v(a,size,value) vi a(size,value)
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define tri pair < int , PII >
#define TRI(a,b,c) mp(a,mp(b,c))
#define xx ff
#define yy ss.ff
#define zz ss.ss
#define in(n) n = inp()
#define vii vector < PII >
#define vll vector< PLL >
#define viii vector < tri >
#define vs vector<string>
#define foreach(v,c) for( typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define fill(a,v)  memset(a,v,sizeof a)
#define printall(a) rep(i,sz(a))cout<<a[i]<<endl;
 ll pow(ll num,ll power){if(power==0)return 1;if(power==1)return num;	ll t = pow(num,power/2);return power%2?t*t*num:t*t;}
int check(int);
int binarysearch(int len)//finds last 1 in 11111000
{int lo = 1,hi = len,mid,flag;while(lo<=hi){mid = hi+lo>>1;(flag = check(mid))?lo = mid+1:hi = mid-1;}return mid-1+flag;}
const int N = 1000*100+5;
int check(int a){return a;}
inline int inp(){int n=0,s=1,c=getchar();if(c=='-')s=-1;while(c<48)c=getchar();while(c>47)n=(n<<3)+(n<<1)+c-'0',c=getchar();return n*s;}
int n;
int level[N],vis[N],pa[N];
vi nei[N];
map < PII , int > wt;
int dp[20][N],parent[20][N];
void dfs(int u)
{
	 int i;
	 vis[u] = 1;
	 rep(i,sz(nei[u]))
	 {
			int t = nei[u][i]; 
			if(vis[t])continue;
			pa[t] = u;
			level[t] = level[u] + 1;
			dfs(t);
			
	 }
}
void precompute() // nodes are from 0 to n-1. take care when modifying
{
		int i,j;
		rep(i,n)
		{
			parent[0][i] = pa[i];
			dp[0][i] = wt[mp(i,pa[i])];
		}
		f(j,1,inf)
		{
			if((1<<j) > n )break;
			rep(i,n)
			{
				int t = (1<<j);
				if(level[i] <= t) continue;
				parent[j][i] = parent[j-1][parent[j-1][i]];
				dp[j][i] = dp[j-1][i] + dp[j-1][parent[j-1][i]];
			}
		}
}		
int lca(int a,int b)
{
		if(level[a] > level[b])swap(a,b);   // level of a is less than that of b
		int log = 19;	
		for(log=19;log>=0;log--)
		{
			if(level[b] >= level[a] + (1<<log) )
			{
				b = parent[log][b];
			}	
		}
		// level of b will be equal to that of a
	//	cout<<"Entering at "<< a << " "<<b<<" "<<level[a]<<" "<<level[b]<<endl;
		if(a==b)return a;
		for(log = 19;log >= 0;log--)
		{
			if(level[a] <= (1<<log))continue;
			if(parent[log][a] != parent[log][b])
			{
				a = parent[log][a];
				b = parent[log][b];
			}
		}
		if(a!=b){ a = pa[a];}
		return a;
}
int dist(int a,int b)
{
		if(level[a] > level[b])swap(a,b); 
		if(a==b)return 0;
		int log;int ret = 0;
		for(log = 19;log>=0;log--)
		{
			if( (1<<log) + level[a] <= level[b])
			{
				ret += dp[log][b];
				b = parent[log][b];
			}
		}
		return ret;
}
int distanc(int a,int b)
{
		int t = lca(a,b);
		return dist(a,t) + dist(t,b);
}
				
int main()
{
      ios::sync_with_stdio(false);
      int i,j,t,m;
      cin>>n;
      rep(i,n-1)
      {
			int a,b,c;
			cin>>a>>b>>c;
			nei[a].pb(b);
			nei[b].pb(a);
			wt[mp(a,b)] = wt[mp(b,a)] = c;
	  }
	  level[0] = 1;pa[0] = -1;
	  dfs(0);
	  precompute();
	  cin>>m;
	  rep(i,m)
	  {
			int a,b;
			cin>>a>>b;
		//	cout<<lca(a,b)<<endl;
			cout<<distanc(a,b)<<endl;
	  }
	  cin>>i;
}

