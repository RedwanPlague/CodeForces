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
 
const int MX = 5000005;
int N;
pll base = {269,271};
pll MOD = {1e9+7,1e9+9};
 
vector<pll> pow(MX);
vector<pll> suf;
 
void power_calc() // calculates the power table
{
    pow[0] = {1LL,1LL};
    for(int i=1; i<MX; i++)
    {
        pow[i] = (pow[i-1] * base) % MOD;
    }
}
 
pll pre;
 
vector<pll> suffix_hash(const string &s)
{
    vector<pll> suf(N+1);
    suf[0] = {0,0};
    for(int i=0; i<N; i++)
    {
        suf[i+1] = (suf[i] + pow[i] * s[N-i-1]) % MOD;
    }
    return suf;
}
 
inline bool is_palindrom(const int idx)
{
    return ( (pre * pow[N]) % MOD == ( (suf[N] - suf[N-idx-1] + MOD) * pow[idx+1] ) % MOD );
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    power_calc();
    string s;
    cin >> s;
    N = s.length();
 
    suf = suffix_hash(s);
 
    vi pal(N);
    pal[0] = 1;
 
    int sum = 1;
    pre = {s[0],s[0]};
 
    for(int i=1; i<N; i++)
    {
        pre = (pre + pow[i] * s[i]) % MOD;
        if(is_palindrom(i))
            pal[i] = 1 + pal[(i-1)/2];
        else
            pal[i] = 0;
        sum += pal[i];
    }
 
    cout << sum << endl;
 
    return 0;
}