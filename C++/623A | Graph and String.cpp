#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
 
using namespace std;
 
typedef vector<int> vi;
 
bool bfs(const int src, const vector<vi> &adj, vi &color)
{
    color[src] = 0;
    queue<int> que;
    que.push(src);
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(color[v] == -1)
            {
                color[v] = 2 - color[u];
                que.push(v);
            }
            else if(color[v] == color[u])
                return false;
        }
    }
    return true;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, m, u, v;
    cin >> n >> m;
 
    vector<vi> adj(n);
    vector<vi> mark(n,vi(n,0));
    for(int i=0; i<m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        mark[u][v] = mark[v][u] = 1;
    }
 
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(!mark[i][j])
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
 
    vi color(n,-1);
    bool found = false;
 
    for(int i=0; i<n; i++)
    {
        if(color[i] == -1)
        {
            if(adj[i].size() == 0)
            {
                color[i] = 1;
            }
            else if(found)
            {
                cout << "No" << endl;
                return 0;
            }
            else
            {
                if(!bfs(i,adj,color))
                {
                    cout << "No" << endl;
                    return 0;
                }
                found = true;
            }
        }
    }
 
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(color[i] != 1 && color[i]+color[j] == 2 && mark[i][j])
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
 
    cout << "Yes\n";
    for(int i=0; i<n; i++)
        cout << (char)(color[i]+'a');
    cout << endl;
 
    return 0;
}