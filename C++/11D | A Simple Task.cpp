#include <iostream>
#include <cstring>
 
using namespace std;
 
typedef long long ll;
 
bool adj[20][20];
ll dp[1<<19][20];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, m, u, v;
    cin >> n >> m;
    memset(adj,0,sizeof(adj));
    for(int i=0; i<m; i++)
    {
        cin >> u >> v;
        u--; v--;
        adj[u][v] = adj[v][u] = 1;
    }
 
    int limit = (1<<n);
    ll cycle = 0;
    memset(dp,0,sizeof(dp));
    for(int mask=1; mask<limit; mask++)
    {
        int cnt = 1; // count of set bits
        int fi = 0; // first set bit
        while(!(mask&(1<<fi)))
            fi++;
        if((1<<fi) == mask)
        {
            dp[mask][fi] = 1;
            continue;
        }
        for(int i=fi+1; (1<<i)<mask; i++)
        {
            if(mask&(1<<i))
            {
                for(int j=fi; (1<<j)<mask; j++)
                {
                    if((mask&(1<<j)) && adj[i][j] && i != j)
                    {
                        dp[mask][i] += dp[mask^(1<<i)][j];
                    }
                }
                cnt++;
            }
        }
        if(cnt >= 3)
        {
            for(int i=fi+1; (1<<i)<mask; i++)
            {
                if((mask&(1<<i)) && adj[fi][i])
                    cycle += dp[mask][i];
            }
        }
    }
 
    cout << (cycle>>1) << endl;
 
    return 0;
}