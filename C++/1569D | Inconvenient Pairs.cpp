#include <bits/stdc++.h>
 
using namespace std;
 
#define F  first
#define S  second
#define br '\n'
#define MX 1000006
 
#define all(v)   (v).begin(), (v).end()
#define pairs(c) ((ll)c * (c - 1) / 2);
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
char isx[MX], isy[MX];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
 
        vi xs(n), ys(m);
        memset(isx, 0, sizeof(isx));
        memset(isy, 0, sizeof(isy));
 
        for (auto &x : xs) {
            cin >> x;
            isx[x] = 1;
        }
        for (auto &y : ys) {
            cin >> y;
            isy[y] = 1;
        }
 
        vvi partx(n), party(m);
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            if (isx[x] && isy[y]) {
                continue;
            }
            if (isx[x]) {
                int i = upper_bound(all(ys), y) - ys.begin();
                party[i].push_back(x);
            }
            else if (isy[y]) {
                int i = upper_bound(all(xs), x) - xs.begin();
                partx[i].push_back(y);
            }
        }
 
        ll total = 0;
        for (auto &parts : {partx, party}) {
            for (auto &part : parts) {
                if ((int)part.size() > 1) {
                    total += pairs(part.size());
                    map<int, int> cnt;
                    for (auto v : part) {
                        cnt[v]++;
                    }
                    for (auto p : cnt) {
                        total -= pairs(p.S);
                    }
                }
            }
        }
 
        cout << total << br;
    }
 
    return 0;
}