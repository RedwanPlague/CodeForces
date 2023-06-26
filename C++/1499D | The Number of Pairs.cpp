#include <bits/stdc++.h>
#include <ctime>
 
using namespace std;
 
#define MOD 1000000007
#define F first
#define S second
#define br '\n'
#define all(v) (v).begin(),(v).end()
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
 
const int N = 20000005;
 
vector<bool> mark(N, false);
int pcnt[N];
 
void sieve() {
    pcnt[1] = 0;
    for (int i=2; i<N; i+=2) {
        pcnt[i]++;
    }
    for (int i=3; i<N; i+=2) {
        if (!mark[i]) {
            for (int j=i; j<N; j+=i) {
                mark[j] = true;
                pcnt[j]++;
            }
        }
    }
}
 
 
int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
 
    sieve();
 
    int T;
    cin >> T;
    while (T--) {
        ll c, d, x;
        cin >> c >> d >> x;
        ll ans = 0;
        for (ll i=1; i*i <= x; i++) {
            if (x % i == 0) {
                ll dv1 = i, dv2 = x / i;
                if ((dv1 + d) % c == 0) {
                    ans += (1LL << pcnt[(dv1 + d)/c]);
                }
                if (dv2 != dv1 && ((dv2 + d) % c == 0)) {
                    ans += (1LL << pcnt[(dv2 + d)/c]);
                }
            }
        }
        cout << ans << br;
    }
 
    return 0;
}
 