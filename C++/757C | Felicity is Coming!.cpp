#include <iostream>
#include <map>
#include <vector>
 
using namespace std;
 
#define MX 100005
#define MXM 1000005
 
typedef long long ll;
typedef pair<int,int> pii;
 
struct Hash
{
    ll val1, val2;
 
    Hash() {}
    Hash(ll val) : val1(val), val2(val) {}
    Hash(ll v1, ll v2) : val1(v1), val2(v2) {}
 
    bool operator==(const Hash& rhs) const
    {
        return (val1 == rhs.val1 && val2 == rhs.val2);
    }
 
    bool operator<(const Hash& rhs) const
    {
        return pii(val1,val2) < pii(rhs.val1,rhs.val2);
    }
 
    Hash operator+(const Hash& rhs) const
    {
        return Hash(val1 + rhs.val1, val2 + rhs.val2);
    }
 
    Hash operator-(const Hash& rhs) const
    {
        return Hash(val1 - rhs.val1, val2 - rhs.val2);
    }
 
    Hash operator*(const Hash& rhs) const
    {
        return Hash(val1 * rhs.val1, val2 * rhs.val2);
    }
 
    Hash operator%(const Hash& rhs) const
    {
        return Hash(val1 % rhs.val1, val2 % rhs.val2);
    }
};
 
const Hash MOD(1000000007,1000000009), p(1000003,1000033);
Hash power[MX];
ll fact[MXM];
 
void precalc()
{
    power[0] = 1;
    for(int i=1; i<MX; i++)
    {
        power[i] = (power[i-1] * p) % MOD;
    }
    fact[0] = 1;
    for(int i=1; i<MXM; i++)
    {
        fact[i] = (fact[i-1] * i) % MOD.val1;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    precalc();
 
    int n, m, g, p;
    cin >> n >> m;
 
    vector<Hash> h(m,0);
    map<Hash,int> mp;
 
    for(int i=0; i<n; i++)
    {
        cin >> g;
        for(int j=0; j<g; j++)
        {
            cin >> p;
            p--;
            h[p] = (h[p] + power[i]) % MOD;
        }
    }
 
    for(int i=0; i<m; i++)
        mp[h[i]]++;
 
    ll ans = 1;
    for(map<Hash,int> :: iterator it = mp.begin(); it != mp.end(); it++)
    {
        ans = (ans * fact[it->second]) % MOD.val1;
    }
 
    cout << ans << endl;
 
    return 0;
}