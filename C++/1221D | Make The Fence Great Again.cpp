#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define MX 300005
 
ll a[MX], b[MX], dp[MX][5];
int vis[MX][5], mark;
int n;
 
ll min_cost(int pos, ll diff)
{
    if(diff < -2)
        diff = -2;
    else if(diff > 1)
        diff = 1;
 
    if(vis[pos][diff+2] == mark)
        return dp[pos][diff+2];
 
    vis[pos][diff+2] = mark;
 
    if(pos == n-1)
    {
        if(diff == 0)
        {
            return (dp[pos][diff+2] = b[pos]);
        }
        return (dp[pos][diff+2] = 0);
    }
 
    if(diff == 0)
    {
        ll ret = b[pos] + min_cost(pos+1,a[pos+1]-a[pos]-1);
        ret = min(ret, 2*b[pos] + min_cost(pos+1,a[pos+1]-a[pos]-2));
 
        return (dp[pos][diff+2] = ret);
    }
 
    if(diff > 0)
    {
        ll ret = min_cost(pos+1,a[pos+1]-a[pos]);
        ret = min(ret, b[pos] + min_cost(pos+1,a[pos+1]-a[pos]-1));
 
        return (dp[pos][diff+2] = ret);
    }
 
    ll ret = min_cost(pos+1,a[pos+1]-a[pos]);
    if(diff != -1)
    {
        ret = min(ret, b[pos] + min_cost(pos+1,a[pos+1]-a[pos]-1));
    }
    ret = min(ret, 2*b[pos] + min_cost(pos+1,a[pos+1]-a[pos]-2));
 
    return (dp[pos][diff+2] = ret);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    int Q;
    cin >> Q;
    while(Q--)
    {
        cin >> n;
        for(int i=0; i<n; i++)
        {
            cin >> a[i] >> b[i];
        }
        mark++;
        cout << min_cost(0,1) << '\n';
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 