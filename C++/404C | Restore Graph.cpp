#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
 
#define F first
#define S second
#define br '\n'
 
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int n;
    ll k;
    cin >> n >> k;
 
    vi cnt(n+1,0);
    vector<pii> dist(n);
    for(int i=0; i<n; i++)
    {
        dist[i].S = i+1;
        cin >> dist[i].F;
        cnt[dist[i].F]++;
    }
 
    sort(dist.begin(), dist.end());
 
    int src = dist[0].S;
 
    if(cnt[0] != 1)
    {
        cout << -1 << endl;
        return 0;
    }
 
    ll limit = k;
    for(int i=1; i<n; i++)
    {
        if( (cnt[i] && !cnt[i-1]) || (cnt[i] > limit) )
        {
            cout << -1 << endl;
            return 0;
        }
        if(limit < n)
            limit *= (k-1);
    }
 
    cout << n-1 << br;
    vi prev, cur;
    int idx = 1, curdist = 1;
    prev.push_back(src);
    while(idx < n)
    {
        int i = 0;
        while(idx < n && dist[idx].F == curdist)
        {
            cur.push_back(dist[idx].S);
            cout << prev[i] << " " << dist[idx].S << br;
            idx++;
            i = (i+1)%prev.size();
        }
        curdist++;
        prev = cur;
        cur.clear();
    }
 
    return 0 ;
}