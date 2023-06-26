#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
 
#define pb push_back
#define br '\n'
 
const int MX = 1000005;
int n, limit;
 
vector <int> adj[MX];
int rnk[MX];
bool take[MX];
int par[MX][20];
 
void bfs(int src)
{
    memset(rnk, -1, sizeof(rnk));
    memset(par, -1, sizeof(par));
    queue <int> que;
    que.push(src);
    rnk[src] = 0;
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int i=0; i<adj[u].size(); i++)
        {
            int &v = adj[u][i];
            if(rnk[v] == -1)
            {
                par[v][0] = u;
                rnk[v] = 1 + rnk[u];
                que.push(v);
            }
        }
    }
    for(int j=1; j<limit; j++)
    {
        for(int i=1; i<=n; i++)
        {
            if(par[i][j-1] != -1)
                par[i][j] = par[par[i][j-1]][j-1];
            //cout<<par[i][j]<<' ';
        }
        //cout<<br;
    }
}
 
int path(int cur)
{
    int till = 1; // the node itself
    for(int pos = limit-1; pos >= 0; pos--)
    {
        if(par[cur][pos] != -1 && !take[par[cur][pos]])
        {
            cur = par[cur][pos];
            till += (1<<pos);
        }
    }
    return till;
}
 
void visit(int cur)
{
    while(par[cur][0] != -1 && !take[cur])
    {
        take[cur] = 1;
        cur = par[cur][0];
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int k, u, v;
    cin>>n>>k;
 
    limit = 0;
    while(n>>limit)
        limit++;
 
    for(int i=0; i<n-1; i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    bfs(n);
 
    memset(take, 0, sizeof(take));
    take[n] = 1;
    int taken = 1;
    for(int i=n-1; i>=1; i--)
    {
        if(take[i])
            continue;
        int till = path(i);
        //cout<<"till "<<till<<br;
        if(taken + till <= n - k)
        {
            visit(i);
            taken += till;
        }
    }
 
    for(int i=1; i<=n; i++)
        if(!take[i])
            cout<<i<<' ';
    cout<<endl;
 
    return 0;
}