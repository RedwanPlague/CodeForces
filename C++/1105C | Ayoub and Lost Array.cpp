#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll MOD = 1000000007;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, l, r;
    ll c0, c1, c2;
 
    cin >> n >> l >> r;
 
    c0 = (r/3)-(l/3)+(l%3 == 0);
    c1 = ((r+2)/3)-((l+2)/3)+(l%3 == 1);
    c2 = ((r+1)/3)-((l+1)/3)+(l%3 == 2);
 
    ll dp[200005][3];
 
    dp[0][0] = c0;
    dp[0][1] = c1;
    dp[0][2] = c2;
 
    for(int i=1; i<n; i++)
    {
        dp[i][0] = ( (c0*dp[i-1][0])%MOD + (c2*dp[i-1][1])%MOD + (c1*dp[i-1][2])%MOD )%MOD;
        dp[i][1] = ( (c1*dp[i-1][0])%MOD + (c0*dp[i-1][1])%MOD + (c2*dp[i-1][2])%MOD )%MOD;
        dp[i][2] = ( (c2*dp[i-1][0])%MOD + (c1*dp[i-1][1])%MOD + (c0*dp[i-1][2])%MOD )%MOD;
    }
 
    cout << dp[n-1][0] << endl;
 
    return 0;
}
 