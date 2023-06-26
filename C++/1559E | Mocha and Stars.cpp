#include <bits/stdc++.h>
 
using namespace std;
 
#define br '\n'
#define F  first
#define S  second
 
#define MX  100005
#define MOD 998244353
 
#define all(v) (v).begin(), (v).end()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
ll dp[MX], psum[MX], contrib[MX];
 
void up(ll &x) {
    if (x < 0) {
        x += MOD;
    }
}
 
void down(ll &x) {
    if (x >= MOD) {
        x -= MOD;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int n, m;
    cin >> n >> m;
    vi l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }
 
    for (int g = m; g >= 1; g--) {
        int mg = m / g;
 
        psum[0] = 0;
        for (int j = 0; j <= mg; j++) {
            dp[j] = 1;
            psum[j + 1] = psum[j] + dp[j];
        }
 
        for (int i = 0; i < n; i++) {
            int lg = (l[i] - 1) / g + 1, rg = r[i] / g;
            for (int j = 0; j <= mg; j++) {
                dp[j] = psum[max(0, j - lg + 1)] - psum[max(0, j - rg)];
                up(dp[j]);
            }
            psum[0] = 0;
            for (int j = 0; j <= mg; j++) {
                psum[j + 1] = psum[j] + dp[j];
                down(psum[j + 1]);
            }
        }
 
        contrib[g] = dp[mg];
        for (int k = 2 * g; k <= m; k += g) {
            contrib[g] -= contrib[k];
            up(contrib[g]);
        }
    }
 
    cout << contrib[1] << endl;
 
    return 0;
}