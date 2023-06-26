#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const int MX = 2000005;
const ll INF = (1LL<<62);
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int n, m, k, forb;
    cin>>n>>m>>k;
 
    int prev[MX];
    bool mark[MX];
    ll cost[MX];
 
    memset(mark, 0, sizeof(mark));
    fill(prev, prev+MX, 1000000007);
 
    for(int i=0; i<m; i++)
    {
        cin>>forb;
        mark[forb] = 1;
    }
 
    for(int l=1; l<=k; l++)
        cin>>cost[l];
 
    if(mark[0])
    {
        cout<<-1<<endl;
        return 0;
    }
 
    for(int i=0; i<n; i++)
    {
        if(mark[i])
            prev[i] = prev[i-1];
        else
            prev[i] = i;
    }
 
    ll minCost = INF;
 
    for(int l = 1; l <= k; l++)
    {
        int cur = 0, next, cnt = 0;
        bool valid = true;
        while(cur < n) // this inner loop isn't a problem cause complexity is = n + n/2 + n/3 + n/4 + ..... n/k = nlog(k)
        {
            next = prev[cur+l];
            //cout<<next<<' ';
            if(cur == next)
            {
                valid = false;
                break;
            }
            cur = next;
            cnt++;
        }
        //cout<<'\n';
        if(valid)
            minCost = min(minCost, cnt * cost[l]);
    }
 
    if(minCost == INF)
        minCost = -1;
    cout<<minCost<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 