#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 1005
#define MOD 1'000'000'007
#define set(N,pos) (N = (1LL<<(pos)))
#define clear(N,pos) (N = (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
 
bool ar[MX][MX], vis[MX][MX];
 
ll bigMod(ll base, ll pw)
{
    ll ret = 1, mul = base;
    while(pw)
    {
        if(pw&1)
            ret = (ret*mul)%MOD;
        mul = (mul*mul)%MOD;
        pw >>= 1;
    }
    return ret;
}
 
int main()
{
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    int h, w;
    cin >> h >> w;
    vi r(h), c(w);
    for(int i=0; i<h; i++)
        cin >> r[i];
    for(int j=0; j<w; j++)
        cin >> c[j];
 
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<r[i]; j++)
        {
            ar[i][j] = 1;
            vis[i][j] = 1;
        }
        ar[i][r[i]] = 0;
        vis[i][r[i]] = 1;
    }
 
    for(int i=0; i<w; i++)
    {
        for(int j=0; j<c[i]; j++)
        {
            if(vis[j][i] && !ar[j][i])
            {
                cout << 0 << endl;
                return 0;
            }
            ar[j][i] = 1;
            vis[j][i] = 1;
        }
        if(vis[c[i]][i] && ar[c[i]][i])
        {
            cout << 0 << endl;
            return 0;
        }
        ar[c[i]][i] = 0;
        vis[c[i]][i] = 1;
    }
 
    int cnt = 0;
    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            if(vis[i][j])
                cnt++;
 
    cout << bigMod(2,h*w-cnt) << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 