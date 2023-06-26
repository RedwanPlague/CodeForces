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
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        if (n & 1) {
            n++;
        }
        if (n < 6) {
            cout << 15 << br;
        }
        else {
            cout << n / 2 * 5 << br;
        }
    }
 
    return 0;
}