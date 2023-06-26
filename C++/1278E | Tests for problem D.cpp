#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 105
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define l first
#define r second
#define pb push_back
 
int dfs(int u, int p, int r_start, const vector<vi> &adj, vector<pii> &seg)
{
    // cout << p << " -> " << u << endl;
    seg[u].r = r_start + adj[u].size() - (p != -1); // do not allocate for parent
    r_start = seg[u].r-1;   // the rightmost child will have the smallest l so that it encapsulates the subtrees of its left siblings and so on
    int r_last = seg[u].r; 
    for(auto &v: adj[u])
    {
        if(v != p)
        {
            seg[v].l = r_start--;
            r_last = dfs(v,u,r_last+1,adj,seg); // each node will allocate space for its children after space for its left siblings' subtree has been allocated
        }
    }
    return r_last;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n;
    cin >> n;
    vector<vi> adj(n);
    int u, v;
    for(int i=1; i<n; i++)
    {
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<pii> seg(n);
    seg[0].l = 1;
    dfs(0,-1,2,adj,seg);
 
    for(auto &sg: seg)
    {
        cout << sg.l << ' ' << sg.r << '\n';
    }
 
    return 0;
}