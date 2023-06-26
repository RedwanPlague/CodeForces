#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 200005
#define MOD 1'000'000'007
#define set(N,pos) (N = (1LL<<(pos)))
#define clear(N,pos) (N = (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
 
ll dp[MX][2];
ll a[MX], b[MX], c;
 
ll min_time(int floor, int way)
{
    if(floor == 0)
    {
        if(way)
            return c;
        else
            return 0;
    }
    ll &cur = dp[floor][way];
    if(cur != -1)
        return cur;
    if(way) // elevator
    {
        cur = min(min_time(floor-1,1)+b[floor-1], min_time(floor-1,0)+c+b[floor-1]);
    }
    else // stairs
    {
        cur = min(min_time(floor-1,0),min_time(floor-1,1))+a[floor-1];
    }
    return cur;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    memset(dp, -1, sizeof(dp));
 
    int n;
    cin >> n >> c;
    for(int i=0; i<n-1; i++)
        cin >> a[i];
    for(int i=0; i<n-1; i++)
        cin >> b[i];
    for(int i=0; i<n; i++)
        cout << min(min_time(i,0),min_time(i,1)) << ' ';
    cout << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 