#include <iostream>
#include <string>
#include <cstring>
 
using namespace std;
 
#define MX 5005
 
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
 
const Hash MOD(1000000007,1000000009), p(29,31);
Hash pow[MX];
 
void calc_power()
{
    pow[0] = 1;
    for(int i=1; i<MX; i++)
    {
        pow[i] = (pow[i-1] * p) % MOD;
    }
}
 
Hash pre[MX], suf[MX];
 
void calc_hash(const string &s)
{
    pre[0] = 0;
    for(int i=0; i<s.size(); i++)
    {
        pre[i+1] = (pre[i] + pow[i]*(s[i]-'a'+1)) % MOD;
    }
    suf[s.size()] = 0;
    for(int i=s.size()-1, j=0; i>=0; i--, j++)
    {
        suf[i] = (suf[i+1] + pow[j]*(s[i]-'a'+1)) % MOD;
    }
}
 
bool is_palin(int l, int r, int N)
{
    Hash soja = (pre[r+1] - pre[l] + MOD) % MOD;
    soja = (soja * pow[N-l]) % MOD;
    Hash ulta = (suf[l] - suf[r+1] + MOD) % MOD;
    ulta = (ulta * pow[r+1]) % MOD;
    return (soja == ulta);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    string s;
    cin >> s;
    int n = s.size();
 
    calc_power();
    calc_hash(s);
 
    int dp[MX][MX];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<n; i++)
        dp[i][i] = 1;
    for(int len=2; len<=n; len++)
    {
        for(int l=0, r=len-1; r<n; l++, r++)
        {
            dp[l][r] = (dp[l][r-1] + dp[l+1][r] - dp[l+1][r-1] + is_palin(l,r,n));
        }
    }
 
    int q, l, r;
    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        cout << dp[l-1][r-1] << '\n';
    }
 
    return 0;
}