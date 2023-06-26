#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 300005
#define MOD 1000000007
#define pb push_back
#define br '\n'
 
bool vis[MX];
vector <int> adj[MX];
ll n;
int f, b;
int parf, parb;
int par[MX];
 
ll dfs(int u)
{
    vis[u] = 1;
    ll cnt = 1;
    for(int i=0; i<adj[u].size(); i++)
    {
        int &v = adj[u][i];
        if(vis[v] == 0 && par[u] != v)
        {
            par[v] = u;
            cnt += dfs(v);
        }
    }
    return cnt;
}
 
int main()
{
    ios_base::sync_with_stdio(0); // cin.tie(0); cout.tie(0);
 
    int u, v;
    cin>>n>>f>>b;
    for(int i=0; i<n-1; i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    memset(vis, 0, sizeof(vis));
    memset(par, 0, sizeof(par));
    dfs(f);
    parb = par[b];
    //cout<<parb<<endl;
    memset(vis, 0, sizeof(vis));
    memset(par, 0, sizeof(par));
    dfs(b);
    parf = par[f];
    par[b] = parb;
    //cout<<parf<<endl;
 
    memset(vis, 0, sizeof(vis));
    ll cf = dfs(f);
    memset(vis, 0, sizeof(vis));
    ll cb = dfs(b);
 
    //cout<<cf<<' '<<cb<<endl;
 
    cout<<n*(n-1)-cf*cb<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 