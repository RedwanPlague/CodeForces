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
        string s, t;
        cin >> n >> s >> t;
 
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (t[i] == '1') {
                if (i - 1 >= 0 && s[i - 1] == '1') {
                    count++;
                    s[i - 1] = '2';
                }
                else if (s[i] == '0') {
                    count++;
                    s[i] = '2';
                }
                else if (i + 1 < n && s[i + 1] == '1') {
                    count++;
                    s[i + 1] = '2';
                }
            }
        }
 
        cout << count << br;
    }
 
    return 0;
}