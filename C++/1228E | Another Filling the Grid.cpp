#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 255
#define MOD 1'000'000'007
#define set(N,pos) (N = (1LL<<(pos)))
#define clear(N,pos) (N = (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
 
ll bigmod(ll base, ll pw)
{
    ll ret = 1, mul = base;
    while(pw)
    {
        if(pw&1)
            ret = (ret*mul)%MOD;
        mul = (mul*mul)%MOD;
        pw >>= 1;
    }
    return ret;
}
 
ll dp[MX][MX];
int vis[MX][MX], mark;
ll n, k;
ll comb[MX][MX];
 
void binom()
{
    for(int i=0; i<MX; i++)
        comb[i][0] = 1;
    for(int i=1; i<MX; i++)
        for(int j=1; j<MX; j++)
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%MOD;
}
 
ll ways(int r, int c)
{
    ll &dpcur = dp[r][c];
    int &viscur = vis[r][c];
    if(viscur == mark)
        return dpcur;
 
    viscur = mark;
 
    if(c == 0)
        return (dpcur = bigmod( (bigmod(k,n) - bigmod(k-1,n) + MOD)%MOD , r)); // ( k^n - (k-1)^n )^r
    if(r == 1)
        return (dpcur = bigmod(k,n-c)); // k^(n-c)
 
    ll a = (bigmod(k,n-c) - bigmod(k-1,n-c) + MOD)%MOD;
    a = (a * bigmod(k-1,c))%MOD;
    a = (a * ways(r-1,c))%MOD;
 
    ll b = 0, d;
    for(int i=1; i<=c; i++)
    {
        d = (bigmod(k-1,c-i)*ways(r-1,c-i))%MOD;
        d = (comb[c][i]*d)%MOD;
        b = (b + d)%MOD;
    }
    b = (b*bigmod(k,n-c))%MOD;
 
    return (dpcur = (a+b)%MOD);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    binom();
    while(cin >> n >> k)
    {
        mark++;
        cout << ways(n,n) << endl;
    }
 
    return 0;
}