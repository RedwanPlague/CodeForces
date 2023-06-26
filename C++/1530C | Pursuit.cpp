#include <bits/stdc++.h>
 
using namespace std;
 
#define br '\n'
 
#ifdef REDWAN
#define dump(x) cerr << #x << " = " << x << endl
#else
#define dump(x)
#endif
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
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
        ll sa = 0, sb = 0;
        vi a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
 
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
 
        for (int i = n / 4; i < n; i++) {
            sa += a[i];
            sb += b[i];
        }
 
        int use = n - n / 4;
        int i = n / 4, j = n / 4, extra = 0;
        while (sa < sb) {
            extra++;
            n++;
            int new_use = n - n / 4;
            a.push_back(100);
            sa += a.back();
            if (new_use == use) {
                sa -= a[i];
                i++;
            }
            else if (j > 0) {
                sb += b[--j];
            }
            use = new_use;
        }
 
        cout << extra << br;
    }
 
    return 0;
}