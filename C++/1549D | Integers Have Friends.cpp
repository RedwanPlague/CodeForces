#include <bits/stdc++.h>
 
using namespace std;
 
#define br '\n'
#define MX 300005
#define LG 18
 
typedef long long ll;
 
ll a[MX], jump[MX][LG];
 
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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        a[n] = a[n - 1] - 1;
        for (int i = 0; i < n; i++) {
            jump[i][0] = abs(a[i + 1] - a[i]);
        }
        for (int j = 1, len = 1; j < LG; j++, len <<= 1) {
            for (int i = 0; i < n; i++) {
                jump[i][j] = gcd(jump[i][j - 1], jump[i + len][j - 1]);
            }
        }
        int mx = 1;
        for (int i = 0; i < n; i++) {
            int k = i;
            ll g = 0;
            for (int j = LG - 1; j >= 0; j--) {
                if (gcd(g, jump[k][j]) > 1) {
                    g = gcd(g, jump[k][j]);
                    k += 1 << j;
                }
            }
            mx = max(mx, k - i + 1);
        }
        cout << mx << br;
    }
 
    return 0;
}