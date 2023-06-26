#include <bits/stdc++.h>
 
using namespace std;
 
#define br       '\n'
#define CREWMATE 0
#define IMPOSTER 1
 
using ll = long long;
 
vector<vector<pair<int, int>>> adj;
vector<int> sz, tp;
 
int dfs(const int u, const int utype) {
    sz[u] = 1;
    tp[u] = utype;
    int cnt = utype;
    for (auto &p : adj[u]) {
        int v = p.first;
        int t = p.second;
        int vtype = utype ^ t;
        if (sz[v] == -1) {
            int ret = dfs(v, vtype);
            if (ret == -1) {
                return -1;
            }
            cnt += ret;
            sz[u] += sz[v];
        }
        else if (tp[v] != vtype) {
            return -1;
        }
    }
    return cnt;
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
        int n, m;
        cin >> n >> m;
 
        adj.clear();
        adj.resize(n);
        sz.clear();
        sz.resize(n, -1);
        tp.clear();
        tp.resize(n);
 
        for (int i = 0; i < m; i++) {
            int u, v;
            string type_str;
            cin >> u >> v >> type_str;
            int type = (type_str == "crewmate") ? CREWMATE : IMPOSTER;
            u--, v--;
            adj[u].emplace_back(v, type);
            adj[v].emplace_back(u, type);
        }
 
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (sz[i] == -1) {
                int mx = dfs(i, IMPOSTER);
                if (mx == -1) {
                    total = -1;
                    break;
                }
                else {
                    total += max(mx, sz[i] - mx);
                }
            }
        }
 
        cout << total << br;
    }
 
    return 0;
}