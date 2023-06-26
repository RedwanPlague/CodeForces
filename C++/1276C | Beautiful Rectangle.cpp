#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pii;
 
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n;
    cin >> n;
    vi a(n);
    map <ll,ll> mp;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
 
    vector<ll> cnt(n+1,0);
    vector<pii> ar;
 
    for(auto x : mp)
    {
        cnt[x.S]++;
    }
 
    for(int i=n-1; i>0; i--)
        cnt[i] += cnt[i+1];
 
    ll mx = 0, mr, mc;
    ll sum = 0;
    for(ll r=1; r<=n; r++)
    {
        sum += cnt[r];
        ll c = sum/r;
        if(c >= r && r*c > mx)
        {
            mx = r*c;
            mr = r;
            mc = c;
        }
    }
 
    for(auto x : mp)
    {
        ar.push_back({min(x.S,mr),x.F});
    }
    sort(ar.begin(), ar.end(), greater<pii>());
 
    vector<vi> ans(mr,vi(mc));
 
    int id = 0;
    for(int i=0; i<mc; i++)
    {
        for(int j=0; j<mr; j++)
        {
            ans[j][(j+i)%mc] = ar[id].S;
            ar[id].F--;
            if(ar[id].F == 0)
                id++;
        }
    }
 
    cout << mx << '\n';
    cout << mr << ' ' << mc << '\n';
    for(int i=0; i<mr; i++)
    {
        for(int j=0; j<mc; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
 
    return 0;
}