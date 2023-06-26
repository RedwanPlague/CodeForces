#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef vector<int> vi;
 
void dfs(const int cur, const vector<vi> &adj, vi &subtree)
{
    if(adj[cur].size() == 0)
    {
        subtree[cur] = 1;
        return ;
    }
    int ret = 0;
    for(int i=0; i<adj[cur].size(); i++)
    {
        int v = adj[cur][i];
        dfs(v,adj,subtree);
        ret += subtree[v];
    }
    subtree[cur] = ret;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #endif
 
    int n, p;
    cin >> n;
    vector<vi> adj(n);
 
    for(int i=1; i<n; i++)
    {
        cin >> p;
        p--;
        adj[p].push_back(i);
    }
 
    vi subtree(n);
    dfs(0,adj,subtree); // should always return n
 
    sort(subtree.begin(), subtree.end());
 
    for(int i=0; i<n; i++)
    {
        cout << subtree[i] << ' ';
    }
    cout << endl;
 
    return 0;
}