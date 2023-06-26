#include <iostream>
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
 
const int MX = 2000005;
const ll p1 = 29;
const ll p2 = 31;
const ll mod1 = 1e9+7;
const ll mod2 = 1e9+9;
int n, k, len, q;
 
vl pow1(MX), pow2(MX);
vector<pll> pre;
string t;
map <pll,int> mp;
 
void power_calc()
{
    pow1[0] = pow2[0] = 1LL;
    for(int i=1; i<MX; i++)
    {
        pow1[i] = (pow1[i-1] * p1) % mod1;
        pow2[i] = (pow2[i-1] * p2) % mod2;
    }
}
 
pll hash_value(const string &s)
{
    ll val1 = 0, val2 = 0;
    for(int i=0; i<s.length(); i++)
    {
        val1 = (val1 + (s[i] - 'a' + 1) * pow1[i]) % mod1;
        val2 = (val2 + (s[i] - 'a' + 1) * pow2[i]) % mod2;
    }
    val1 = (val1 * pow1[len]) % mod1;
    val2 = (val2 * pow2[len]) % mod2;
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
 
inline pll range_hash(const int l, const int r)
{
    return ( (!l) ? pre[r] : pll( (pre[r].x - pre[l-1].x + mod1) %mod1, (pre[r].y - pre[l-1].y + mod2) %mod2 ) );
}
 
inline pll shift(const pll &val, const int add)
{
    return pll( (val.x * pow1[add])%mod1, (val.y * pow2[add])%mod2 );
}
 
bool check(const int idx)
{
    vector<bool> mark(q+1,0);
    map <pll,int> :: iterator it;
    for(int i = idx, cnt = 0; cnt < n; i += k, cnt++)
    {
        it = mp.find(shift(range_hash(i,i+k-1),len-i));
        if(it == mp.end() || mark[it->second])
            return false;
        mark[it->second] = 1;
    }
    return true;
}
 
void print(const int idx)
{
    map <pll,int> :: iterator it;
    for(int i = idx, cnt = 0; cnt < n; i += k, cnt++)
    {
        it = mp.find(shift(range_hash(i,i+k-1),len-i));
        cout << it->second << ' ';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    power_calc();
 
    cin >> n >> k;
    len = n*k;
    cin >> t;
    t += t;
    pre = prefix_hash(t);
    cin >> q;
    string s;
    for(int i=1; i<=q; i++)
    {
        cin >> s;
        mp[hash_value(s)] = i;
    }
 
    int idx = -1;
    for(int i=0; i<len; i++)
    {
        if( mp.count(shift(range_hash(i,i+k-1),len-i)) )
        {
            idx = i;
            break;
        }
    }
    if(idx == -1)
    {
        cout << "NO" << endl;
        return 0;
    }
 
    //cout << "aisi" << endl;
 
    for(int i=idx; i<idx+k; i++)
    {
        if(check(i))
        {
            cout << "YES\n";
            print(i);
            return 0;
        }
    }
 
    cout << "NO" << endl;
 
    return 0;
}