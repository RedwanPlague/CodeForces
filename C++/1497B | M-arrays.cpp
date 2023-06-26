#include <iostream>
#include <cstring>
 
using namespace std;
 
#define br '\n'
#define all(v) (v).begin(),(v).end()
 
int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../708/input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
 
    int cnt[100001];
 
    while (T--) {
        memset(cnt, 0, sizeof(cnt));
 
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a%m]++;
        }
 
        int ans = (cnt[0] > 0);
 
        int i = 1, j = m - 1;
        while (i < j) {
            if (cnt[i] > 0 || cnt[j] > 0) {
                int mx = max(cnt[i], cnt[j]);
                int mn = min(cnt[i], cnt[j]);
                ans += max(1, mx - mn);
            }
            i++, j--;
        }
 
        if (i == j) {
            ans += (cnt[i] > 0);
        }
 
        cout << ans << br;
    }
 
    return 0;
}
 