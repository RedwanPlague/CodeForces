#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
 
#define br '\n'
#define F  first
#define S  second
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        if (n == 1 && m == 1) {
            cout << 0 << br;
        }
        else if (n == 1 || m == 1) {
            cout << 1 << br;
        }
        else {
            cout << 2 << br;
        }
    }
 
    return 0;
}