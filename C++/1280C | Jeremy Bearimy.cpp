#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 200005
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
struct Edge
{
    int u, v;
    ll w;
};
 
int sz[MX];
int vis[MX], mark;
 
void dfs(int u, vector<vi> &adj)
{
    vis[u] = mark;
    sz[u] = 1;
    for(int i=0; i<adj[u].size(); i++)
    {
        int &v = adj[u][i];
        if(vis[v] != mark)
        {
            dfs(v,adj);
            sz[u] += sz[v];
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
        int k;
        cin >> k;
        int n = 2*k;
        vector<vi> adj(n);
        vector <Edge> edge(n-1);
        int u, v;
        ll w;
        for(int i=0; i<n-1; i++)
        {
            cin >> u >> v >> w;
            u--; v--;
            edge[i].u = u;
            edge[i].v = v;
            edge[i].w = w;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        mark++;
        dfs(0,adj);
        /*for(int i=0; i<n; i++)
            cout << sz[i] << ' ' ;*/
        ll b = 0, g = 0;
        for(int i=0; i<n-1; i++)
        {
            int su = min(sz[edge[i].u],sz[edge[i].v]);
            int sv = n - su;
            if(su&1)
                g += edge[i].w;
            b += min(su,sv)*edge[i].w;
        }
        cout << g << ' ' << b << '\n';
    }
 
    return 0;
}
 
 
 
 
 
 
 
 