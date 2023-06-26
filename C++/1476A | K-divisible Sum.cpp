#include <iostream>
#include <vector>
 
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
        int m = (n-1)/k+1;
        ll use = (ll)m * k;
        cout << (use-1)/n+1 << '\n';
    }
 
    return 0;
}
 