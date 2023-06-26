// https://codeforces.com/contest/342/problem/E
 
#include <cstring>
#include <iostream>
#include <vector>
 
using namespace std;
 
#define MX  100005
#define LG  17
#define INF 1000000007
 
#define all(v) (v).begin(), (v).end()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
vvi adj;
int sz[MX];
bool on[MX];
 
int depth[MX];  // depth in actual tree
int tin[MX];    // in time of dfs
int tout[MX];   // out time of dfs
int timer;      // used to count time
int up[MX][LG]; // ancestors in actual tree (sparse table for lca)
int par[MX];    // parent in centroid tree
int red[MX];    // closest red node in subtree (including self)
int reddi[MX];  // distance to closest red node in subtree (including self)
 
void dfs(int u, int p) {
    tin[u] = timer++;
    up[u][0] = p;
    for (int i = 1; i < LG; i++) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (auto v : adj[u]) {
        if (v != p) {
            depth[v] = 1 + depth[u];
            dfs(v, u);
        }
    }
    tout[u] = timer++;
}
 
bool is_ancestor(int a, int b) { return tin[a] <= tin[b] && tout[b] <= tout[a]; }
 
int lca(int u, int v) {
    if (is_ancestor(u, v)) {
        return u;
    }
    if (is_ancestor(v, u)) {
        return v;
    }
    for (int i = LG - 1; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}
 
int distance(int u, int v) {
    int l = lca(u, v);
    return depth[u] + depth[v] - 2 * depth[l];
}
 
// calculates subtree size
void getsz(int u, int p) {
    sz[u] = 1;
    for (auto v : adj[u]) {
        if (on[v] && v != p) {
            getsz(v, u);
            sz[u] += sz[v];
        }
    }
}
 
void centroid_finder(int u, int p, int root, int prev);
 
void use_centroid(int u, int prev) {
    par[u] = prev;
 
    // erase u (centroid) from graph
    on[u] = false;
 
    // initiate centroid searching again from children
    for (auto v : adj[u]) {
        if (on[v]) {
            getsz(v, u);
            centroid_finder(v, u, v, u);
        }
    }
}
 
void centroid_finder(int u, int p, int root, int prev) {
    for (auto v : adj[u]) {
        if (on[v] && v != p) {
            if (sz[v] > sz[root] / 2) {
                // centroid is on this subtree
                return centroid_finder(v, u, root, prev);
            }
        }
    }
    // centroid found, use it
    use_centroid(u, prev);
}
 
void make_red(int u) {
    for (int v = u; v != -1; v = par[v]) {
        int d = distance(v, u);
        if (red[v] == -1 || d < reddi[v]) {
            red[v] = u;
            reddi[v] = d;
        }
    }
}
 
int find_red(int u) {
    int mn = INF;
    for (int v = u; v != -1; v = par[v]) {
        if (red[v] != -1) {
            int d = distance(red[v], u);
            mn = min(mn, d);
        }
    }
    return mn;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int n, m;
    cin >> n >> m;
 
    adj.resize(n);
 
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    timer = 0;
    depth[0] = 0;
    dfs(0, 0);
 
    memset(on, true, sizeof(on));
    memset(red, -1, sizeof(red));
 
    getsz(0, -1);
    centroid_finder(0, -1, 0, -1);
 
    make_red(0);
 
    while (m--) {
        int t, u;
        cin >> t >> u;
        u--;
        switch (t) {
        case 1: make_red(u); break;
        case 2: cout << find_red(u) << '\n'; break;
        }
    }
 
    return 0;
}