// https://codeforces.com/contest/321/problem/C
 
#include <cstring>
#include <iostream>
#include <vector>
 
using namespace std;
 
#define MX 100005
 
#define all(v) (v).begin(), (v).end()
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
vvi adj;
int sz[MX];
char rnk[MX];
bool on[MX];
 
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
 
void centroid_finder(int u, int p, int root, char use);
 
void use_centroid(int u, char use) {
    rnk[u] = use;
 
    // erase u (centroid) from graph
    on[u] = false;
 
    // initiate centroid searching again from children
    for (auto v : adj[u]) {
        if (on[v]) {
            getsz(v, u);
            centroid_finder(v, u, v, use + 1);
        }
    }
}
 
void centroid_finder(int u, int p, int root, char use) {
    for (auto v : adj[u]) {
        if (on[v] && v != p) {
            if (sz[v] > sz[root] / 2) {
                // centroid is on this subtree
                return centroid_finder(v, u, root, use);
            }
        }
    }
    // centroid found, use it
    use_centroid(u, use);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int n;
 
    while (cin >> n) {
        adj.clear();
        adj.resize(n);
 
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
 
        memset(on, true, sizeof(on));
 
        getsz(0, -1);
        centroid_finder(0, -1, 0, 'A');
 
        for (int i = 0; i < n; i++) {
            cout << rnk[i] << ' ';
        }
        cout << '\n';
    }
 
    return 0;
}