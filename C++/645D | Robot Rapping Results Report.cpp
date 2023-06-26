#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
 
#define F first
#define S second
 
using namespace std;
 
typedef pair<int,int> pii;
typedef vector<pii> vii;
 
const int INF = 1000000007;
 
void top_sort(const int cur, const vector<vii> &adj, stack<int> &stk, vector<bool> &vis)
{
    vis[cur] = true;
    for(int i=0; i<adj[cur].size(); i++)
    {
        int v = adj[cur][i].F;
        if(!vis[v])
            top_sort(v,adj,stk,vis);
    }
    stk.push(cur);
}
 
int index(const int item, const vii &v)
{
    for(int i=0; i<v.size(); i++)
    {
        if(v[i].F == item)
            return v[i].S;
    }
    return INF;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<vii> adj(n+1);
    int u, v;
    for(int i=1; i<=m; i++)
    {
        cin >> u >> v;
        adj[u].push_back({v,i});
    }
 
    stack<int> stk;
    vector<bool> vis(n+1,0);
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
            top_sort(i,adj,stk,vis);
    }
 
    int mx = 0;
    u = stk.top();
    stk.pop();
    while(!stk.empty())
    {
        v = stk.top();
        stk.pop();
        mx = max(mx, index(v,adj[u]));
        u = v;
    }
 
    if(mx == INF)
        cout << -1 << endl;
    else
        cout << mx << endl;
 
    return 0;
}