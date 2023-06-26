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
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) {
            swap(a, b);
        }
        int n = 2 * (b - a);
        int d1 = c + n / 2;
        int d2 = c - n / 2;
        if (a > n || b > n || c > n) {
            cout << -1 << br;
        }
        else if (d1 <= n) {
            cout << d1 << br;
        }
        else if (d2 <= n) {
            cout << d2 << br;
        }
        else {
            cout << -1 << br;
        }
    }
 
    return 0;
}