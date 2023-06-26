#include <bits/stdc++.h>
 
using namespace std;
 
#define br '\n'
 
#ifdef REDWAN
#define dump(x) cerr << #x << " = " << x << endl
#else
#define dump(x)
#endif
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int n, m;
    while (cin >> n >> m) {
        vi large(n, 0);
        int stay = n;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            if (u > v) {
                swap(u, v);
            }
            if (large[u] == 0) {
                stay--;
            }
            large[u]++;
        }
 
        int q;
        cin >> q;
        while (q--) {
            int op;
            cin >> op;
            if (op == 1) {
                int u, v;
                cin >> u >> v;
                u--, v--;
                if (u > v) {
                    swap(u, v);
                }
                if (large[u] == 0) {
                    stay--;
                }
                large[u]++;
            }
            else if (op == 2) {
                int u, v;
                cin >> u >> v;
                u--, v--;
                if (u > v) {
                    swap(u, v);
                }
                large[u]--;
                if (large[u] == 0) {
                    stay++;
                }
            }
            else if (op == 3) {
                cout << stay << br;
            }
        }
    }
 
    return 0;
}