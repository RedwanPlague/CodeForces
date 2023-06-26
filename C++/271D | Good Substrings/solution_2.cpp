#include <iostream>
#include <vector>
#include <string>
#include <set>
 
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
 
const int MX = 1505;
pll base = {29,31};
pll MOD = {1e9+7,1e9+9};
 
vector<pll> pow(MX);
vector<pll> pre;
int N;
 
void power_calc() // calculates the power table
{
    pow[0] = {1LL,1LL};
    for(int i=1; i<MX; i++)
    {
        pow[i] = (pow[i-1] * base) % MOD;
    }
}
 
void prefix_hash(const string &s)
{
    pre.resize(N+1);
    pre[0] = {0,0};
    for(int i=0; i<s.length(); i++)
    {
        pre[i+1] = (pre[i] + pow[i] * (s[i] - 'a' + 1)) % MOD;
    }
}
 
inline pll rhash(const int l, const int r)
{
    return ( ( (pre[r+1] - pre[l] + MOD) * pow[N-l] ) %MOD );
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    power_calc();
 
    int k;
    string s, mark;
    cin >> s >> mark >> k;
 
    N = s.length();
    prefix_hash(s);
 
    set<pll> st;
 
    for(int l=0; l<N; l++)
    {
        int cnt = 0;
        for(int r=l; r<N; r++)
        {
            cnt += ('1' - mark[s[r]-'a']);
            if(cnt > k)
                break;
            else
            {
                st.insert(rhash(l,r));
            }
        }
    }
 
    cout << st.size() << endl;
 
    return 0;
}