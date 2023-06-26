#include <bits/stdc++.h>
using namespace std;
 
#define br '\n'
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 1005;
const ll MOD = 998244353;
 
int n;
int a[MX];
ll dp[MX];
ll comb[MX][MX];
 
void make()
{
    comb[0][0] = 1;
    for(int i=1; i<MX; i++)
    {
        comb[i][0] = 1;
        for(int j=1; j<=i; j++)
        {
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1]) % MOD;
        }
    }
}
 
ll good(int idx)
{
    if(idx == n)
        return 1;
    if(dp[idx] != -1)
        return dp[idx];
    dp[idx] = 0;
    if(a[idx] <= 0)
        return dp[idx];
    for(int i=idx+a[idx]+1; i<=n; i++)
    {
        dp[idx] = ( dp[idx] + (comb[i-idx-1][a[idx]] * good(i))%MOD ) %MOD;
        //cout<<i-idx-1<<' '<<a[idx]<<' '<<comb[i-idx-1][a[idx]]<<' '<<good(i)<<br;
    }
    return dp[idx];
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin>>n;
 
    make();
 
    for(int i=0; i<n; i++)
        cin>>a[i];
 
    memset(dp, -1, sizeof(dp));
 
    ll ans = 0;
 
    for(int i=0; i<n; i++)
    {
        ans += good(i);
    }
 
    cout<<ans%MOD<<endl;
 
    return 0;
}