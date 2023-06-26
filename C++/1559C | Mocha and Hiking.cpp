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
 
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto &x : a) {
        cin >> x;
    }
 
    for (int i = 1; i < n; i++) {
        if (a[i - 1] == 0 && a[i] == 1) {
            for (int j = 1; j <= i; j++) {
                cout << j << ' ';
            }
            cout << n + 1 << ' ';
            for (int j = i + 1; j <= n; j++) {
                cout << j << ' ';
            }
            cout << br;
            return;
        }
    }
 
    if (a[n - 1] == 0) {
        for (int j = 1; j <= n; j++) {
            cout << j << ' ';
        }
        cout << n + 1 << br;
    }
    else {
        cout << n + 1 << ' ';
        for (int j = 1; j <= n; j++) {
            cout << j << ' ';
        }
        cout << br;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int T = 1;
    cin >> T; // if no testcase, comment this out
    for (int i = 1; i <= T; i++) {
        solve();
    }
 
    return 0;
}