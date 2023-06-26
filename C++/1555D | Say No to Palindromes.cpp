#include <bits/stdc++.h>
 
using namespace std;
 
#define br '\n'
#define F  first
#define S  second
#define MX 200005
 
#define all(v) (v).begin(), (v).end()
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int n, m;
    string s;
    cin >> n >> m >> s;
 
    int pre[MX][6];
 
    string p[6];
    p[0] = "abc";
    p[1] = "acb";
    p[2] = "bac";
    p[3] = "bca";
    p[4] = "cab";
    p[5] = "cba";
 
    memset(pre[0], 0, sizeof(pre[0]));
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            pre[i + 1][j] = pre[i][j];
            if (s[i] != p[j][i % 3]) {
                pre[i + 1][j]++;
            }
            /* cout << pre[i + 1][j] << ' '; */
        }
        /* cout << br; */
    }
 
    while (m--) {
        int l, r;
        cin >> l >> r;
        int ans = n;
        for (int j = 0; j < 6; j++) {
            ans = min(ans, pre[r][j] - pre[l - 1][j]);
        }
        cout << ans << br;
    }
 
    return 0;
}