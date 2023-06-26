#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int MX = 105;
const int MOD = 1e9+7;
 
int main()
{
    ios_base::sync_with_stdio(0);
 
    int n, b;
    cin >> n;
    vector<bool> cnt(n+1,0);
    vi a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
 
    int idx = 0;
    for(int i=0; i<n; i++)
    {
        cin >> b;
        if(!cnt[b])
        {
            int ans = 1;
            while(a[idx] != b)
            {
                cnt[a[idx]] = 1;
                idx++;
                ans++;
            }
            cout << ans << ' ';
            idx++;
            cnt[b] = 1;
        }
        else
            cout << 0 << ' ';
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 