#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef vector<int> vi;
 
#define INF 1000000
#define end(cur,i) (edge[i].u + edge[i].v - cur)
 
struct Triple
{
    int u, v, w;
    Triple() : w(0) {}
};
 
bool update(int cur, const int &dest, const int &w, const vector<vi> &adj, vector<Triple> &edge, vi &vis, const int &mark)
{
    if(cur == dest)
    {
        // printf("\n%d ", cur+1);
        return true;
    }
 
    vis[cur] = mark;
    for(auto &id: adj[cur])
    {
        int v = end(cur,id);
        if(vis[v] != mark)
        {
            if(update(v,dest,w,adj,edge,vis,mark))
            {
                edge[id].w = max(edge[id].w, w);
                // printf("<- %d ", cur+1);
                return true;
            }
        }
    }
    return false;
}
 
int get_min(int cur, const int &dest, const vector<vi> &adj, const vector<Triple> &edge, vi &vis, const int &mark)
{
    if(cur == dest)
    {
        // printf("\n[%d,%d] ", cur+1, INF);
        return INF;
    }
    
    vis[cur] = mark;
    for(auto &id: adj[cur])
    {
        int v = end(cur,id);
        if(vis[v] != mark)
        {
            int mn = get_min(v,dest,adj,edge,vis,mark);
            if(mn != -1)
            {
                // printf("<- (%d,%d) ", cur+1, min(mn,edge[id].w));
                return min(mn,edge[id].w);
            }
        }
    }
    return -1;
}
 
int main()
{
    int n, u, v, w, m;
    scanf("%d", &n);
    vector<vi> adj(n);
    vector<Triple> edge(n-1);
    for(int i=0; i<n-1; i++)
    {
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(i);
        adj[v].push_back(i);
        edge[i].u = u;
        edge[i].v = v;
    }
 
    scanf("%d", &m);
    vector<Triple> path(m);
    vi vis(n);
    int mark = 0;
    for(auto &p: path)
    {
        scanf("%d %d %d", &u, &v, &w);
        p.u = u-1;
        p.v = v-1;
        p.w = w;
        mark++;
        update(p.u,p.v,p.w,adj,edge,vis,mark);
    }
 
    // putchar('\n');
    for(auto &e: edge)
    {
        if(e.w == 0)
            e.w = INF;
        // printf("%d ", e.w);
    }
    // putchar('\n');
 
    bool ok = true;
    for(auto &p: path)
    {
        mark++;
        int mn = get_min(p.u,p.v,adj,edge,vis,mark);
        if(mn != p.w)
        {
            ok = false;
            break;
        }
    }
 
    if(!ok)
        puts("-1");
    else
    {
        for(auto &e: edge)
            printf("%d ", e.w);
        putchar('\n');
    }
    
}