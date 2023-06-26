#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
ll g(ll x, ll n)
{
    ll ret = 0;
    int zeroes = 0;
 
    for(ll mask=1LL; mask<=n; mask<<=1)
    {
        if(n&mask)
        {
            n ^= mask;
            if(!(x&n))
                ret += (1LL << zeroes);
        }
        if(!(x&mask))
            zeroes++;
    }
    return ret;
}
 
ll ways(ll l, ll r)
{
    if(l == r)
        return 0;
    if(l == 0)
        return 2*r-1 + ways(1,r);
 
    ll ret = 0;
    if(l&1)
    {
        ret += 2*( g(l,r)-g(l,l) );
        l++;
    }
    if(r&1)
    {
        ret += 2*( g(r-1,r)-g(r-1,l) );
        r--;
    }
    return ret + 3*ways(l>>1, r>>1);
}
 
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        ll l, r;
        cin >> l >> r;
        cout << ways(l,r+1) << endl;
    }
 
    return 0;
}