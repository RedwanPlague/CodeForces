#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define F first
#define S second
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        ll sum = 0, change = 0;
        cin >> sum;
        for (int i=1; i<n; i++) {
            ll p;
            cin >> p;
            ll inc = max(0LL, (100*p - 1) / k + 1 - sum);
            change += inc;
            sum += p + inc;
        }
        cout << change << '\n';
    }
 
    return 0;
}
 