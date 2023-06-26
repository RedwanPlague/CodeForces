#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
    while (T--) {
        int n, H;
        cin >> n >> H;
 
        int a, b;
        cin >> a >> b;
        if (a < b) {
            swap(a, b);
        }
 
        for (int i = 2; i < n; i++) {
            int c;
            cin >> c;
            if (c >= a) {
                b = a;
                a = c;
            }
            else if (a > c && c > b) {
                b = c;
            }
        }
 
        int t = a + b;
        int cnt = H / t * 2;
        int extra = H % t;
        if (extra) {
            cnt++;
            if (extra > a) {
                cnt++;
            }
        }
 
        cout << cnt << endl;
    }
 
    return 0;
}