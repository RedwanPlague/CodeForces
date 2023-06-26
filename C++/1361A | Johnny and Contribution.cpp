#include <bits/stdc++.h>
 
using namespace std;
 
#define MX 35
#define MOD 1'000'000'007
#define F first
#define S second
#define invmod(x) bigmod(x,MOD-2)
#define br '\n'
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
 
    int n, m;
    while (cin >> n >> m)
    {
        vector<vi> adj(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        vector<vi> li(n);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            a--;
            li[a].push_back(i);
        }
 
        vi ans;
        bool possible = true;
        vector<int> vis(n, -1);
 
        for (int i=0; possible && i<n; i++) {
            for (int j=0; possible && j<li[i].size(); j++) {
                int v = li[i][j];
                ans.push_back(v+1);
                vis[v] = i;
                if (adj[v].size() < i) {
                    possible = false;
                    break;
                }
                vector<bool> mark(i, false);
                for (auto x: adj[v]) {
                    if (vis[x] != -1) {
                        if (vis[x] < i) {
                            mark[vis[x]] = true;
                        }
                        else if (vis[x] == i) {
                            possible = false;
                            break;
                        }
                    }
                }
                for (int k=0; k<i; k++) {
                    if (!mark[k]) {
                        possible = false;
                        break;
                    }
                }
            }
        }
 
        if(!possible) {
            cout << -1 << endl;
        }
        else {
            for (auto x: ans) {
                cout << x << ' ';
            }
            cout << endl;
        }
    }
 
    return 0;
}