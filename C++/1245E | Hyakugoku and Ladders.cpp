#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 105
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define x first
#define y second
 
const pii INV(-1,-1);
double dp[15][15];
int h[15][15];
bool vis[15][15];
 
pii src(9,0), dest(0,0);
 
pii next(pii cur, int add)
{
    if(cur.x&1)
    {
        cur.y += add;
        if(cur.y >= 10)
        {
            cur.y -= 10;
            cur.y = 9 - cur.y;
            cur.x--;
            if(cur.x < 0)
                return INV;
        }
    }
    else
    {
        cur.y -= add;
        if(cur.y < 0)
        {
            cur.y = -cur.y-1;
            cur.x--;
            if(cur.x < 0)
                return INV;
        }
    }
    return cur;
}
 
pii prev(pii cur)
{
    if(cur.x&1)
    {
        if(cur.y == 0)
        {
            cur.x++;
        }
        else
        {
            cur.y--;
        }
    }
    else
    {
        if(cur.y == 9)
        {
            cur.x++;
        }
        else
        {
            cur.y++;
        }
    }
    return cur;
}
 
pii climb(pii cur)
{
    cur.x -= h[cur.x][cur.y];
    return cur;
}
 
double moves(pii cur)
{
    if(cur == dest)
        return 0;
 
    int i = cur.x;
    int j = cur.y;
    if(vis[i][j])
        return dp[i][j];
 
    vis[i][j] = true;
    double &ret = dp[i][j];
    ret = 1;
    int k = 0;
    for(int add=1; add<=6; add++)
    {
        pii nxt = next(cur,add);
        if(nxt == INV)
            k++;
        else
            ret += min( moves(nxt), moves(climb(nxt)) ) / 6.0;
    }
    if(k)
        ret *= 6.0/(6.0-k);
    return ret;
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            cin >> h[i][j];
 
    memset(vis,0,sizeof(vis));
    cout << fixed << setprecision(10) << moves(src) << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 