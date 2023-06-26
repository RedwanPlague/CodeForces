#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 105
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
ll bigmod(ll base, ll pw)
{
    base %= MOD;
    pw = (pw + MOD - 1) % (MOD - 1);
    ll ret = 1;
    while(pw)
    {
        if(pw&1)
            ret = (ret*base)%MOD;
        base = (base*base)%MOD;
        pw >>= 1;
    }
    return ret;
}
 
vi prime;
vector<bool> isp(MX,true);
void sieve()
{
    int limit = sqrt(MX+.0);
    isp[0] = isp[1] = false;
    prime.push_back(2);
    for(int i=4; i<MX; i+=2)
        isp[i] = false;
    for(int i=3; i<MX; i+=2)
    {
        if(isp[i])
        {
            prime.push_back(i);
            if(i < limit)
            {
                for(int j=i*i; j<MX; j+=2*i)
                    isp[j] = false;
            }
        }
    }
}
 
string s;
char c[3] = {'a', 'b', 'c'};
 
char rep(int prev, int next)
{
    for(int i=0; i<3; i++)
    {
        if(c[i] != (prev >= 0 ? s[prev] : '?') && c[i] != (next <s.size() ? s[next] : '?'))
            return c[i];
    }
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int T;
    cin >> T;
    while(T--)
    {
        cin >> s;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '?')
                s[i] = rep(i-1,i+1);
        }
        bool ok = true;
        for(int i=1; i<s.size(); i++)
        {
            if(s[i] == s[i-1])
            {
                ok = false;
                break;
            }
        }
        if(ok)
            cout << s << '\n';
        else
            cout << -1 << '\n';
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 