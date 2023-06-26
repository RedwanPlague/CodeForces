#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 31;
const ll MOD = 1000000007;
 
#define pb push_back
 
ll bigMod(ll base, ll pow)
{
    if(pow == 0)
        return 1LL;
    ll x = bigMod(base, pow>>1);
    x = (x*x)%MOD;
    if(pow&1)
        x = (base*x)%MOD;
    return x;
}
 
int main()
{
    ios_base::sync_with_stdio(0); // cin.tie(0); cout.tie(0);
 
    ll n, k;
 
    cin>>n>>k;
 
    if(n == 0)
    {
        cout<<0<<endl;
        return 0;
    }
 
    n %= MOD;
 
    ll ans = ( (n * bigMod(2, k+1)) % MOD - bigMod(2, k) + 1 ) % MOD;
 
    if(ans < 0)
        ans += MOD;
 
    cout<<ans<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 