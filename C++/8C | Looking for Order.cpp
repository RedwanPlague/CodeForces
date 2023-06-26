#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
 
#define read(n) scanf("%d", &n)
#define MX 24
#define INF 1000000007
#define x first
#define y second
#define pb push_back
#define dis(a,b) ( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) )
 
typedef pair<int,int> pii;
 
int n, limit;
vector <pii> v;
pii origin;
int dp[1<<MX];
vector <int> which[1<<MX];
 
int quick(int mask)
{
    if(mask == limit)
        return 0;
    if(dp[mask] != -1)
        return dp[mask];
    int pos = 0;
    while(mask & (1<<pos))
        pos++;
    int cost = dis(origin,v[pos]);
    int temp = mask;
    int ps = pos;
    which[temp].pb(ps);
    mask |= (1<<pos);
    if(mask == limit)
        return (dp[temp] = 2*cost);
    int minCost = cost + quick(mask);
    int other = -1;
    pos++;
    while(pos < n)
    {
        if(!(mask & (1<<pos)))
        {
            int ret = dis(origin, v[pos]) + dis(v[ps], v[pos]) + quick(mask | (1<<pos));
            if(ret < minCost)
            {
                minCost = ret;
                other = pos;
            }
        }
        pos++;
    }
    if(other != -1)
        which[temp].pb(other);
    return (dp[temp] = cost + minCost);
}
 
int main()
{
    int X, Y;
    read(origin.x); read(origin.y);
    read(n);
    limit = (1<<n) - 1;
    for(int i=0; i<n; i++)
    {
        read(X); read(Y);
        v.pb(pii(X,Y));
    }
    memset(dp, -1, sizeof(dp));
    printf("%d\n", quick(0));
 
    int mask = 0;
 
    while(mask != limit)
    {
        printf("0 ");
        int temp = mask;
        for(int i=0; i<which[temp].size(); i++)
        {
            mask |= (1<<which[temp][i]);
            printf("%d ", 1 + which[temp][i]);
        }
    }
    printf("0\n");
 
    return 0;
}