#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
 
typedef long long ll;
 
#define br '\n'
 
const int mx = 105;
const ll inf = (1LL<<60);
 
int main()
{
    ios_base::sync_with_stdio(0); // cin.tie(0); cout.tie(0);
    int N, M;
    cin>>N>>M;
 
    int item[mx], noItem[mx];
    ll sum[mx];
    ll lav[mx][mx]; // lav[i][j] = max gain if j items are taken from the i-th shelf
 
    memset(lav, 0, sizeof(lav));
 
    for(int shelf = 1; shelf <= N; shelf++)
    {
        cin>>noItem[shelf];
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= noItem[shelf]; i++)
        {
            cin>>item[i];
            sum[i] = item[i] + sum[i-1];
        }
        for(int i = 1; i <= noItem[shelf]; i++)
        {
            for(int j = i; j <= noItem[shelf]; j++)
            {
                lav[shelf][noItem[shelf]-(j-i+1)] = max(lav[shelf][noItem[shelf]-(j-i+1)], sum[noItem[shelf]] - (sum[j] - sum[i-1]));
            }
        }
        lav[shelf][noItem[shelf]] = sum[noItem[shelf]];
        /*for(int take = 0; take <= noItem[shelf]; take++)
            cout<<lav[shelf][take]<<' ';
        cout<<br;*/
    }
 
 
    ll dp[mx][10005]; // dp[i][j] = max gain if j items are taken total from i shelves
 
    memset(dp, -1, sizeof(dp));
    
    dp[0][0] = 0;
 
    for(int shelf = 1; shelf <= N; shelf++)
    {
        dp[shelf][0] = 0;
        for(int taken = 1; taken <= M; taken++)
        {
            for(int take = 0; take <= noItem[shelf] && take <= taken; take++)
            {
                if(dp[shelf-1][taken - take] != -1)
                    dp[shelf][taken] = max(dp[shelf][taken], dp[shelf-1][taken - take] + lav[shelf][take]);
            }
            //cout<<dp[shelf][taken]<<' ';
        }
        //cout<<br;
    }
 
    cout<<dp[N][M]<<endl;
 
    return 0;
}