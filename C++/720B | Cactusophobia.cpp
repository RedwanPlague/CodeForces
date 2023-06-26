#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
 
#define F first
#define S second
 
namespace dinic 
{
 // Dinic's Max Flow
 // Complexity=  O(|E|*|V|^2) , but much faster
 // 
 // INPUT:
 //     - At first , Call reset();    
 //     - graph, constructed using addEdge()
 //     - S = source and T = sink
 //
 // OUTPUT:
 //     - maximum flow value
 //     - To obtain flow values of each edge, (Original_cap[edge_i] - Obtained_cap[edge_i] )
 //       (zero capacity edges are residual edges).
 //
 // change the value of MAX_E & MAX_V as needed
 //
 
 
 const int MAX_E=100003;
 const int MAX_V=100003;
 int ver[MAX_E],cap[MAX_E],nx[MAX_E],last[MAX_V],ds[MAX_V],st[MAX_V],now[MAX_V],edge_count,S,T;
 
 
 void reset()
 {
  memset(nx,-1,sizeof(nx));
  memset(last,-1,sizeof(last));
  edge_count=0;
 }
 
 
 // Set reverse capacity 0 for directed edge
 void addedge(const int v,const int w,const int capacity,const int reverse_capacity)
 {
#ifndef ONLINE_JUDGE
  printf("%d ----%d---> %d\n", v, capacity, w);
#endif
  ver[edge_count]=w; cap[edge_count]=capacity; nx[edge_count]=last[v]; last[v]=edge_count++;
  ver[edge_count]=v; cap[edge_count]=reverse_capacity; nx[edge_count]=last[w]; last[w]=edge_count++;
 }
 
 bool bfs()
 {
  memset(ds,-1,sizeof(ds));
  int a,b;
  a=b=0;
  st[0]=T;
  ds[T]=0;
  while (a<=b)
  {
   int v=st[a++];
   for (int w=last[v];w>=0;w=nx[w])
   {
    if (cap[w^1]>0 && ds[ver[w]]==-1)
    {
     st[++b]=ver[w];
     ds[ver[w]]=ds[v]+1;
    }
   }
  }
  return ds[S]>=0;
 }
 
 int dfs(int v,int cur)
 {
  if (v==T) return cur;
  for (int &w=now[v];w>=0;w=nx[w])
  {
   if (cap[w]>0 && ds[ver[w]]==ds[v]-1)
   {
    int d=dfs(ver[w],min(cur,cap[w]));
    if (d)
    {
     cap[w]-=d;
     cap[w^1]+=d;
     return d;
    }
   }
  }
  return 0;
 }
 
 long long flow()
 {
  long long res=0;
  while (bfs())
  {
   for (int i=0;i<MAX_V;i++) now[i]=last[i];
   while (1)
   {
    int tf=dfs(S,INF);
    res+=tf;
    if (!tf) break;
   }
  }
  return res;
 }
}
 
 
struct Edge
{
 int to, color, id;
 Edge() {}
 Edge(int t, int c, int i) : to(t), color(c), id(i) {}
};
typedef vector<Edge> ve;
 
void make_cycle(int from, const Edge &e, vector<vi> &blocks, vector<bool> &emark, vector<Edge> &par)
{
 int cur = from;
 blocks.emplace_back();
 blocks.back().emplace_back(e.color);
 emark[e.id] = true;
 while(cur != e.to)
 {
  blocks.back().emplace_back(par[cur].color);
  emark[par[cur].id] = true;
  cur = par[cur].to;
 }
}
 
void dfs(int cur, int p, const vector<ve> &adj, vector<vi> &blocks, vector<bool> &emark, vi &vis, vector<Edge> &par)
{
 vis[cur] = 1;
 for(auto &e: adj[cur])
 {
  if(vis[e.to] == 0)
  {
   par[e.to] = e;
   par[e.to].to = cur;
   dfs(e.to,cur,adj,blocks,emark,vis,par);
  }
  else if(e.to != p && vis[e.to] == 1)
  {
   make_cycle(cur,e,blocks,emark,par);
  }
 }
 vis[cur] = 2;
}
 
void dfs_fix(int cur, const vector<ve> &adj, vector<vi> &blocks, vector<bool> &emark, vi &vis)
{
 vis[cur] = 1;
 for(auto &e: adj[cur])
 {
  if(!emark[e.id])
  {
   blocks.emplace_back();
   blocks.back().emplace_back(e.color);
   emark[e.id] = true;
  }
  if(vis[e.to] == 0)
  {
   dfs_fix(e.to,adj,blocks,emark,vis);
  }
 }
}
 
int main()
{
#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
#endif
 
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF)
 {
  vector<ve> adj(n);
  int u, v, c;
  for(int i=0; i<m; i++)
  {
   scanf("%d %d %d", &u, &v, &c);
   u--; v--;
   adj[u].push_back({v,c,i});
   adj[v].push_back({u,c,i});
  }
  vector<vi> blocks;
  vector<bool> emark(m);
  vi vis(n);
  vector<Edge> par(n);
 
  dfs(0,-1,adj,blocks,emark,vis,par);
  vis.assign(n,0);
  dfs_fix(0,adj,blocks,emark,vis);
 
#ifndef ONLINE_JUDGE
  for(auto &block: blocks)
  {
   printf("block: ");
   for(auto &x: block)
   {
    printf("%d ", x);
   }
   putchar('\n');
  }
#endif
 
  dinic::reset();
  int use = 0;
  dinic::S = use++;
  use += m;
  for(auto &block: blocks)
  {
   dinic::addedge(dinic::S,use,max(1,(int)block.size()-1),0);
   for(auto &x: block)
   {
    dinic::addedge(use,x,1,0);
   }
   use++;
  }
  dinic::T = use;
  for(int i=1; i<=m; i++)
  {
   dinic::addedge(i,dinic::T,1,0);
  }
 
  printf("%d\n", (int)dinic::flow());
 }
 
    return 0;
}