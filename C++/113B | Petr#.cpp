#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define MX 2001
 
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
 
    string text, sbeg, send;
    cin >> text >> sbeg >> send;
    int tlen = text.size(), lbeg = sbeg.size(), lend = send.size();
 
    Hash strhash[MX][MX];
    for(int i=0; i<tlen; i++)
    {
        strhash[i][i] = (text[i]-'a'+1);
        for(int j=i+1; j<tlen; j++)
        {
            strhash[i][j] = (strhash[i][j-1] + power[j-i]*(text[j]-'a'+1)) % MOD;
        }
    }
 
    int mnlen = max(lbeg, lend);
    Hash hbeg = get_hash(sbeg);
    Hash hend = get_hash(send);
 
    vector<Hash> v;
 
    for(int i=0; i<tlen; i++)
    {
        for(int j=i+mnlen-1; j<tlen; j++)
        {
            if(hbeg == strhash[i][i+lbeg-1] && hend == strhash[j-lend+1][j])
                v.push_back(strhash[i][j]);
        }
    }
 
    sort(v.begin(),v.end());
    cout << distance(v.begin(),unique(v.begin(),v.end()));
 
    return 0;
}