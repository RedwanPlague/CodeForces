#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
 
int main() {
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vi pos;
        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                pos.push_back(i);
            }
        }
        if (pos.empty()) {
            cout << "0\n";
        }
        else {
            int median = pos[pos.size() / 2], midx = pos.size() / 2;
            long long sum = 0;
            for (int i = 0; i < (int)pos.size(); i++) {
                sum += abs(pos[i] - median) - abs(i - midx);
            }
            cout << sum << '\n';
        }
    }
 
    return 0;
}