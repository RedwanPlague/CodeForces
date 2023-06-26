#include <iostream>
using namespace std;
 
typedef long long ll;
 
#define MOD 1000000007
 
ll bigMod(ll base, ll pow)
{
    if(pow == 0)
        return 1LL;
    ll x = bigMod(base, pow>>1);
    x = (x*x)%MOD;
    if(pow&1)
        x = (x*base)%MOD;
    return x;
}
 
int main()
{
    ll n, m, k;
    cin>>n>>m>>k;
    if(k == -1 && (n&1) != (m&1))
        cout<<0<<endl;
    else
        cout<<bigMod(bigMod(2, n-1), m-1)<<endl;
    return 0;
}