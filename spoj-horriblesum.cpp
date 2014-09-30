#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<stack>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<sstream>
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
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end());
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define ok if(debug)

ll MOD = int(1e9) + 7;
ll pow(ll num,ll power){if(power==0)return 1;if(power==1)return num;	ll t = pow(num,power/2);return power%2?t*t*num:t*t;}
int check(int);
int binarysearch(int len)//finds last 1 in 11111000
{int lo = 1,hi = len,mid,flag;while(lo<=hi){mid = hi+lo>>1;(flag = check(mid))?lo = mid+1:hi = mid-1;}return mid-1+flag;}
const int N = 1000*100+5;
int debug = 1;
int check(int a){return a;}
inline int inp(){int n=0,s=1,c=getchar();if(c=='-')s=-1;while(c<48)c=getchar();while(c>47)n=(n<<3)+(n<<1)+c-'0',c=getchar();return n*s;}
const int base = 1<<17;
ll seg[4*N],inc[4*N];

void update(ll p,ll l,ll r,ll L,ll R,ll val)
{
//	cout<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<val<<endl;
	if(l == L && r == R)
	{
		inc[p] += val;
		return;
	}
	int mid = (L+R)/2;
	if(r <= mid)
		update(p*2,l,r,L,mid,val);
	else if(l > mid)
		update(p*2+1,l,r,mid+1,R,val);
	else 
	{
		update(p*2,l,mid,L,mid,val);
		update(p*2 + 1,mid+1,r,mid+1,R,val);
	}
	seg[p] = seg[p*2] + inc[2*p]*(ll)(mid-l+1) + seg[2*p+1] + inc[2*p+1]*(ll)(r-mid);
}
ll query(ll p,ll l,ll r,ll L,ll R)
{
	int mid = (L+R)/2;
	if(L == l&& R == r)
	{
		return seg[p] + (ll)inc[p]*(ll)(R - L+1);
	}
	if( r <= mid)
	{
		return (ll)(r-l+1)*(ll)inc[p] + query(p*2,l,r,L,mid);
	}
	if(l > mid)
		return inc[p]*(ll)(r-l+1) + query(p*2+1,l,r,mid+1,R);
	return inc[p]*(ll)(r-l+1) + query(p*2,l,mid,L,mid) + query(p*2+1,mid+1,r,mid+1,R);
}
int main()
{
      ios::sync_with_stdio(false);
      int i,j,n,t,q;      
      cin>>t;
      while(t--)
      {
      	cin>>n;	  
	  	cin>>q;
  	  	while(q--)
	  	{
				int t1;
				cin>>t1;
				if(t1==0)
				{
					int l,r,val;
					cin>>l>>r>>val;
					update(1,l,r,1,base,val);
				}
				else
				{
					int l,r;
					cin>>l>>r;
					cout<<query(1,l,r,1,base)<<endl;
				}
		   }
		   memset(seg,0,sizeof(seg));
		   memset(inc,0,sizeof(seg));
		}
		cin>>i;		
			
      
}

