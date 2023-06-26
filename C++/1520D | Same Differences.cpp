#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, long long> cnt;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a - i]++;
        }
        long long sum = 0;
        for (auto x : cnt) {
            sum += x.second * (x.second - 1) / 2;
        }
        cout << sum << '\n';
    }
 
    return 0;
}