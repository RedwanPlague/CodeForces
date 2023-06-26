// https://codeforces.com/problemset/problem/938/E
 
#include <cstdio>
#include <map>
#include <algorithm>
 
using namespace std;
 
#define MX 10000005
#define MOD 1000000007
#define F first
#define S second
 
typedef long long ll;
 
ll fact[MX];
 
ll bigmod(ll base, ll pw)
{
    base %= MOD;
    pw = (pw+MOD-1)%(MOD-1);
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
 
void init()
{
    fact[0] = 1LL;
    for(int i=1; i<MX; i++)
        fact[i] = i * fact[i-1] % MOD;
}
 
int main()
{
    init();
 
    int n, a;
    scanf("%d", &n);
    map<int,int> mp;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a);
        mp[a]++;
    }
 
    ll sum = 0;
    int less = 0, lasta = 0, lastc = 0;
    for(auto p: mp)
    {
        sum = (sum + lasta*(lastc*bigmod(n-less,-1)%MOD)%MOD)%MOD;
        less += lastc;
        lasta = p.F;
        lastc = p.S;
    }
 
    printf("%lld\n", sum*fact[n]%MOD);
 
    return 0;
}