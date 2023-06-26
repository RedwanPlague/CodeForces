#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 35
#define MOD 1'000'000'007
#define set(N,pos) (N = (1LL<<(pos)))
#define clear(N,pos) (N = (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<vi> adj(n);
    int u, v;
    vector<pii> edge(m);
    for(int i=0; i<m; i++)
    {
        cin >> u >> v;
        u--; v--;
        edge[i].F = u;
        edge[i].S = v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi comp(n,-1);
 
    for(int i=0; i<n; i++)
    {
        sort(all(adj[i]));
    }
 
    int cnt = 0;
    ll track[5] = {0,0,0,0,0};
    for(int i=0; i<n; i++)
    {
        if(comp[i] == -1)
        {
            cnt++;
            if(cnt > 3)
            {
                cout << -1 << endl;
                return 0;
            }
            for(int j=0; j<n; j++)
            {
                int idx = lower_bound(all(adj[i]),j) - adj[i].begin();
                if(idx >= adj[i].size() || adj[i][idx] != j)
                {
                    comp[j] = cnt;
                    track[cnt]++;
                }
            }
        }
    }
 
    if(cnt != 3)
    {
        cout << -1 << endl;
        return 0;
    }
 
    if(m != track[1]*track[2]+track[2]*track[3]+track[3]*track[1])
    {
        cout << -1 << endl;
        return 0;
    }
 
    for(int i=0; i<m; i++)
    {
        if(comp[edge[i].F] == comp[edge[i].S])
        {
            cout << -1 << endl;
            return 0;
        }
    }
 
    for(int i=0; i<n; i++)
        cout << comp[i] << ' ';
    cout << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 