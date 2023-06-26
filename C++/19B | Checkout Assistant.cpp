#include <cstdio>
#include <algorithm>
using namespace std;
 
#define read(n) scanf("%d", &n)
#define MX 4002
#define INF (1LL<<60)
 
int main()
{
    int n;
    read(n);
 
    int time[MX], cost[MX];
 
    for(int i=1; i<=n; i++)
    {
        read(time[i]); read(cost[i]);
        time[i]++;
    }
 
    long long dp[MX][MX];
 
    fill(dp[0], dp[MX], INF);
 
    dp[0][0] = 0;
 
    for(int i=1; i<=n; i++)
    {
        dp[i][0] = 0;
        for(int j=1; j<MX; j++)
        {
            if(dp[i-1][j] != INF)
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if(j >= time[i] && dp[i-1][j-time[i]] != INF)
                dp[i][j] = min(dp[i][j], cost[i] + dp[i-1][j-time[i]]);
            //printf("%I64d ", dp[i][j]);
        }
        //puts("");
    }
 
    long long minCost = INF;
 
    for(int j=n; j<MX; j++)
    {
        minCost = min(minCost, dp[n][j]);
    }
 
    printf("%I64d\n", minCost);
 
    return 0;
}