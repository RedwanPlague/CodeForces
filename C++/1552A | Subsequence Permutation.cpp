#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
 
#define br '\n'
#define F  first
#define S  second
 
#define all(v) (v).begin(), (v).end()
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        vector<pair<char, int>> v;
        for (int i = 0; i < n; i++) {
            v.emplace_back(s[i], i);
        }
        sort(all(v));
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (v[i].F != s[i]) {
                count++;
            }
        }
        cout << count << br;
    }
 
    return 0;
}