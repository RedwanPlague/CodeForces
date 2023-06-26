#include <bits/stdc++.h>
 
using namespace std;
 
#define br '\n'
#define F  first
#define S  second
#define MX 100005
 
#define all(v) (v).begin(), (v).end()
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n), b(n);
        ll sa = 0, sb;
        for (auto &x : a) {
            cin >> x;
            sa += x;
        }
        for (auto &x : b) {
            cin >> x;
        }
        sa -= a[0];
        sb = 0;
        ll ans = max(sa, sb);
        for (int i = 1; i < n; i++) {
            sa -= a[i];
            sb += b[i - 1];
            ans = min(ans, max(sa, sb));
        }
 
        cout << ans << br;
    }
 
    return 0;
}