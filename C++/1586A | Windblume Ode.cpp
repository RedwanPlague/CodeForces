#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using vi = vector<int>;
 
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
        int sum = 0;
        int idx = -1;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            sum += a;
            if (a & 1) {
                idx = i;
            }
        }
 
        bool prime = true;
        for (int i = 2, l = sqrt(sum + 1); prime && i <= l; i++) {
            if (sum % i == 0) {
                prime = false;
            }
        }
 
        if (prime) {
            cout << n - 1 << '\n';
            for (int i = 1; i <= n; i++) {
                if (i != idx) {
                    cout << i << ' ';
                }
            }
            cout << '\n';
        }
        else {
            cout << n << '\n';
            for (int i = 1; i <= n; i++) {
                cout << i << ' ';
            }
            cout << '\n';
        }
    }
 
    return 0;
}