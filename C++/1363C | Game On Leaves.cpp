#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
#define MX 35
#define MOD 1'000'000'007
#define F first
#define S second
#define invmod(x) bigmod(x,MOD-2)
#define br '\n'
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
 
vvi read_tree(int n)
{
    vvi adj(n);
    int u, v;
    for(int i=1; i<n; i++)
    {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}
 
int dfs(int src, int par, const vvi& adj)
{
    int size = 1;
    for(auto &v: adj[src])
    {
        if(v != par)
            size += dfs(v, src, adj);
    }
    return size;
}
 
void solve()
{
    int n, x;
    cin >> n >> x;
    x--;
    vvi adj = read_tree(n);
 
    if(adj[x].size() <= 1)
    {
        cout << "Ayush\n";
        return ;
    }
 
    int xr = 0;
    for(auto &v: adj[x])
        xr += dfs(v, x, adj);
 
    if(xr&1)
        cout << "Ayush\n";
    else
        cout << "Ashish\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    while(cin >> T)
    {
        while(T--)
        {
            solve();
        }
    }
 
    return 0;
}