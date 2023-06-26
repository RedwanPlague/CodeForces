#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
const ll p = 3; // can't use p = 2, cause then 2^a will be 0 for all a > 63, as we have 2^63 as mod by using long long. I think p and mod have to be co-prime :3
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
 
    vector <ll> pw(n+1), hs(n+1,0);
    vector <pii> edge;
 
    pw[0] = 1LL;
    for(int i=1; i<=n; i++)
        pw[i] = p * pw[i-1];
 
    int u, v;
    for(int i=0; i<m; i++)
    {
        cin >> u >> v;
        edge.push_back(pii(u,v));
        hs[u] += pw[v];
        hs[v] += pw[u];
    }
 
    ll ans = 0;
    for(int i=0; i<edge.size(); i++)
    {
        u = edge[i].first;
        v = edge[i].second;
        if(hs[u] + pw[u] == hs[v] + pw[v])
            ans++;
    }
 
    sort(hs.begin()+1,hs.end()); // 0 not included
    ll cnt;
    for(int i=1; i<hs.size(); i++)
    {
        cnt = 1;
        while(i+1 < hs.size() && hs[i] == hs[i+1])
        {
            i++;
            cnt++;
        }
        ans += (cnt*(cnt-1))/2;
    }
 
    cout << ans << endl;
 
    return 0;
}