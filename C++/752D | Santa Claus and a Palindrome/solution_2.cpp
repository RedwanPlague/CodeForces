#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
 
#define br '\n'
#define x first
#define y second
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
 
const int MX = 100005;
const ll p1 = 29;
const ll p2 = 31;
const ll mod1 = 1e9+7;
const ll mod2 = 1e9+9;
 
vl pow1(MX), pow2(MX);
 
void power_calc() // calculates the power table of the two primes p1 and p2
{
    pow1[0] = pow2[0] = 1LL;
    for(int i=1; i<MX; i++)
    {
        pow1[i] = (pow1[i-1] * p1) % mod1;
        pow2[i] = (pow2[i-1] * p2) % mod2;
    }
}
 
pll hash_value(const string &s) // calculates the hash of s
{
    ll val1 = 0, val2 = 0;
    for(int i=0; i<s.length(); i++)
    {
        val1 = (val1 + (s[i] - 'a' + 1) * pow1[i]) % mod1;
        val2 = (val2 + (s[i] - 'a' + 1) * pow2[i]) % mod2;
    }
    return pll(val1,val2);
}
 
vector<pll> prefix_hash(const string &s)
{
    vector<pll> pre(s.length());
    pre[0].x = pre[0].y = s[0] - 'a' + 1;
    for(int i=1; i<s.length(); i++)
    {
        pre[i].x = (pre[i-1].x + (s[i] - 'a' + 1) * pow1[i]) % mod1;
        pre[i].y = (pre[i-1].y + (s[i] - 'a' + 1) * pow2[i]) % mod2;
    }
    return pre;
}
 
inline pll range_hash(const vector<pll> &pre, const int l, const int r)
{
    return ( (!l) ? pre[r] : pll( (pre[r].x - pre[l-1].x + mod1) %mod1, (pre[r].y - pre[l-1].y + mod2) %mod2 ) );
}
 
inline pll shift(const pll &val, const int add)
{
    return pll( (val.x * pow1[add])%mod1, (val.y * pow2[add])%mod2 );
}
 
int main()
{
    power_calc();
 
    int k, n;
    cin >> k >> n;
 
    vector<pll> hf(k), hr(k); // hf = forward hash, hr = reverse hash
    vl val(k);
    string s;
    for(int i=0; i<k; i++)
    {
        cin >> s >> val[i];
        hf[i] = hash_value(s);
        reverse(s.begin(), s.end());
        hr[i] = hash_value(s);
    }
 
    map <pll, pair<vl,vl> > diff;
    map <pll,vl> same;
    for(int i=0; i<k; i++)
    {
        if(hf[i] == hr[i])
        {
            same[hf[i]].push_back(val[i]);
        }
        else if(hf[i] < hr[i])
        {
            diff[hf[i]].first.push_back(val[i]);
        }
        else
        {
            diff[hr[i]].second.push_back(val[i]);
        }
    }
 
    ll ans = 0;
    for(map <pll, pair<vl,vl> > :: iterator it = diff.begin(); it != diff.end(); it++)
    {
        vl& v1 = it->second.first;
        vl& v2 = it->second.second;
        sort(v1.rbegin(), v1.rend());
        sort(v2.rbegin(), v2.rend());
        for(int i=0; i < v1.size() && i < v2.size() && v1[i]+v2[i] > 0; i++)
        {
            ans += v1[i] + v2[i];
        }
    }
 
    //cout << ans << endl;
 
    ll mx = 0;
    for(map <pll,vl> :: iterator it = same.begin(); it != same.end(); it++)
    {
        vl& v = it->second;
        sort(v.rbegin(), v.rend());
        int i;
        for(i=0; i+1<v.size() && v[i+1] > 0; i+=2)
            ans += v[i] + v[i+1];
        if(i+1 < v.size())
        {
            if(v[i] <= 0 && v[i+1] <= 0)
                continue;
            if(v[i] < abs(v[i+1]))
            {
                mx = max(mx, v[i]);
            }
            else
            {
                ans += (v[i] + v[i+1]);
                mx = max(mx, -v[i+1]);
            }
        }
        else if(i < v.size())
        {
            mx = max(mx, v[i]);
        }
    }
 
    //cout << ans << endl;
    //cout << mx << endl;
    cout << ans + mx << endl;
 
    return 0;
}