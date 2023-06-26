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
 
int cnt[MX], parity[2][MX];
 
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
        memset(cnt, 0, sizeof(cnt));
        memset(parity[0], 0, sizeof(parity[0]));
        memset(parity[1], 0, sizeof(parity[1]));
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            parity[i & 1][a]++;
            cnt[a]++;
        }
        int pos = 0;
        bool ok = true;
        for (int i = 0; ok && i < MX; pos += cnt[i++]) {
            int p = pos & 1;
            if (parity[p][i] != parity[1 - p][i] + (cnt[i] & 1)) {
                ok = false;
            }
        }
 
        cout << (ok ? "YES" : "NO") << br;
    }
 
    return 0;
}