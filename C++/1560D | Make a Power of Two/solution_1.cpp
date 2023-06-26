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
 
string s, t, w;
 
int dp[20][20];
 
int lcs(int i, int j) {
    if (i == (int)s.length()) {
        return 0;
    }
    if (j == (int)t.length()) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (s[i] == t[j]) {
        return (dp[i][j] = 1 + lcs(i + 1, j + 1));
    }
    return (dp[i][j] = lcs(i + 1, j));
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef REDWAN
    freopen("input.txt", "r", stdin);
#endif
 
    /* for (int i = 0; i < 60; i++) { */
    /*     cout << (1LL << i) << endl; */
    /* } */
 
    vector<string> twops({"1",
                          "2",
                          "4",
                          "8",
                          "16",
                          "32",
                          "64",
                          "128",
                          "256",
                          "512",
                          "1024",
                          "2048",
                          "4096",
                          "8192",
                          "16384",
                          "32768",
                          "65536",
                          "131072",
                          "262144",
                          "524288",
                          "1048576",
                          "2097152",
                          "4194304",
                          "8388608",
                          "16777216",
                          "33554432",
                          "67108864",
                          "134217728",
                          "268435456",
                          "536870912",
                          "1073741824",
                          "2147483648",
                          "4294967296",
                          "8589934592",
                          "17179869184",
                          "34359738368",
                          "68719476736",
                          "137438953472",
                          "274877906944",
                          "549755813888",
                          "1099511627776",
                          "2199023255552",
                          "4398046511104",
                          "8796093022208",
                          "17592186044416",
                          "35184372088832",
                          "70368744177664",
                          "140737488355328",
                          "281474976710656",
                          "562949953421312",
                          "1125899906842624",
                          "2251799813685248",
                          "4503599627370496",
                          "9007199254740992",
                          "18014398509481984",
                          "36028797018963968",
                          "72057594037927936",
                          "144115188075855872",
                          "288230376151711744",
                          "576460752303423488"});
 
    int T;
    cin >> T;
    while (T--) {
        cin >> s;
        int S = s.length();
        int mn = 10000;
        for (auto &x : twops) {
            t = x;
            int L = x.length();
            memset(dp, -1, sizeof(dp));
            int l = lcs(0, 0);
            int cur = L - l + S - l;
            if (cur < mn) {
                mn = cur;
                w = x;
            }
        }
        cout << mn << br;
    }
 
    return 0;
}