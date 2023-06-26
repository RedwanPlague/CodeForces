#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
 
#define br '\n'
#define F  first
#define S  second
#define MX 200005
 
bool is_kalindrome(const vi &a, int x) {
    vi b;
    for (int i = 0; i < (int)a.size(); i++) {
        if (a[i] != x) {
            b.push_back(a[i]);
        }
    }
    for (int i = 0, j = b.size() - 1; i < j; i++, j--) {
        if (b[i] != b[j]) {
            return false;
        }
    }
    return true;
}
 
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
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool kalindrom = true;
        for (int i = 0, j = a.size() - 1; i < j; i++, j--) {
            if (a[i] != a[j]) {
                if (!is_kalindrome(a, a[i]) && !is_kalindrome(a, a[j])) {
                    kalindrom = false;
                }
                break;
            }
        }
        cout << (kalindrom ? "YES" : "NO") << br;
    }
 
    return 0;
}