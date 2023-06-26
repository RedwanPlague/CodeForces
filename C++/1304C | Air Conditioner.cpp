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
#define pb push_back
 
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
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int Q;
    cin >> Q;
    while(Q--)
    {
        int n, m;
        cin >> n >> m;
        ll L = m, R = m, T = 0;
        ll l, r, t;
        bool mara = false;
        for(int i=0; i<n; i++)
        {
            cin >> t >> l >> r;
            if(!mara)
            {
                L -= (t-T);
                R += (t-T);
                if(R < l || r < L)
                {
                    mara = true;
                    continue;
                }
                L = max(L,l);
                R = min(R,r);
                T = t;
            }
        }
        if(mara)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 