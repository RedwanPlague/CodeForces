#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
 
#define MX 105
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
void dfs(int u, const vector<vi> &adj, vl &cnt, vi &par)
{
    cnt[u] = 1;
    for(int v: adj[u])
    {
        if(cnt[v] == -1)
        {
            dfs(v,adj,cnt,par);
            par[v] = u;
            cnt[u] += cnt[v];
        }
    }
}
 
ll mex(int u, int v, vector<vl> &dp, const vector<vl> &cnt, const vector<vi> &par)
{
    if(u == v)
        return 0;
    if(dp[u][v] != -1)
        return dp[u][v];
    return (dp[u][v] = cnt[u][v] * cnt[v][u] + max( mex(par[v][u], v, dp,cnt,par), mex(par[u][v], u, dp,cnt,par) ));
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n, u, v;
    cin >> n;
    vector<vi> adj(n), par(n,vi(n));
    vector<vl> cnt(n,vl(n,-1)), dp(n,vl(n,-1));
    for(int i=1; i<n; i++)
    {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for(int i=0; i<n; i++)
        dfs(i,adj,cnt[i],par[i]);
 
    ll max_mex = -1;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            max_mex = max(max_mex, mex(i,j,dp,cnt,par));
    
    cout << max_mex << endl;
 
    return 0;
}