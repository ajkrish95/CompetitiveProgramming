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
#include<iomanip>
#include<cstdlib>
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
 ll pow(ll num,ll power){if(power==0)return 1;if(power==1)return num;	ll t = pow(num,power/2);return power%2?t*t*num:t*t;}
int check(int);
int binarysearch(int len)//finds last 1 in 11111000
{int lo = 1,hi = len,mid,flag;while(lo<=hi){mid = hi+lo>>1;(flag = check(mid))?lo = mid+1:hi = mid-1;}return mid-1+flag;}
const int N = 1000*100+5;
int debug = 1;
int check(int a){return a;}
inline int inp(){int n=0,s=1,c=getchar();if(c=='-')s=-1;while(c<48)c=getchar();while(c>47)n=(n<<3)+(n<<1)+c-'0',c=getchar();return n*s;}
namespace Geometry
{
	double eps = 1e-9;
	struct point
	{
		int x,y;
		point(int a,int b) {x = a;y = b;}
		point(){}
	
	};
	struct line
	{
		point a,b;
		line(){}
		line(point &x,point &y)
		{
			a = x;
			b = y;
		}
		double len()
		{
			return sqrt( (b.x - a.x) * (b.x - a.x) + (b.y - a.y)*(b.y - a.y) );
		}
		double manhattan()			// change to fabs if point is double
		{	
			return abs(b.x-a.x) + abs(b.y - a.y);
		}	
	};
	int dot(point a,point b);
	int cross(point a,point b);
	int operator^(point a,point b);
	int operator *(point a,point b)	;
	point operator -(point a,point b);	
	point operator + (point a,point b);	
	bool operator == (point a,point b);
	bool operator!= (point a,point b);
	int operator *(line a,line b);
	int operator ^ ( line a,line b);
	double dist(point a,point b);	
	bool isPointInLine(point p,line l);	
	bool isPointInSegment(point p,line l);
	double distPointLine(point p,line l);
	double distPointSegment(point p,line l);
	double findArea(vector <point> poly);
	void intersection(int A1,int B1,int C1,int A2,int B2,int C2,double &x,double &y);
	void intersection(line a,line b,bool isSegment,double &x,double &y);
	void convertEquation(line p,int&A,int &B,int &C);
}	
int Geometry:: dot(point a,point b)
{
		return (a.x*b.x + a.y*b.y);
}
int Geometry:: cross(point a,point b)
{
		return a.x*b.y - a.y*b.x;
}
int Geometry:: operator^(point a,point b)
{
		return cross(a,b);
}
int Geometry:: operator *(point a,point b)
{
		return dot(a,b);
}
Geometry:: point Geometry:: operator -(point a,point b)
{
		return point(a.x-b.x,a.y-b.y);
}
Geometry:: point Geometry:: operator + (point a,point b)
{
		return point(a.x + b.x,a.y + b.y);
}
bool Geometry :: operator == ( point a,point b)
{
	return a.x == b.x && a.y == b.y;
}
bool Geometry :: operator != (point a,point b)
{
	return a.x != b.x || a.y != b.y;
}
int Geometry:: operator *(line a,line b)
{
		point t1 = a.a - a.b;
		point t2 = b.a - b.b;
		return t1*t2;
}
int Geometry :: operator ^ ( line a,line b)
{
	 point t1 = a.a - a.b;
	 point t2 = b.a - b.b;
	 return t1^t2;
}
double Geometry:: dist(point a,point b)
{
		return line(a,b).len();
}	
bool Geometry:: isPointInLine(point p,line l)
{
		point dir1 = l.a - l.b;
		point dir2  = l.a - p;
		if(  (dir1^dir2) == 0 )return true;
		return false;	
}	
bool Geometry:: isPointInSegment(point p,line l)
{
		if(!isPointInLine(p,l))return false;
		point a = p - l.a;
		point b = p - l.b;
		return ( a*b <= 0);
}
double Geometry :: distPointLine(point p,line l)
{
		return fabs((p - l.a)^(p - l.b))/l.len(); 
}		
double Geometry :: distPointSegment(point p,line l)
{
		if( (l.b - l.a)*(l.a - p) > 0 )return dist(p,l.a);
		if( (l.a - l.b)*(l.b - p) > 0 )return dist(p,l.b);		
		return distPointLine(p,l);
}	
double Geometry :: findArea(vector < point > poly)
{
	int n = sz(poly);
	int i;
	int area = 0;
	rep(i,n)area += (poly[i]^(poly[(i+1)%n]));
	return fabs(area/2.0);
}
void Geometry :: convertEquation(line p,int &A,int &B,int &C)
{
	point a = p.a;point b = p.b;
	A = b.y - a.y;
	B = a.x - b.x;
	C = A * a.x + B * a.y;
}
void Geometry :: intersection(line a,line b,bool isSegment,double &x,double &y)
{
	int A1,B1,C1,A2,B2,C2;
	convertEquation(a,A1,B1,C1);
	convertEquation(b,A2,B2,C2);
	intersection(A1,B1,C1,A2,B2,C2,x,y);
	if(isSegment)
	{
		int x1 = min(a.a.x,a.b.x);
		int x2 = max(a.a.x,a.b.x);
		int x3 = min(b.a.x,b.b.x);
		int x4 = max(b.a.x,b.b.x);
		int y1 = min(a.b.y,a.a.y),y2 = max(a.b.y,a.a.y);
		int y3 = min(b.a.y,b.b.y),y4 = max(b.a.y,b.b.y);
		if(x >= x1 - eps && x <= x2 + eps && x >= x3 - eps && x <= x4 + eps 
		  && y >= y1 - eps && y <= y2 + eps && y >= y3 - eps && y <= y4 + eps)return;
		 x = inf;y = inf;
	} 
}
void Geometry :: intersection( int A1,int B1,int C1,int A2,int B2,int C2,double &x,double &y)
{
	double det = A1*B2 - A2*B1;
	if(det == 0){ x = y = inf;return;}   // parallel 
	else
	{	
		x = (B2*C1 - B1*C2)/det;
		y = (A1*C2 - A2*C1)/det;
	}			
}
using namespace Geometry;
point O;
bool compare(point a,point b)
{
	if ( (line(a,O) ^ line(b,O)) != 0) return ((line(a,O) ^ line(b,O)) > 0);
	return (line(a,O).len() < line(b,O).len());
}
void print(point p)
{
	cout<<p.x<<" "<<p.y<<"   ";
}
vector < point > convexHull( vector < point > arr )
{
//	int n = sz(arr);
	int i;
	vector<point> a;rep(i,sz(arr))a.pb(arr[i]);
//	sort(all(a),compare); a.erase(unique(all(a)),a.end());
	rep(i,sz(arr))
	{
		if( i == 0 || mp(a[i].y,a[i].x) < mp(O.y,O.x))O = a[i];
	}
	sort(all(a),compare);a.erase(unique(all(a)),a.end());
//	rep(i,sz(a))print(a[i]);
//	cout<<endl;
	stack < point > s;
	s . push(O);
//	if(a[0] != O)cout<<"Something is wrong "<<endl;
	s.push(a[1]);
	int n = sz(a);
	for(i=2;i<n;i++)
	{
	//	s.push(a[i]);
		while(sz(s) >= 3)
		{
			point t1 = a[i];
			point t2 = s.top();
			s.pop();
			point t3 = s.top();
			s.push(t2);
			int val = (t2 - t3) ^ (t1 - t3);
//			print(t1);print(t2);print(t3);
//			cout<<val<<endl;
			if( val <= 0 )s.pop();   // remove equal to 0 if you want all points on the convex hull 
			else break;
		}
		s.push(a[i]);
	}
	vector < point > ret;
	while(!s.empty())
	{
		ret.pb(s.top());
		s.pop();
	}
	reverse(all(ret));
	vector<point>res;point last = ret[0];
	rep(i,sz(ret))				// remove all the points that are not end points in the convex hull if that is not needed return ret
	{
		if( i == 0 || i == sz(ret) -1 ){res.pb(ret[i]);last = ret[i];}
		else if( (last - ret[i]) ^ ( last - ret[i+1])){res.pb(ret[i]);last = ret[i];}
	}
	return res;
}		
map<PII, int > indd;
int main()
{
	int i,j,n,t;
	ios::sync_with_stdio(false);
//	freopen("output.txt","w",stdout);
	t = 1;
	
	while(t--)
	{
		cin>>n;
		vector<point>arr;
		vector<point>convex;
		rep(i,n)
		{
			int a,b;cin>>a>>b;
			arr.pb(point(a,b));
			if(!indd.count(mp(a,b)))indd[mp(a,b)] = i+1;
		}
		if(n == 1) { cout<<"0.00"<<endl<<1<<endl<<endl;indd.clear();arr.clear();continue;}
		convex = convexHull(arr);
		double ans = 0;
		rep(i,sz(convex))ans += line(convex[i],convex[(i+1)%(sz(convex))]).len();
//		cout<<fixed<<setprecision(2)<<ans<<endl;
//		rep(i,sz(convex))cout<<indd[mp(convex[i].x,convex[i].y)]<<" ";
//		indd.clear();arr.clear();
//		cout<<endl<<endl;
		cout<<int(ans);
	}
	cin>>i;	
}	
	


