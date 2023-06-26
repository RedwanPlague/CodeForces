#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 200005
#define MOD 998244353
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
ll bigmod(ll base, ll pw)
{
    base %= MOD;
    pw = (pw + MOD - 1) % (MOD - 1);
    ll ret = 1;
    while(pw)
    {
        if(pw&1)
            ret = (ret*base)%MOD;
        base = (base*base)%MOD;
        pw >>= 1;
    }
    return ret;
}
 
ll fact[MX], inv[MX];
 
void init()
{
    fact[0] = 1;
    inv[0] = bigmod(1,-1);
    for(int i=1; i<MX; i++)
    {
        fact[i] = (fact[i-1]*i) % MOD;
        inv[i] = bigmod(fact[i],-1);
    }
}
 
ll C(ll n, ll r)
{
    if(n < r)
        return 0;
    return (fact[n] * ((inv[r] * inv[n-r])%MOD)) % MOD;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    init();
 
    ll n, k;
    cin >> n >> k;
    vi v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];
    ll a = 0, b = 0;
    for(int i=0; i<n; i++)
    {
        if(v[i] != v[(i+1)%n])
            b++;
        else 
            a++;
    }
 
    ll ans = 0, m, one, two;
    for(int i=0; i<b; i++)
    {
        m = b-i;
        one = (C(b,i)*bigmod(k-2,i))%MOD;
        if(m&1)
        {
            two = bigmod(2,m-1);
        }
        else 
        {
            two = ( ((bigmod(2,m) - C(m,m/2) + MOD)%MOD) * inv[2] ) % MOD; // should be bigmod(2,-1) but fact[2] = 2, so same same :3 
        }
        ans = (ans + (one*two)%MOD)%MOD;
    }
 
    cout << (bigmod(k,a) * ans)%MOD << endl;
 
    return 0;
}