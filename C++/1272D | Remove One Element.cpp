#include <bits/stdc++.h>
 
using namespace std;
 
#define MX 200005
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int n;
    cin >> n;
    int a[MX];
    int dp[MX][2]; // vallage na duniya, tai emne korsi. :)      dp[i][0] = haven't deleted anything yet (from [0,i]). dp[i][1] = you get it
 
    cin >> a[0] >> a[1];
    dp[0][0] = dp[1][0] = dp[0][1] = dp[1][1] = 1;
    if(a[1] > a[0])
    {
        dp[1][0]++;
        dp[1][1]++;
    }
 
    int mx = dp[1][1];
    for(int i=2; i<n; i++) // ami koshto pete valobashi
    {
        cin >> a[i];
        dp[i][0] = dp[i][1] = 1;
        if(a[i] > a[i-1])
        {
            dp[i][0] = max(dp[i][0],dp[i-1][0]+1);
            dp[i][1] = max(dp[i][1],dp[i-1][1]+1);
        }
        if(a[i] > a[i-2])
        {
            dp[i][1] = max(dp[i][1],dp[i-2][0]+1);
        }
        mx = max(mx,dp[i][1]);
    }
    
    cout << mx << endl;
 
    return 0;
}