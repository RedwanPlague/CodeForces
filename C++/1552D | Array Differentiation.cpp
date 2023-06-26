#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
#define br '\n'
#define F  first
#define S  second
 
#define all(v) (v).begin(), (v).end()
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int lim = (1 << n);
        bool found = false;
 
        for (int j = 0; !found && j < n; j++) {
            if (a[j] == 0) {
                found = true;
            }
        }
 
        for (int i = 1; !found && i < lim; i++) {
            for (int k = 1; !found && k < lim; k++) {
                ll sum = 0;
                for (int j = 0; j < n; j++) {
                    if (i & (1 << j)) {
                        if (k & (1 << j)) {
                            sum += a[j];
                        }
                        else {
                            sum -= a[j];
                        }
                    }
                }
                for (int j = 0; !found && j < n; j++) {
                    if (!(i & (1 << j))) {
                        if (sum == a[j]) {
                            found = true;
                        }
                    }
                }
            }
        }
        cout << (found ? "YES" : "NO") << br;
    }
 
    return 0;
}