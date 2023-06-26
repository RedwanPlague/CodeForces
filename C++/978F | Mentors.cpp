#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
 
typedef pair<int,int> pii;
 
const int MX = 200005;
 
vector <int> adj[MX];
vector <pii> pr;
int gone[MX], ans[MX], skill[MX];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n, k, u, v;
    cin>>n>>k;
 
    for(int i=1; i<=n; i++)
    {
        cin>>skill[i];
        pr.push_back(pii(skill[i],i));
    }
 
    for(int i=0; i<k; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    sort(pr.begin(), pr.end());
 
    memset(gone, 0, sizeof(gone));
 
    int prev = -1, cnt = 0;
 
    for(int i=0; i<n; i++)
    {
        int bef;
        int sk = pr[i].first;
        if(sk != prev)
        {
            bef = i;
            cnt = 1;
            prev = sk;
        }
        else
        {
            bef = i-cnt;
            cnt++;
        }
        int idx = pr[i].second;
        ans[idx] = max(0,bef - gone[idx]);
        for(int j=0; j<adj[idx].size(); j++)
        {
            if(skill[idx] != skill[adj[idx][j]])
                gone[adj[idx][j]]++;
        }
    }
 
    for(int i=1; i<=n; i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 