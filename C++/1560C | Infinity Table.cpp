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
 
    /* for (int i = 0; i < 10; i++) { */
    /*     cout << i << ' ' << (int)sqrt(i) << br; */
    /* } */
 
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        int n1 = sqrt(k - 1);
        int n = n1 + 1;
        int mid = n1 * n1 + n;
        if (k == mid) {
            cout << n << ' ' << n << br;
        }
        else if (k > mid) {
            cout << n << ' ' << n * n - k + 1 << br;
        }
        else if (k < mid) {
            cout << k - n1 * n1 << ' ' << n << br;
        }
    }
 
    return 0;
}