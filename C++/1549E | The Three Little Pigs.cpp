#include <bits/stdc++.h>
 
using namespace std;
 
#define br  '\n'
#define MOD 1000000007
#define MX  3000006
 
#ifdef REDWAN
#define dump(x) cerr << #x << " = " << x << endl
#else
#define dump(x)
#endif
 
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
 
ll fact[MX], invfact[MX];
 
ll C(int n, int r) { return n < r ? 0 : (fact[n] * invfact[r] % MOD) * invfact[n - r] % MOD; }
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    clock_t start = clock();
    fact[0] = 1LL;
    for (int i = 1; i < MX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    invfact[MX - 1] = bigmod(fact[MX - 1], MOD - 2);
    for (int i = MX - 2; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
 
    int n, q;
    while (cin >> n >> q) {
        int N = 3 * n + 3;
        vector<ll> lob(N + 1), hor(3 + 1);
        hor[0] = 0;
        hor[1] = 3;
        hor[2] = 3;
        hor[3] = 1;
 
        /* lob[0] = 1; */
        /* for (int i = 1; i <= N; i++) { */
        /*     lob[i] = (lob[i - 1] * (N - i + 1) % MOD) * bigmod(i, MOD - 2) % MOD; */
        /* } */
        for (int i = 0; i <= N; i++) {
            lob[i] = C(N, i);
        }
        lob[0] = 0;
        for (int i = 1; i < 4; i++) {
            lob[i] -= hor[i];
        }
 
        vector<ll> p(N - 2);
        for (int i = N; i >= 3; i--) {
            ll coeff = lob[i] / hor[3];
            p[i - 3] = coeff;
            for (int j = i, k = 3; k >= 0; j--, k--) {
                lob[j] = (lob[j] - coeff * hor[k] % MOD) % MOD;
                if (lob[j] < 0) {
                    lob[j] += MOD;
                }
            }
        }
 
        while (q--) {
            int x;
            cin >> x;
            cout << p[x] << br;
        }
    }
 
    clock_t end = clock();
    cerr << 1e3 * (end - start + 0.0) / CLOCKS_PER_SEC << "ms" << br;
 
    return 0;
}