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
        int n, k;
        cin >> n >> k;
        vector<pii> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].F;
            a[i].S = i;
        }
        sort(all(a));
        int segs = n;
        for (int i = 1; i < n; i++) {
            if (a[i - 1].S + 1 == a[i].S) {
                segs--;
            }
        }
        cout << (segs <= k ? "Yes" : "No") << br;
    }
 
    return 0;
}