#include <bits/stdc++.h>
 
using namespace std;
 
#define br '\n'
#define F  first
#define S  second
 
#define MX  100005
#define MOD 1000000007
 
#define all(v) (v).begin(), (v).end()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
    for (int cs = 1; cs <= T; cs++) {
        int n;
        cin >> n;
        vi a(n);
        ll sum = 0;
        for (auto &x : a) {
            cin >> x;
            sum += x;
        }
        sort(all(a));
        ll mx = a.back();
        cout << fixed << setprecision(9) << mx + (sum - mx + 0.0) / (n - 1) << br;
    }
 
    return 0;
}