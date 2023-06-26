#include <iostream>
#include <cstring>
 
using namespace std;
 
#define br '\n'
#define all(v) (v).begin(),(v).end()
 
int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
 
    int cnt[101];
 
    while (T--) {
        int n;
        cin >> n;
 
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }
 
        for (int i = 0; i <= 100; i++) {
            if (cnt[i]) {
                cout << i << ' ';
                cnt[i]--;
            }
        }
 
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                cout << i << ' ';
            }
        }
        cout << br;
    }
 
    return 0;
}
 