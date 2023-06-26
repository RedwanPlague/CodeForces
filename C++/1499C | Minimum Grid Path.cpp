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
        int n;
        cin >> n;
        ll mne, mno, sume, sumo, cnte = 1, cnto = 1;
        cin >> mne >> mno;
        sume = mne;
        sumo = mno;
        ll ans = mne * n + mno * n;
        for (int i=2; i<n; i++) {
            ll a;
            cin >> a;
            if (i&1) {
                mno = min(mno, a);
                sumo += a;
                cnto++;
            }
            else {
                mne = min(mne, a);
                sume += a;
                cnte++;
            }
            ans = min(ans, sume + mne * (n - cnte) + sumo + mno * (n - cnto));
        }
 
        cout << ans << br;
    }
 
    return 0;
}
 