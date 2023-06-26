#include <bits/stdc++.h>
 
using namespace std;
 
#define F  first
#define S  second
#define br '\n'
#define MX 4000006
 
#define all(v) (v).begin(), (v).end()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
ll dp[MX], sum[MX];
 
int M;
 
inline void add(ll &a, ll b) {
    a += b;
    if (a >= M)
        a -= M;
}
 
inline void sub(ll &a, ll b) {
    a -= b;
    if (a < 0)
        a += M;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int n;
    while (cin >> n >> M) {
        dp[1] = 1;
        memset(sum, 0, sizeof(sum));
        ll pref = dp[1];
 
        for (int j = 2; j <= n; j++) {
            add(sum[j], dp[1]);
        }
        for (int i = 2; i <= n; i++) {
            add(sum[i], sum[i - 1]);
            dp[i] = pref;
            add(dp[i], sum[i]);
            for (int j = 2 * i; j <= n; j += i) {
                add(sum[j], dp[i]);
                sub(sum[j], dp[i - 1]);
            }
            add(pref, dp[i]);
        }
 
        cout << dp[n] << br;
    }
 
    return 0;
}