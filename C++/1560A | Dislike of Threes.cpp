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
 
    vi v;
 
    int i = 1;
    while ((int)v.size() < 1000) {
        if (i % 3 != 0 && i % 10 != 3) {
            v.push_back(i);
        }
        i++;
    }
 
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        cout << v[k - 1] << br;
    }
 
    return 0;
}