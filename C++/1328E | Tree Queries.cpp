#include <iostream>
#include <vector>
 
using namespace std;
 
typedef vector<int> vi;
 
int n, l;
vector<vi> adj;
 
int timer;
vi tin, tout, dist, par;
vector<vi> up;
 
void dfs(int v, int p)
{
 dist[v] = 1 + dist[p];
 par[v] = p;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
 
    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }
 
    tout[v] = ++timer;
}
 
bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i)
 {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
 
void preprocess(int root) 
{
    tin.resize(n);
    tout.resize(n);
 dist.assign(n,-1);
 par.resize(n);
    timer = 0;
    l = 0;
 while((1<<l) < n)
  l++;
    up.assign(n, vi(l + 1));
    dfs(root, root);
}
 
bool near(const vi &li)
{
 int low = -1, maxd = -1;
 for(int i=0; i<li.size(); i++)
 {
  if(dist[li[i]] > maxd)
  {
   maxd = dist[li[i]];
   low = li[i];
  }
 }
 for(int i=0; i<li.size(); i++)
 {
  int com = lca(low,li[i]);
  if(com != li[i] && com != par[li[i]])
   return false;
 }
 return true;
}
 
int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(nullptr);
 
 int m;
 cin >> n >> m;
 int u, v;
 adj.resize(n);
 for(int i=1; i<n; i++)
 {
  cin >> u >> v;
  u--; v--;
  adj[u].push_back(v);
  adj[v].push_back(u);
 }
 
 preprocess(0);
 
 while(m--)
 {
  int k;
  cin >> k;
  vi li(k);
  for(int i=0; i<k; i++)
  {
   cin >> li[i];
   li[i]--;
  }
  if(near(li))
   cout << "YES\n";
  else
   cout << "NO\n";
 }
 
 return 0;
}