#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define F first
#define S second
#define br '\n'
#define all(v) (v).begin(),(v).end()
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
 
int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
    while (T--) {
        int n, k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;
        int mnk = min(k1, k2);
        int mxk = max(k1, k2);
        int wl = mnk + (mxk - mnk) / 2;
        int bl = (n - mxk) + (mxk - mnk) / 2;
        if (w <= wl && b <= bl) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
 
    return 0;
}
 