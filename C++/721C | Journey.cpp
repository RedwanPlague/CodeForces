#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
 
#define F first
#define S second
 
using namespace std;
 
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef long long ll;
 
const int MX = 5005;
const ll INF = (1LL<<60);
 
ll dp[MX][MX];
 
ll min_cost(const int cur, const int used, const vector<vii> &adj)
{
    if(used == 1)
    {
        if(cur == adj.size()-1)
            return (dp[cur][used] = 0);
        return (dp[cur][used] = INF);
    }
    if(dp[cur][used] != -1)
        return dp[cur][used];
    ll ret = INF;
    for(int i=0; i<adj[cur].size(); i++)
    {
        int v = adj[cur][i].F;
        ll w = adj[cur][i].S;
 
        ret = min(ret, w+min_cost(v,used-1,adj));
    }
    return (dp[cur][used] = ret);
}
 
void print_path(const int cur, const ll used, const vector<vii> &adj)
{
    cout << cur+1 << " ";
    //cout << dp[cur][used] << endl;
    if(cur == adj.size()-1)
        return ;
    for(int i=0; i<adj[cur].size(); i++)
    {
        int v = adj[cur][i].F;
        ll w = adj[cur][i].S;
        if(dp[cur][used] == w+dp[v][used-1])
        {
            print_path(v,used-1,adj);
            return ;
        }
    }
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, m, u, v;
    ll t, w;
    cin >> n >> m >> t;
    vector<vii> adj(n);
    for(int i=0; i<m; i++)
    {
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back(pii(v,w));
    }
 
    memset(dp,-1,sizeof(dp));
 
    int use = n;
    while(use >= 2 && min_cost(0,use,adj) > t)
        use--;
 
    cout << use << endl;
    print_path(0,use,adj);
    cout << endl;
 
    return 0;
}