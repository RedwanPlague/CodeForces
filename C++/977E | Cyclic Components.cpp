#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
 
#define MX 200005
#define MOD 1000000007
#define pb push_back
#define br '\n'
 
int cnt;
bool vis[MX];
vector <int> adj[MX];
vector <int> e[MX];
 
void dfs(int src)
{
    //cout<<src<<' ';
    vis[src] = 1;
    e[cnt].pb(src);
    for(int i=0; i<adj[src].size(); i++)
    {
        if(!vis[adj[src][i]])
            dfs(adj[src][i]);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
 
    int n, m, u, v;
    cin>>n>>m;
 
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
 
    for(int i=1; i<=n; i++)
    {
        //cout<<endl;
        if(!vis[i])
        {
            dfs(i);
            cnt++;
        }
    }
 
    int ans = 0;
 
    for(int i=0; i<cnt; i++)
    {
        bool valid = true;
        for(int j=0; j<e[i].size(); j++)
        {
            if(adj[e[i][j]].size() != 2)
            {
                valid = false;
                break;
            }
        }
        if(valid)
            ans++;
    }
 
    cout<<ans<<br;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 