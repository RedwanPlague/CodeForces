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
        int p;
        vi a;
        int cnt = 0;
        int prev = -1;
        for(int i=0; i<n; i++)
        {
            cin >> p;
            if(p != prev)
            {
                a.push_back(cnt);
                cnt = 0;
            }
            cnt++;
            prev = p;
        }
        a.push_back(cnt);
 
        vi sum(a.size());
        sum[0] = a[0];
        int lim = -1;
        for(int i=1; i<a.size(); i++)
        {
            sum[i] = sum[i-1] + a[i];
            if(lim == -1 && sum[i] > n/2)
                lim = i-1;
        }
 
        int g = 0, s = 0, b = 0, dg, ds, db;
        for(int i=1; i<=lim; i++)
        {
            dg = sum[i];
            int id = upper_bound(sum.begin()+i+1, sum.begin()+lim+1, 2*dg) - sum.begin();
            if(id > lim)
                continue;
 
            ds = sum[id] - dg;
            db = sum[lim] - sum[id];
            if(dg < ds && dg < db && (dg+ds+db) > (g+s+b))
            {
                g = dg;
                s = ds;
                b = db;
            }
        }
 
        cout << g << ' ' << s << ' ' << b << '\n';
 
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 