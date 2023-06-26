#include <bits/stdc++.h>
 
using namespace std;
 
#define MX 35
#define MOD 1'000'000'007
#define F first
#define S second
#define invmod(x) bigmod(x,MOD-2)
#define br '\n'
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
void dfs(int u, const vector<vi> &adj, vi &dist, vi &sz)
{
 sz[u] = 1;
 for(auto v: adj[u])
 {
  if(sz[v] == -1)
  {
   dist[v] = 1 + dist[u];
   dfs(v,adj,dist,sz);
   sz[u] += sz[v];
  }
 }
}
 
int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
#endif
 
 int n, k;
 while(cin >> n >> k)
 {
  int u, v;
  vector<vi> adj(n);
  vi dist(n), sz(n,-1);
  priority_queue<pii> pq;
  for(int i=1; i<n; i++)
  {
   cin >> u >> v;
   u--; v--;
   adj[u].push_back(v);
   adj[v].push_back(u);
  }
  dfs(0,adj,dist,sz);
  for(int i=0; i<n; i++)
  {
   dist[i] -= sz[i]-1;
   pq.push({dist[i],i});
  }
  ll sum = 0;
  while(k && !pq.empty())
  {
   pii tp = pq.top();
   pq.pop();
   if(dist[tp.S] != tp.F)
    continue;
   sum += tp.F;
   // cout << tp.S+1 << " -> " << tp.F << br;
   k--;
  }
  cout << sum << br;
 }
 
 return 0;
}