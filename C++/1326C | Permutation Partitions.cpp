#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 105
#define MOD 998244353
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
 
 
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n, k;
    while(cin >> n >> k)
    {
        int a;
        vi pos(n+1);
        for(int i=0; i<n; i++)
        {
            cin >> a;
            pos[a] = i;
        }
        vi v;
        ll sum = 0, way = 1;
        for(int i=0, take = n; i<k; i++, take--)
        {
            v.push_back(pos[take]);
            sum += take;
        }
        sort(all(v));
        for(int i=1; i<k; i++)
        {
            way = (way * (v[i] - v[i-1])) % MOD;
        }
        cout << sum << ' ' << way << endl;
    }
 
    return 0;
}