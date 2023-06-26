#include <iostream>
#include <vector>
#include <string>
 
#define br '\n'
#define F first
#define S second
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
 
ostream& operator<<(ostream &os, const pll &a)
{
    os << "(" << a.F << "," << a.S << ")";
}
 
pll operator+(const pll &a, const ll &b) { return { a.F + b, a.S + b }; }
pll operator*(const pll &a, const ll &b) { return { a.F * b, a.S * b }; }
pll operator+(const pll &a, const pll &b) { return { a.F + b.F, a.S + b.S }; }
pll operator-(const pll &a, const pll &b) { return { a.F - b.F, a.S - b.S }; }
pll operator*(const pll &a, const pll &b) { return { a.F * b.F, a.S * b.S }; }
pll operator%(const pll &a, const pll &b) { return { a.F % b.F, a.S % b.S }; }
 
const int MX = 5005;
int N;
pll base = {29,31};
pll MOD = {1e9+7,1e9+9};
 
vector<pll> pow(MX);
vector<pll> pre, suf;
 
void power_calc() // calculates the power table
{
    pow[0] = {1LL,1LL};
    for(int i=1; i<MX; i++)
    {
        pow[i] = (pow[i-1] * base) % MOD;
    }
}
 
pll hash_value(const string &s) // calculates the hash of s
{
    pll val = {0,0};
    for(int i=0; i<s.length(); i++)
    {
        val = (val + pow[i] * (s[i] - 'a' + 1)) % MOD;
    }
    return val;
}
 
vector<pll> prefix_hash(const string &s)
{
    vector<pll> pre(N);
    pre[0].F = pre[0].S = s[0] - 'a' + 1;
    for(int i=1; i<N; i++)
    {
        pre[i] = (pre[i-1] + pow[i] * (s[i] - 'a' + 1)) % MOD;
    }
    return pre;
}
 
vector<pll> suffix_hash(const string &s)
{
    vector<pll> suf(N);
    suf[0].F = suf[0].S = s[N-1] - 'a' + 1;
    for(int i=1; i<N; i++)
    {
        suf[i] = (suf[i-1] + pow[i] * (s[N-i-1] - 'a' + 1)) % MOD;
    }
    return suf;
}
 
inline pll range_hash(const vector<pll> &v, const int l, const int r)
{
    return ( (!l) ? v[r] : ( (v[r] - v[l-1] + MOD) %MOD ) );
}
 
inline pll shift(const pll &val, const int add)
{
    return ( (val * pow[add]) % MOD) ;
}
 
bool match(const int l1, const int r1, const int l2, const int r2)
{
    return ( shift(range_hash(pre,l1,r1),N-l1) == shift(range_hash(pre,l2,r2),N-l2) );
}
 
bool is_palindrom(const int l, const int r)
{
    return ( shift(range_hash(pre,l,r),N-l) == shift(range_hash(suf,N-r-1,N-l-1),r+1) );
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    power_calc();
    string s;
    cin >> s;
    N = s.length();
 
    pre = prefix_hash(s);
    suf = suffix_hash(s);
 
    vi cnt(N+1,0);
    vector<vi> pal(N+1,vi(N+1,0));
 
    for(int i=0; i<N; i++)
        pal[i][i] = 1;
    cnt[1] += N;
 
    int midl, midr;
    for(int len = 2; len <= N; len++)
    {
        for(int i=0; i+len-1<N; i++)
        {
            midl = i+len/2-1;
            midr = midl + 1 + (len&1);
            if(match(i,midl,midr,i+len-1) && pal[i][midl])
                pal[i][i+len-1] = 1 + pal[i][midl];
            else if(is_palindrom(i,i+len-1))
                pal[i][i+len-1] = 1;
            cnt[ pal[i][i+len-1] ]++;
        }
    }
 
    /*for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout << pal[i][j] << ' ';
        }
        cout << br;
    }*/
 
    for(int i=N; i>0; i--)
        cnt[i-1] += cnt[i];
 
    for(int i=1; i<=N; i++)
        cout << cnt[i] << ' ';
    cout << endl;
 
    return 0;
}