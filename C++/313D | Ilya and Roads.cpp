#include <iostream>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
#define MX 305
#define INF (1LL<<60)
 
int main()
{
    ios_base::sync_with_stdio(0); // cin.tie(0); cout.tie(0);
    int N, M, K, l, r;
    ll c;
 
    cin>>N>>M>>K;
 
    ll full[MX][MX]; // full[i][j] = minimum cost to cover a segment that ends in j and covers [i,j] fully and maybe even the holes before i, but not after j.
 
    fill(full[0], full[N+1], INF);
 
    for(int i=0; i<M; i++)
    {
        cin>>l>>r>>c;
        full[l][r] = min(full[l][r], c);
    }
 
    full[0][0] = 0;
 
    for(r = 1; r <= N; r++)
    {
        for(l = 1; l <= r; l++)
        {
            full[l][r] = min(full[l][r], full[l-1][r]); // if i can cover [4,6] in cost 4$ and [5,6] in 5$.... which is better? [4,6] obviously.
        }
    }
 
    ll dp[MX][MX]; // dp[i][j] = minimum cost after checking i holes and covering atleast j of them
 
    fill(dp[0], dp[N+1], INF);
 
    dp[0][0] = 0;
 
    for(int i=1; i<=N; i++)
    {
        dp[i][0] = 0;
        for(int j=1; j<=i; j++)
        {
            dp[i][j] = min(dp[i][j], dp[i-1][j]); // two ways to cover j holes after checking i of them : either we've already covered j of them at i-1 checkings or..
            for(int k = 0; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i-(j-k)][k] + full[i-(j-k)+1][i]); // or we've covered k holes in i-(j-k) checkings and now will cover additional (j-k) holes; these (j-k) holes being [i-(j-k)+1,i]
            }
        }
    }
 
    ll ans = *min_element(dp[N] + K, dp[N+1]);
 
    if(ans >= INF)
        ans = -1;
 
    cout<<ans<<endl;
 
    return 0;
}