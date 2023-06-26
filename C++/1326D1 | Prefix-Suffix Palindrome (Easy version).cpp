#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
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
 
const int MX = 1000005;
pll base = {29,31};
pll MOD = {1e9+7,1e9+9};
 
vector<pll> pw(MX+1);
 
void power_calc() // calculates the power table
{
    pw[0] = {1LL,1LL};
    for(int i=1; i<=MX; i++)
    {
        pw[i] = pw[i-1] * base % MOD;
    }
}
 
void Hash(const string &s, vector<pll> &pre, vector<pll> &suf)
{
    pre.resize(s.length()+1);
    suf.resize(s.length()+1);
    pre[0] = {0,0};
    suf.back() = {0,0};
    for(int i=0; i<s.length(); i++)
    {
        pre[i+1] = (pre[i] + pw[i] * (s[i] - 'a' + 1)) % MOD;
    }
    for(int i=s.length()-1; i>=0; i--)
    {
        suf[i] = (suf[i+1] + pw[s.length()-1-i] * (s[i] - 'a' + 1)) % MOD;
    }
}
 
bool palindrome(int l, int r, const vector<pll> &pre, const vector<pll> &suf)
{
    return ( ((pre[r+1]-pre[l]+MOD) * pw[MX-l])%MOD == ((suf[l]-suf[r+1]+MOD) * pw[MX+r-suf.size()+2])%MOD );
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    power_calc();
 
    int T;
    cin >> T;
    while(T--)
    {
        string s;
        cin >> s;
        vector<pll> pre, suf;
        Hash(s,pre,suf);
        string top;
        for(int i=0, j=s.length()-1; s[i] == s[j] && i < j; i++, j--)
        {
            top += s[i];
        }
        int l = top.size(), r = s.length() - top.size() - 1;
        int mx = 0, ll = -1, rr = -1;
        for(int i=l; i<=r; i++)
        {
            if(palindrome(l,i,pre,suf) && (i-l+1) > mx)
            {
                mx = i - l + 1;
                ll = l;
                rr = i;
            }
        }
        for(int i=r; i>=l; i--)
        {
            if(palindrome(i,r,pre,suf) && (r-i+1) > mx)
            {
                mx = r - i + 1;
                ll = i;
                rr = r;
            }
        }
        string t = top;
        if(mx)
        {
            for(int i=ll; i<=rr; i++)
            {
                t += s[i];
            }
        }
        reverse(all(top));
        t += top;
        cout << t << '\n';
    }
 
    return 0;
}