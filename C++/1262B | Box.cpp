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
        vi q(n);
        for(int i=0; i<n; i++)
        {
            cin >> q[i];
            q[i]--;
        }
 
        vi ans(n,-1);
        int prev = -1;
        vector <bool> used(n,false);
 
        for(int i=0; i<n; i++)
        {
            if(q[i] != prev)
            {
                ans[i] = q[i];
                used[q[i]] = true;
            }
            prev = q[i];
        }
 
        vi left;
        for(int i=0; i<n; i++)
            if(!used[i])
                left.push_back(i);
 
        for(int i=0, j=0; i<n; i++)
        {
            if(ans[i] == -1)
                ans[i] = left[j++];
        }
 
        bool ok = true;
        int mx = -1;
        for(int i=0; i<n; i++)
        {
            mx = max(mx,ans[i]);
            if(mx != q[i])
            {
                ok = false;
                break;
            }
        }
 
        if(!ok)
            cout << -1 << '\n';
        else
        {
            for(int i=0; i<n; i++)
                cout << ans[i]+1 << ' ' ;
            cout << '\n';
        }
 
    }
 
 
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 