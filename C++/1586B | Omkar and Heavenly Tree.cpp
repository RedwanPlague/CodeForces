#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using vi = vector<int>;
 
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
        vector<bool> used(n + 1, false);
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            used[b] = true;
        }
        int center = -1;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                center = i;
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (i != center) {
                cout << i << ' ' << center << '\n';
            }
        }
    }
 
    return 0;
}