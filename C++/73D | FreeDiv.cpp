#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef vector<int> vi;
 
inline int ceil(const int a, const int b)
{
    if(a <= 0)
        return 0;
    return (a-1)/b+1;
}
 
int dfs(const int cur, const vector<vi> &adj, vector<bool> &vis) // returns number of nodes in current component
{
    vis[cur] = true;
    int ret = 1;
    for(int i=0; i<adj[cur].size(); i++)
    {
        int v = adj[cur][i];
        if(!vis[v])
            ret += dfs(v,adj,vis);
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<vi> adj(n+1);
    int u, v;
    for(int i=0; i<m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vector<bool> vis(n+1,0);
    int N = 0, sum = 0;
 
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            sum += min(k,dfs(i,adj,vis));
            N++;
        }
    }
 
    if(k == 1)
        cout << max(0,N-2) << endl;
    else
        cout << max(0,N-sum/2-1) << endl;
 
    return 0;
}