#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
 
#define MX 1000010
#define MOD 1'000'000'007
#define set(N,pos) (N | (1LL<<(pos)))
#define clear(N,pos) (N & (~(1LL<<(pos))))
#define is_set(N,pos) (N & (1LL<<(pos)))
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
 
int n, m, lim, xs;
char grid[MX];
int lvl[MX], mark[MX];
 
pii coor(int idx)
{
    return pii(idx/m,idx-(idx/m)*m);
}
 
int man(int x, int y)
{
    return (x*m+y);
}
 
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
 
bool isboundary(int pos)
{
    if(grid[pos] == '.')
        return false;
    pii t = coor(pos);
    int x = t.F, y = t.S;
    if(x == 0 || x == n-1 || y == 0 || y == m-1)
        return true;
    for(int i=0; i<8; i++)
    {
        if(grid[man(x+dx[i],y+dy[i])] == '.')
            return true;
    }
    return false;
}
 
bool bfs(int lst)
{
    if(lst == 0)
        return true;
 
    memset(mark,-1,sizeof(mark));
 
    int cnt = 0;
 
    queue<int> que;
    for(int i=0; i<lim; i++)
    {
        if(lvl[i] >= lst)
        {
            que.push(i);
            mark[i] = 0;
            cnt++;
        }
    }
 
    while(!que.empty())
    {
        int u = que.front(), v;
        que.pop();
        pii t = coor(u);
        int x = t.F, y = t.S;
        for(int i=0; i<8; i++)
        {
            if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m)
            {
                v = man(x+dx[i],y+dy[i]);
                if(grid[v] == 'X' && mark[v] == -1)
                {
                    mark[v] = 1 + mark[u];
                    cnt++;
                    if(mark[v] < lst)
                        que.push(v);
                }
            }
        }
    }
 
    return (cnt == xs);
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(false); cin.tie(0);
 
    cin >> n >> m;
    lim = n*m;
    string s;
    int pos = 0;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        for(int j=0; j<m; j++)
            grid[pos++] = s[j];
    }
 
    memset(lvl,-1,sizeof(lvl));
 
    xs = 0;
    queue<int> que;
    for(int i=0; i<lim; i++)
    {
        if(isboundary(i))
        {
            que.push(i);
            xs++;
            lvl[i] = 0;
        }
    }
 
    int lo = 0, hi = 0, mid;
 
    while(!que.empty())
    {
        int u = que.front(), v;
        que.pop();
        pii t = coor(u);
        int x = t.F, y = t.S;
        for(int i=0; i<8; i++)
        {
            if(x+dx[i] >= 0 && x+dx[i] < n && y+dy[i] >= 0 && y+dy[i] < m)
            {
                v = man(x+dx[i],y+dy[i]);
                if(grid[v] == 'X' && lvl[v] == -1)
                {
                    lvl[v] = 1 + lvl[u];
                    xs++;
                    hi = max(hi,lvl[v]);
                    que.push(v);
                }
            }
 
        }
    }
 
    while(lo < hi-1)
    {
        mid = (lo + hi) / 2;
        if(bfs(mid))
            lo = mid;
        else
            hi = mid-1;
    }
    int T;
    if(bfs(hi))
        T = hi;
    else
        T = lo;
 
    cout << T << endl;
    for(int i=0, pos=0; i<n; i++)
    {
        for(int j=0; j<m; j++,pos++)
        {
            if(lvl[pos] >= T)
                cout << 'X';
            else
                cout << '.';
        }
        cout << '\n';
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 