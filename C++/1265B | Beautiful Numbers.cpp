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
        int n;
        cin >> n;
        vi p(n+1), idx(n+1);
        int cur;
        for(int i=0; i<n; i++)
        {
            cin >> p[i];
            idx[p[i]] = i;
            if(p[i] == 1)
                cur = i;
        }
        int cnt = 1;
        vector<bool> mark(n+1,false);
        mark[cur] = 1;
        cout << 1;
 
        int lo = cur, hi = cur;
 
        for(int i=2; i<=n; i++)
        {
            if(idx[i] < lo)
            {
                while(lo > idx[i])
                {
                    lo--;
                    mark[lo] = 1;
                    cnt++;
                }
            }
            else if(hi < idx[i])
            {
                while(hi < idx[i])
                {
                    hi++;
                    mark[hi] = 1;
                    cnt++;
                }
            }
            cout << (i == cnt);
        }
        cout << '\n';
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 