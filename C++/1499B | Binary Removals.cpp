#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define F first
#define S second
#define br '\n'
#define all(v) (v).begin(),(v).end()
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
 
int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
 
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.length();
 
        int i = 1;
        while (i < n && !(s[i] == '1' && s[i-1] == '1')) {
            i++;
        }
        /* cout << "i = " << i << br; */
 
        if (i == n) {
            cout << "YES" << br;
        }
        else {
            int j = n-2;
            while (j >= i && !(s[j] == '0' && s[j+1] == '0')) {
                j--;
            }
            /* cout << "j = " << j << br; */
 
            if (j > i) {
                cout << "NO" << br;
            }
            else {
                cout << "YES" << br;
            }
        }
    }
 
    return 0;
}
 