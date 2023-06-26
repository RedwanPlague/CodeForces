// https://codeforces.com/problemset/problem/461/B
 
#include <iostream>
#include <vector>
 
using namespace std;
 
#define MX  100005
#define MOD 1000000007
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
ll bigmod(ll base, ll pw) {
    ll ret = 1LL;
    while (pw) {
        if (pw & 1) {
            ret = ret * base % MOD;
        }
        base = base * base % MOD;
        pw >>= 1;
    }
    return ret;
}
 
#define invmod(x) bigmod(x, MOD - 2)
 
// black node taken on the last separation or not
ll taken[MX], notaken[MX];
int col[MX];
vvi adj;
 
void dfs(int u) {
    if (col[u]) {
        taken[u] = 1;
        notaken[u] = 0;
        for (auto v : adj[u]) {
            dfs(v);
            ll added = (taken[v] + notaken[v]) % MOD;
            taken[u] = taken[u] * added % MOD;
        }
    }
    else {
        taken[u] = 0;
        notaken[u] = 1;
        ll prod = 1;
        for (auto v : adj[u]) {
            dfs(v);
            ll added = (taken[v] + notaken[v]) % MOD;
            taken[u] = (taken[u] + taken[v] * invmod(added) % MOD) % MOD;
            prod = prod * added % MOD;
            notaken[u] = notaken[u] * added % MOD;
        }
        taken[u] = taken[u] * prod % MOD;
    }
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
            int p;
            cin >> p;
            adj[p].push_back(i);
        }
 
        for (int i = 0; i < n; i++) {
            cin >> col[i];
        }
 
        dfs(0);
 
        cout << taken[0] << endl;
    }
 
    return 0;
}