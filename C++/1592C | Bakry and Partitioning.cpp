#include <bits/stdc++.h>
#include <climits>
 
using namespace std;
 
#define br '\n'
#define MX 100005
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
 
int a[MX], xr[MX], par[MX];
bool vis[MX];
vvi adj;
stack<int> order;
 
void dfs(const int u, const int p) {
    par[u] = p;
    xr[u] = a[u];
    order.push(u);
    for (auto v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            xr[u] ^= xr[v];
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
 
        adj.clear();
        adj.resize(n);
 
        int all_xr = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            all_xr ^= a[i];
        }
 
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        if (all_xr == 0) {
            cout << "YES" << br;
            continue;
        }
        else if (k == 2) {
            cout << "NO" << br;
            continue;
        }
 
        dfs(0, -1);
 
        memset(vis, false, n * sizeof(bool));
 
        bool found = false;
 
        while (!order.empty()) {
            int u = order.top();
            order.pop();
            if (!vis[u] && xr[u] == all_xr) {
                int v = par[u];
                while (v != -1) {
                    if (xr[v] == 0) {
                        found = true;
                        break;
                    }
                    else if (vis[v]) {
                        found = true;
                        break;
                    }
                    vis[v] = true;
                    v = par[v];
                }
            }
        }
 
        cout << (found ? "YES" : "NO") << br;
    }
 
    return 0;
}