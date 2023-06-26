#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int,int> pii;
 
int k = 1;
 
void dfs(int u, vector< vector<pii> > &adj, vector<int> &vis, vector<int> &color)
{
    vis[u] = 1;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i].first;
        /*printf("-> %d %d = ", u, v);
        for(int i=0; i<color.size(); i++)
            printf("%d ", color[i]);
        puts("");*/
        if(vis[v] == 1)
        {
            color[adj[u][i].second] = 2;
            k = 2;
        }
        else if(vis[v] == 0)
        {
            color[adj[u][i].second] = 1;
            dfs(v,adj,vis,color);
        }
        else if(vis[v] == 2)
        {
            color[adj[u][i].second] = 1;
        }
    }
    vis[u] = 2;
}
 
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector< vector<pii> > adj(n);
    vector<int> vis(n,0);
    for(int i=0; i<m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(pii(v,i));
    }
    vector<int> color(m);
    for(int i=0; i<n; i++)
        if(vis[i] == 0)
            dfs(i,adj,vis,color);
    printf("%d\n", k);
    for(int i=0; i<m; i++)
        printf("%d ", color[i]);
    puts("");
    return 0;
}