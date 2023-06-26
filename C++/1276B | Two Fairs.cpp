#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 200005
 
int n, m, a, b;
int vis[MX], mark;
 
ll dfs(int u, int x, vector<vi> &adj)
{
    if(u == x)
        return 0;
    vis[u] = mark;
    ll ret = 1;
    for(int i=0; i<adj[u].size(); i++)
    {
        int &v = adj[u][i];
        if(vis[v] != mark)
            ret += dfs(v,x,adj);
    }
    return ret;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int t;
    cin >> t;
    while(t--)
    {
        int u, v;
        cin >> n >> m >> a >> b;
        a--;
        b--;
        vector<vi> adj(n);
        for(int i=0; i<m; i++)
        {
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        mark++;
        ll one = n - dfs(b,a,adj) - 1;
        mark++;
        ll two = n - dfs(a,b,adj) - 1;
        cout << one*two << '\n';
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 