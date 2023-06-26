#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define MX 10005
 
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
 
Hash get_rev_hash(const string &s)
{
    Hash ret = 0;
    for(int i=s.size()-1, j=0; i>=0; i--, j++)
    {
        ret = (ret + power[j]*(tolower(s[i])-'a'+1)) % MOD;
    }
    return ret;
}
 
int bin_search(const vector< pair<Hash,int> > &hv, Hash key)
{
    int lo = 0, hi = hv.size()-1, mid;
    while(lo <= hi)
    {
        mid = (lo+hi)/2;
        if(hv[mid].first < key)
            lo = mid+1;
        else if(hv[mid].first == key)
            return hv[mid].second;
        else
            hi = mid-1;
    }
    return -1;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    calc_power();
 
    int n;
    string text;
    cin >> n >> text;
 
    for(int i=0; i<n; i++)
        text[i] -= ('a'-1);
 
    int m, mxlen = 0;
    cin >> m;
    vector<string> word(m);
    vector< pair<Hash,int> > hv(m);
    for(int i=0; i<m; i++)
    {
        cin >> word[i];
        mxlen = max(mxlen,(int)word[i].size());
        hv[i].first = get_rev_hash(word[i]);
        hv[i].second = i;
    }
 
    sort(hv.begin(), hv.end());
 
    vector<int> next(n+1);
    next[n] = n;
    Hash cur;
    for(int i=n-1; i>=0; i--)
    {
        next[i] = -1;
        cur = 0;
        for(int j=i, len=0; j<n && len < mxlen; j++, len++)
        {
            cur = (cur + power[len]*text[j]) % MOD;
            int it = bin_search(hv,cur);
            if(it != -1 && next[j+1] != -1)
            {
                next[i] = it;
                break;
            }
        }
    }
 
    /*for(int i=0; i<n; i++)
    {
        cout << i << ' ';
        if(next[i] != -1)
            cout << word[next[i]];
        cout << '\n';
    }*/
 
    for(int i=0; i<n; i += word[next[i]].size())
    {
        cout << word[next[i]] << ' ';
    }
 
    return 0;
}