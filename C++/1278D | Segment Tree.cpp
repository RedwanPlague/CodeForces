#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 105
#define MOD 1000000007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define l first
#define r second
 
void dfs(int u, const vector<vi> &adj, vector<bool> &vis)
{
    vis[u] = true;
    for(auto &v: adj[u])
    {
        if(!vis[v])
            dfs(v,adj,vis);
    }
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n;
    cin >> n;
    vi mark(2*n+1);
    vector<pii> seg(n);
    vector<vi> adj(n);
 
    for(int i=0; i<n; i++)
    {
        cin >> seg[i].l >> seg[i].r;
        mark[seg[i].l] = mark[seg[i].r] = i;
    }
 
    int edge = 0;
    set<int> ends;
    for(int i=1; edge<n && i<=2*n; i++)
    {
        int u = mark[i];
        pii cur = seg[u];
        if(cur.l == i)
        {
            for(auto &x: ends)
            {
                if(cur.r > x)
                {
                    int v = mark[x];
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                    edge++;
                    if(edge >= n)
                        break;
                    //cout << u << "(" << cur.l << "," << cur.r << ") -- " << v << "(" << nxt.l << "," << nxt.r << ")\n";
                }
                else
                    break;
            }
            ends.insert(cur.r);
        }
        else
            ends.erase(i);
    }
 
    if(edge != n-1)
    {
        cout << "NO" << endl;
        return 0;
    }
 
    vector<bool> vis(n,false);
    dfs(0,adj,vis);
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 