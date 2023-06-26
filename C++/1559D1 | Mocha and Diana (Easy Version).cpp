#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
 
using namespace std;
using namespace __gnu_pbds;
 
using ost_type = int;
using ordered_set =
    tree<ost_type, null_type, less<ost_type>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k) --> returns iterator to the kth largest element counting from 0
// order_of_key(val) --> returns the number of items in a set that are strictly smaller than our
// item
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// to generate a uniform random integer over a range [l,r], use
// int x = uniform_int_distribution<int>(l,r)(rng);
 
#define br '\n'
#define F  first
#define S  second
 
#define MX  100005
#define MOD 1000000007
 
#define all(v) (v).begin(), (v).end()
 
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
 
int pa[MX], pb[MX], sa[MX], sb[MX];
 
int getpar(int u, int *p) {
    if (p[u] == u) {
        return u;
    }
    return (p[u] = getpar(p[u], p));
}
 
bool unite(int u, int v, int *p, int *s) {
    int pu = getpar(u, p);
    int pv = getpar(v, p);
    if (pu == pv) {
        return false;
    }
 
    if (s[pu] > s[pv]) {
        s[pu] += s[pv];
        p[pv] = p[pu];
    }
    else {
        s[pv] += s[pu];
        p[pu] = p[pv];
    }
    return true;
}
 
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
 
    for (int i = 0; i < n; i++) {
        pa[i] = pb[i] = i;
        sa[i] = sb[i] = 1;
    }
 
    for (int i = 0; i < a; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        unite(u, v, pa, sa);
    }
    for (int i = 0; i < b; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        unite(u, v, pb, sb);
    }
 
    vector<pii> add;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (getpar(j, pa) != getpar(i, pa) && getpar(j, pb) != getpar(i, pb)) {
                unite(i, j, pa, sa);
                unite(i, j, pb, sb);
                add.emplace_back(i, j);
            }
        }
    }
 
    cout << add.size() << br;
    for (auto x : add) {
        cout << x.F + 1 << ' ' << x.S + 1 << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int T = 1;
    /* cin >> T; // if no testcase, comment this out */
    for (int i = 1; i <= T; i++) {
        solve();
    }
 
    return 0;
}