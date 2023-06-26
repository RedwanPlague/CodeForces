#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
 
#define br '\n'
 
using namespace std;
 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;
 
const int MOD = 998244353;
 
ll ways(const int cur, const vector<vi> &adj, vi &vis)
{
    ll ret = 1;
    for(int i=0; i<adj[cur].size(); i++)
    {
        int v = adj[cur][i];
        if(vis[v] == -1)
        {
            vis[v] = 3 - vis[cur];
            ll val = ways(v,adj,vis);
            if(val == -1)
                return -1;
            ret = (ret * val) % MOD;
        }
        else if(vis[v] == vis[cur])
            return -1;
    }
    ret = (ret * vis[cur]) % MOD;
    return ret;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif // ONLINE_JUDGE
 
    int T;
    cin >> T;
 
    while(T--)
    {
        int n, m;
        cin >> n >> m;
        vector<vi> adj(n+1);
        int u, v;
        for(int i=0; i<m; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vi vis1(n+1,-1), vis2(n+1,-1);
        ll ans = 1;
        for(int i=1; i<=n; i++)
        {
            if(vis1[i] == -1)
            {
                vis1[i] = 1;
                vis2[i] = 2;
                ll val = ways(i,adj,vis1) + ways(i,adj,vis2);
                if(val == -2)
                    val = 0;
                val %= MOD;
                ans = ( ans * val ) % MOD;
            }
        }
        cout << ans << br;
    }
 
    return 0;
}