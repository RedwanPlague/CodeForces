#include <iostream>
#include <string>
#include <set>
 
using namespace std;
 
#define MX 600005
 
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
 
    Hash operator*(ll num) const
    {
        return Hash(val1 * num, val2 * num);
    }
 
    Hash operator%(const Hash& rhs) const
    {
        return Hash(val1 % rhs.val1, val2 % rhs.val2);
    }
};
 
const Hash MOD(1000000007,1000000009), p(5,7);
Hash power[MX];
 
void calc_power()
{
    power[0] = 1;
    for(int i=1; i<MX; i++)
    {
        power[i] = (power[i-1] * p) % MOD;
    }
}
 
Hash get_hash(const string &s)
{
    Hash ret = 0;
    for(int i=0; i<s.size(); i++)
    {
        ret = (ret + power[i]*(s[i]-'a'+1)) % MOD;
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    calc_power();
 
    int n, m;
    string s;
    cin >> n >> m;
    set<Hash> st;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        st.insert(get_hash(s));
    }
    for(int i=0; i<m; i++)
    {
        cin >> s;
        Hash val = get_hash(s), cur;
        bool found = false;
        for(int j=0; j<s.size(); j++)
        {
            s[j] = s[j] - 'a' + 1;
            for(int k=1; k<=3; k++)
            {
                if(k != s[j])
                {
                    cur = (val - power[j]*s[j] + power[j]*k + MOD*4) % MOD;
                    if(st.count(cur))
                    {
                        found = true;
                        break;
                    }
                }
            }
        }
        if(found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
 
    return 0;
}