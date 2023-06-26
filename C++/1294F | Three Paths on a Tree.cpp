#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define F first
#define S second
 
pii farthest_node(const vi &from, const vector<vi> &adj)
{
    int n = adj.size();
    vi dist(n,-1);
    queue<int> que;
    for(int x: from)
    {
        dist[x] = 0;
        que.push(x);
    }
    int mx = 0, far = from.front();
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int v: adj[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = 1 + dist[u];
                if(dist[v] > mx)
                {
                    mx = dist[v];
                    far = v;
                }
                que.push(v);
            }
        }
    }
    return {far,mx};
}
 
vi path_to_farthest_node(int from, const vector<vi> &adj)
{
    int n = adj.size();
    vi dist(n,-1), par(n);
    queue<int> que;
    dist[from] = 0;
    par[from] = -1;
    que.push(from);
 
    int mx = 0, far = from;
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int v: adj[u])
        {
            if(dist[v] == -1)
            {
                dist[v] = 1 + dist[u];
                par[v] = u;
                if(dist[v] > mx)
                {
                    mx = dist[v];
                    far = v;
                }
                que.push(v);
            }
        }
    }
 
    vi path;
    for(int cur = far; cur != -1; cur = par[cur])
        path.push_back(cur);
 
    return path;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, u, v;
    cin >> n;
    vector<vi> adj(n);
    for(int i=1; i<n; i++)
    {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    int a, b, c, tot;
    a = farthest_node({0},adj).F;
 
    vi path = path_to_farthest_node(a,adj);
    b = path.front();
    tot = path.size()-1;
 
    if(tot == n-1)
    {
        c = path[1];
    }
    else 
    {
        pii ret = farthest_node(path,adj);
        c = ret.F;
        tot += ret.S;
    }
 
    cout << tot << endl;
    cout << a+1 << ' ' << b+1 << ' ' << c+1 << endl;
    
    return 0;
}