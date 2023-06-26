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
        int h, w;
        cin >> h >> w;
 
        vvi grid(h, vi(w, 0));
        for (int j = 0; j < w; j += 2) {
            grid[0][j] = 1;
        }
        for (int i = 2; i < h; i += 2) {
            grid[i][w - 1] = 1;
        }
        for (int j = w - 3; j >= 0; j -= 2) {
            grid[h - 1][j] = 1;
        }
        for (int i = h - 3; i >= 2; i -= 2) {
            grid[i][0] = 1;
        }
 
        for (auto &r : grid) {
            for (auto &c : r) {
                cout << c;
            }
            cout << br;
        }
        cout << br;
    }
 
    return 0;
}