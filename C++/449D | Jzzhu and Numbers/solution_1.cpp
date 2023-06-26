#include <iostream>
#include <vector>
 
#define MX 20
#define MOD 1000000007
 
using namespace std;
 
typedef long long ll;
 
const int limit = (1<<MX);
 
ll bigMod(ll base, ll pw)
{
    if(!pw)
        return 1LL;
    ll x = bigMod(base,pw>>1);
    x = (x*x)%MOD;
    if(pw&1)
        x = (base*x)%MOD;
    return x;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> dp(limit,0);
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        dp[a[i]] += 1;
    }
    for(int i=0; i<MX; i++)
    {
        for(int mask=limit-1; mask>=0; mask--)
        {
            if(!(mask&(1<<i)))
               dp[mask] += dp[mask|(1<<i)];
        }
    }
 
    ll ways = 0;
    for(int mask=0; mask<limit; mask++)
    {
        int bitcnt = 0;
        for(int i=0; (1<<i)<=mask; i++)
            if(mask&(1<<i))
                bitcnt++;
        if(bitcnt&1)
            ways = (ways - bigMod(2,dp[mask]) + MOD)%MOD;
        else
            ways = (ways + bigMod(2,dp[mask]))%MOD;
    }
 
    cout << ways << endl;
 
    return 0;
}