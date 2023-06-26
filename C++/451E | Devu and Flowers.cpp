#include <iostream>
#include <vector>
 
#define MOD 1000000007
 
using namespace std;
 
typedef long long ll;
 
ll hor;
 
ll bigMod(ll base, ll pw)
{
    if(!pw)
        return 1LL;
    ll x = bigMod(base,pw>>1);
    x = (x*x)%MOD;
    if(pw&1)
        x = (x*base)%MOD;
    return x;
}
 
ll comb(ll n, ll r)
{
    if(n == 0 && r == 0)
        return 1LL;
    ll ret = n%MOD;
    for(ll i=n-1; i>(n-r); i--)
    {
        ret = (ret*(i%MOD))%MOD;
    }
    return (ret*hor)%MOD;
}
 
int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(0); cout.tie(0);
 
 int n;
 ll s;
 cin >> n >> s;
 vector<ll> f(n);
 for(int i=0; i<n; i++)
    {
        cin >> f[i];
    }
    hor = 1;
    for(int i=1; i<n; i++)
    {
        hor = (hor*i)%MOD;
    }
    hor = bigMod(hor,MOD-2)%MOD;
    int limit = (1<<n);
    ll ways = 0;
    for(int mask=0; mask<limit; mask++)
    {
        int setbit = 0;
        ll sum = 0;
        for(int i=0; i<n; i++)
        {
            if(mask&(1<<i))
            {
                sum += f[i]+1;
                setbit++;
            }
        }
        if(sum <= s)
        {
            if(setbit&1)
                ways = (ways - comb(n+(s-sum)-1,n-1) + MOD)%MOD;
            else
                ways = (ways + comb(n+(s-sum)-1,n-1))%MOD;
        }
        //cout << ways << endl;
    }
 
    cout << ways << endl;
 
 return 0;
}