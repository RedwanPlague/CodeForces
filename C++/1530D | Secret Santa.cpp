#include <bits/stdc++.h>
 
using namespace std;
 
#define br '\n'
 
#ifdef REDWAN
#define dump(x) cerr << #x << " = " << x << endl
#else
#define dump(x)
#endif
 
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
        int n;
        cin >> n;
        vi a(n + 1);
        vector<bool> mark(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mark[a[i]] = true;
        }
        vector<bool> used(n + 1, 0);
        vector<bool> happy(n + 1, 0);
        vi ans(n + 1);
        for (int i = 1; i <= n; i++) {
            if (!mark[i]) {
                if (!used[a[i]]) {
                    happy[i] = true;
                    ans[i] = a[i];
                    used[a[i]] = true;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!used[a[i]]) {
                happy[i] = true;
                ans[i] = a[i];
                used[a[i]] = true;
            }
        }
 
        priority_queue<int> noto, nofrom;
        for (int i = 1; i <= n; i++) {
            if (!happy[i]) {
                noto.push(i);
            }
            if (!used[i]) {
                nofrom.push(i);
            }
        }
 
        int mx = n - noto.size();
 
        while (!noto.empty()) {
            int a = noto.top(), b = nofrom.top();
            noto.pop();
            nofrom.pop();
            if (a == b) {
                int pb = b;
                b = nofrom.top();
                nofrom.pop();
                nofrom.push(pb);
            }
            ans[a] = b;
        }
 
        cout << mx << br;
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
        cout << br;
    }
 
    return 0;
}