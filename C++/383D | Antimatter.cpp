#include <cstdio>
#include <cstring>
 
#define read(n) scanf("%d", &n)
#define OFF 10000
#define MX 20001
#define MOD 1000000007
 
int main()
{
    int n;
    read(n);
 
    int dp[n][MX];
    int a[n];
 
    memset(dp, 0, sizeof(dp));
 
    for(int i=0; i<n; i++)
        read(a[i]);
 
    dp[0][OFF-a[0]] = 1;
    dp[0][OFF+a[0]] = 1;
 
    int sum = dp[0][OFF];
 
    for(int i=1; i<n; i++)
    {
        dp[i][OFF-a[i]] = (dp[i][OFF-a[i]] + 1) % MOD;
        dp[i][OFF+a[i]] = (dp[i][OFF+a[i]] + 1) % MOD;
        for(int j=-OFF; j<=OFF; j++)
        {
            if(OFF+j-a[i] >= 0)
                dp[i][OFF+j] = (dp[i][OFF+j] + dp[i-1][OFF+j-a[i]]) % MOD;
            if(OFF+j+a[i] < MX)
                dp[i][OFF+j] = (dp[i][OFF+j] + dp[i-1][OFF+j+a[i]]) % MOD;
        }
        sum = (sum + dp[i][OFF]) % MOD;
        //dp[i][OFF] = (dp[i][OFF] + 1) % MOD;
    }
 
    /*for(int i=0; i<n; i++)
    {
        for(int j=-OFF; j<=OFF; j++)
        {
            printf("%d ", dp[i][OFF+j]);
        }
        puts("");
    }*/
 
    printf("%d\n", sum);
 
    return 0;
}