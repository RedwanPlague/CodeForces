#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define MX 2005
#define MOD 998244353
 
ll bigmod(ll base, ll pw)
{
    base %= MOD;
    pw = (pw + MOD - 1) % (MOD - 1);
    ll ret = 1;
    while(pw)
    {
        if(pw&1)
            ret = (ret*base)%MOD;
        base = (base*base)%MOD;
        pw >>= 1;
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    string s;
    cin >> s;
    int n = s.size();
 
    int sum[MX];
    sum[0] = 0;
    for(int i=0; i<n; i++)
    {
        sum[i+1] = sum[i] + (s[i] == '?');
    }
 
    ll dp[MX][MX];
    memset(dp,0,sizeof(dp));
    for(int len=2; len<=n; len++)
    {
        for(int i=0, j=len-1; j<n; i++, j++)
        {
            if(s[i] != '(') // then either  s[i]==')'  or  s[i]=='?' and we make it s[i]==')' , so we can discard s[i]
            {
                dp[i][j] = (dp[i][j] + dp[i+1][j]) % MOD;
            }
            if(s[j] != ')') // then either  s[j]=='('  or  s[j]=='?' and we make it s[j]=='(' , so we can discard s[j]
            {
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
            }
            if(s[i] != '(' && s[j] != ')') // if the first two conditions were true together, we counted some things twice
            {
                dp[i][j] = (dp[i][j] - dp[i+1][j-1] + MOD) % MOD;
            }
            if(s[i] != ')' && s[j] != '(') // now we can make s[i]=='(' and s[j]==')', so now they add 1 to the depths of all the different sequences already created in s(i+1,j-1) which is 2^k, k = '?'s in s(i+1,j-1)
            {
                dp[i][j] = (dp[i][j] + dp[i+1][j-1] + bigmod(2,sum[j]-sum[i+1])) % MOD;
            }
        }
    }
 
    cout << dp[0][n-1] << endl;
 
    return 0;
}