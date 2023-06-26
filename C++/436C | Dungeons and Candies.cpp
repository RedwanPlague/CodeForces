#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
 
struct Edge
{
    int from, to;
    ll weight;
    Edge() {}
    Edge(int u, int v, ll w) : from(u), to(v), weight(w) {}
    bool operator<(const Edge &other)
    {
        return (weight < other.weight);
    }
};
 
class Cluster
{
    int *par, *siz;
 
public:
 
    Cluster(const int n)
    {
        par = new int[n];
        siz = new int[n];
        for(int i=0; i<n; i++)
        {
            par[i] = i;
            siz[i] = 1;
        }
    }
 
    ~Cluster()
    {
        delete[] par;
        delete[] siz;
    }
 
    int find_set(int r)
    {
        if(r == par[r])
            return r;
        return (par[r] = find_set(par[r]));
    }
 
    void unite(const int u, const int v)
    {
        int up = find_set(u);
        int vp = find_set(v);
        if(up == vp)
            return ;
        if(siz[up] > siz[vp])
        {
            par[vp] = up;
            siz[up] += siz[vp];
        }
        else
        {
            par[up] = vp;
            siz[vp] += siz[up];
        }
    }
 
};
 
typedef vector<string> vs;
typedef vector<int> vi;
 
int n, m;
 
int diff(const vs &a, const vs &b)
{
    int cnt = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i][j] != b[i][j])
                cnt++;
        }
    }
    return cnt;
}
 
void BFS(const int src, const vector<vi> &adj)
{
    int N = adj.size();
    vector<bool> vis(N,false);
    vis[src] = true;
    queue<int> que;
    que.push(src);
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(!vis[v])
            {
                cout << v << ' ' << u << '\n';
                vis[v] = true;
                que.push(v);
            }
        }
    }
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int K, W;
    cin >> n >> m >> K >> W;
 
    vector<vs> grid(K, vs(n));
 
    for(int k=0; k<K; k++)
    {
        for(int i=0; i<n; i++)
        {
            cin >> grid[k][i];
        }
    }
 
    int src = 0;
    ll init = n*m;
 
    vector<Edge> edge;
    for(int i=1; i<=K; i++)
        edge.push_back(Edge(src,i,init));
    for(int i=0; i<K; i++)
    {
        for(int j=i+1; j<K; j++)
        {
            edge.push_back(Edge(i+1,j+1,W*diff(grid[i],grid[j])));
        }
    }
    sort(edge.begin(), edge.end());
 
    Cluster cls(K+1); // including the dummy source
    int cnt = 0;
    ll sum = 0;
    vector<vi> adj(K+1);
 
    for(int i=0; i<edge.size() && cnt <= K; i++)
    {
        int u = edge[i].from;
        int v = edge[i].to;
        ll w = edge[i].weight;
        if(cls.find_set(u) != cls.find_set(v))
        {
            cls.unite(u,v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            cnt++;
            sum += w;
        }
    }
 
    cout << sum << '\n';
    BFS(src,adj);
 
    return 0;
}