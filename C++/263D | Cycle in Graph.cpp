#include <iostream>
#include <vector>
 
using namespace std;
 
typedef vector<int> vi;
 
int dfs(const int cur, const vector<vi> &adj, vi &par)
{
    int ret = cur;
    for(int i=0; i<adj[cur].size(); i++)
    {
        int v = adj[cur][i];
        if(par[v] == -1)
        {
            par[v] = cur;
            ret = dfs(v,adj,par);
        }
    }
    return ret;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
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
 
    int src = 1;
    vi par(n+1,-1);
    par[src] = -2;
    int last = dfs(src,adj,par);
 
    vector<bool> mark(n+1,0);
    for(int i=0; i<adj[last].size(); i++)
        mark[adj[last][i]] = 1;
 
    int first, cur = par[last], cnt = 2, length;
    vi ans;
    ans.push_back(last);
    while(cur != -2)
    {
        ans.push_back(cur);
        if(mark[cur])
        {
            first = cur;
            length = cnt;
        }
        cur = par[cur];
        cnt++;
    }
    cout << length << '\n';
    int idx = ans.size()-1;
    while(ans[idx] != first)
        idx--;
    while(idx >= 0)
        cout << ans[idx--] << ' ';
    cout << endl;
 
    return 0;
}