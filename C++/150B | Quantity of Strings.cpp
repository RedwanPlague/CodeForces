#include <iostream>
using namespace std;
 
typedef long long ll;
 
const int MOD = 1000000007;
 
ll bigMod(ll base, ll pw)
{
    if(!pw)
        return 1LL;
    ll x = bigMod(base,pw>>1);
    x = (x*x) % MOD;
    if(pw&1)
        x = (x*base) % MOD;
    return x;
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    if(k == 1 || k > n)
    {
        cout << bigMod(m,n) << endl;
    }
    else if(k == n)
    {
        cout << bigMod(m,(n+1)/2) << endl;
    }
    else if(k & 1)
    {
        cout << (m*m) % MOD << endl;
    }
    else 
    {
        cout << m % MOD << endl;
    }
 
 return 0;
}