void mul(ll a[K][K],ll b[K][K],ll res[K][K])
{
        int i,j,k1;
        rep(i,K)rep(j,K)res[i][j] = 0;
        rep(i,K)rep(j,K)rep(k1,K) res[i][j] = (res[i][j] + a[i][k1]*b[k1][j])%MOD;
}
 
void power(ll a[K][K],ll n)
{
//      cout<<"power "<<n<<endl;
        if(n<=1)return;int i,j;
        ll b[K][K],c[K][K],d[K][K];rep(i,K)rep(j,K)d[i][j] = a[i][j];
        power(d,n/2);
        mul(d,d,b);
        if(n%2)
        {
               
                mul(b,a,c);
                rep(i,K)rep(j,K)a[i][j] = c[i][j];
        }
        else
        {
                rep(i,K)rep(j,K)a[i][j] = b[i][j];
        }      
}


