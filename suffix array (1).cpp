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
#define vv vector<int>
#define s(n) scanf("%d",&n)
#define ll long long
#define mp make_pair
#define PII pair <int ,int >
#define inf 1000*1000*1000+5
#define v(a,size,value) vv a(size,value)
#define sz(a) a.size()
string s;
const int N = 1000*100+5;
int suffix[18][N],S;  

int comparestrings(int start) 
{
		int len = S - start;
		int power;
//		cout<<"Entering at "<<start<<endl;
		int lo = 1,hi = len+1,mid,flag;
		while(hi>lo)
		{
	//		cout<<hi<<" "<<lo<<endl;
			mid = (hi+lo)>>1;
				for(power = 0; (1<<power) <= mid;power++);
				power--;
			//cout<<power<<endl;
			int temp1 = suffix[power][start],temp2 = suffix[power][start + mid - (1<<power)];
			int temp3 = suffix[power][0],temp4 = suffix[power][mid - (1<<power)];
			flag = (temp1==temp3&&temp2==temp4);
		//	cout<<"  "<<flag<<endl;
			if(mid==lo)return lo - 1 + flag;
			if(flag==1)lo = mid;
			else hi = mid ;
	   }
	   return lo - 1 + flag;
}
		
int main()
{
      int i,j;
      int t;
      cin>>t;
      vv ans;
      while(t--)
      {
	  cin>>s;
	   S = s.size();
	  rep(i,S)
	  		suffix[0][i] = s[i] - 'a'+1;
	  int log;		
      for(log = 1;(1<<log)<S;log++);
      f(j,1,log+1)
	  {
			vector < PII >temp;
			for(i=0;i + (1<<(j)) <= S;i++)
			temp.pb(mp(suffix[j-1][i],suffix[j-1][i + (1<<(j-1))])) ;
			sort(temp.begin(),temp.end());
			int rank = 1;
			map< PII ,int > mymap;
			rep(i,sz(temp)) 
						if(mymap[temp[i]]==0)mymap[temp[i]] = rank++;
			for(i=0;i+(1<<(j)) <= S;i++)
			suffix[j][i] = mymap[mp(suffix[j-1][i],suffix[j-1][i + (1<<(j-1))])];
	}
	
    int sum = 0;
    rep(i,S)sum +=comparestrings(i);
    ans.pb(sum);
    rep(i,18)rep(j,N)suffix[i][j] =0 ;
     }
     rep(i,sz(ans))cout<<ans[i]<<endl;
     cin>>i;
}
