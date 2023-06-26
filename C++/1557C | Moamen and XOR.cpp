#include <bits/stdc++.h>
 
using namespace std;
 
#define br '\n'
#define F  first
#define S  second
 
#define MX  200005
#define MOD 1000000007
 
#define all(v) (v).begin(), (v).end()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
 
int n, k;
ll dp[MX][2];
ll n2, n1;
 
ll bigmod(ll base, ll pw) {
    ll ret = 1;
    while (pw) {
        if (pw & 1)
            ret = ret * base % MOD;
        base = base * base % MOD;
        pw >>= 1;
    }
    return ret;
}
 
ll ways(int pos, bool big) {
    if (pos == k) {
        return 1LL;
    }
    ll &ret = dp[pos][big];
    if (ret != -1) {
        return ret;
    }
 
    if (big) {
        ret = n2 * ways(pos + 1, big) % MOD;
    }
    else {
        ret = (ways(pos + 1, n % 2 == 0) + (n1 - (n % 2 == 0)) * ways(pos + 1, 0) % MOD) % MOD;
    }
    return ret;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        cin >> n >> k;
        n2 = bigmod(2, n);
        n1 = bigmod(2, n - 1);
        memset(dp, -1, sizeof(dp));
        cout << ways(0, false) << endl;
    }
 
    return 0;
}