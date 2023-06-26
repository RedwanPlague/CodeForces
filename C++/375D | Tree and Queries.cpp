// https://codeforces.com/problemset/problem/375/D
 
#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define F first
#define S second
#define MX 100005
#define br '\n'
 
const int BLOCK_SIZE = 400;
 
struct Query
{
    int l, r, k, id;
    bool operator < (const Query& obj) const 
    {
        if(l/BLOCK_SIZE != obj.l/BLOCK_SIZE)
            return l < obj.l;
        return ((l/BLOCK_SIZE)&1) ? (r < obj.r) : (r > obj.r);
    }
};
 
void dfs(int u, int p, const vector<vi> &adj, vi &ucol, const vi &color, vector<pii> &range, int &use)
{
 range[u].F = ++use;
 ucol[use] = color[u];
 for(auto v: adj[u])
 {
  if(v != p)
  {
   dfs(v,u,adj,ucol,color,range,use);
  }
 }
 range[u].S = use;
}
 
class Counter
{
 int cnt[MX], suff[MX];
 vector<bool> mark;
 
public:
 
 Counter(int n)
 {
  memset(cnt,0,sizeof(cnt));
  memset(suff,0,sizeof(suff));
  mark.resize(n);
 }
 
 void add(int u, int num)
 {
  if(mark[u])
   return ;
  mark[u] = true;
  int new_cnt = ++cnt[num];
  suff[new_cnt]++;
 }
 
 void remove(int u, int num)
 {
  if(!mark[u])
   return ;
  mark[u] = false;
  int old_cnt = cnt[num]--;
  suff[old_cnt]--;
 }
 
 int getans(int k)
 {
  return suff[k];
 }
};
 
int main()
{
 ios_base::sync_with_stdio(false); cin.tie(nullptr);
 
#ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
#endif
 
    int n, m;
 while(cin >> n >> m)
 {
  vi color(n), ucol(n);
  vector<vi> adj(n);
 
  for(auto &c: color)
   cin >> c;
  
  int u, v, k;
  for(int i=1; i<n; i++)
  {
   cin >> u >> v;
   u--; v--;
   adj[u].push_back(v);
   adj[v].push_back(u);
  }
 
  int use = -1;
  vector<pii> range(n);
  dfs(0,-1,adj,ucol,color,range,use);
 
#ifndef ONLINE_JUDGE
  for(auto r: range)
   cout << '[' << r.F << ' ' << r.S << ']';
  cout << br;
#endif
 
  vector<Query> query(m);
  for(int i=0; i<m; i++)
  {
   cin >> u >> k;
   u--;
   query[i].l = range[u].F;
   query[i].r = range[u].S;
   query[i].k = k;
   query[i].id = i;
  }
  sort(query.begin(), query.end());
 
  Counter counter(n);
  vi ans(m);
  
  int cur_l = 0;
  int cur_r = -1;
  for(Query &q: query)
  {
   while(cur_l > q.l)
   {
    cur_l--;
    counter.add(cur_l,ucol[cur_l]);
   }
   while(cur_r < q.r)
   {
    cur_r++;
    counter.add(cur_r,ucol[cur_r]);
   }
   while(cur_l < q.l) 
   {
    counter.remove(cur_l,ucol[cur_l]);
    cur_l++;
   }
   while(cur_r > q.r) 
   {
    counter.remove(cur_r,ucol[cur_r]);
    cur_r--;
   }
   ans[q.id] = counter.getans(q.k);
  }
 
  for(auto x: ans)
   cout << x << br;
 }
 
    return 0;
}