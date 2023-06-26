#include <bits/stdc++.h>
 
using namespace std;
 
#define F  first
#define S  second
#define br '\n'
#define MX 1000006
 
#define all(v) (v).begin(), (v).end()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
void sfill(string &s, int l, char c) { s.append(string(l - s.size(), c)); }
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
    while (T--) {
        string n;
        int k;
        cin >> n >> k;
        int l = n.size();
 
        ll mn = (1LL << 60);
 
        ll vn = stoll(n);
        for (char d = '1'; d <= '9'; d++) {
            ll vN = stoll(string(l, d));
            if (vN >= vn) {
                mn = vN;
                break;
            }
        }
 
        if (k == 1) {
            cout << mn << br;
            continue;
        }
 
        for (int a = '0'; a <= '9'; a++) {
            for (int b = a + 1; b <= '9'; b++) {
                string N;
                for (int i = 0; i < l; i++) {
                    if (n[i] == a || n[i] == b) {
                        N += n[i];
                    }
                    else {
                        if (n[i] < a) {
                            sfill(N, l, a);
                        }
                        else if (n[i] < b) {
                            N += b;
                            sfill(N, l, a);
                        }
                        else {
                            while (!N.empty() && N.back() != a) {
                                N.pop_back();
                            }
                            if (N.empty()) {
                                if (a == '0') {
                                    N += b;
                                }
                                sfill(N, l + 1, a);
                            }
                            else {
                                N.back() = b;
                                sfill(N, l, a);
                            }
                        }
                        break;
                    }
                }
                mn = min(mn, stoll(N));
            }
        }
        cout << mn << endl;
    }
 
    return 0;
}