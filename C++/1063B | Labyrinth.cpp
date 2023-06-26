#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
#include <iomanip>
 
#define F first
#define S second
 
using namespace std;
 
typedef pair<int,int> pii;
 
const int MX = 2005;
 
string grid[MX];
int dist[MX][MX];
int n, m, X, Y, r, c;
 
void BFS01()
{
    deque<pii> dq;
    dq.push_back({r,c});
    dist[r][c] = 0;
    while(!dq.empty())
    {
        pii u = dq.front();
        //cout << "(" << u.F << "," << u.S << ") = " << dist[u.F][u.S] << endl;
        dq.pop_front();
        for(int i=0; i<4; i++)
        {
            int vx, vy;
            vx = u.F;
            vy = u.S-1;
            if(vy >= 0 && dist[u.F][u.S] < dist[vx][vy] && grid[vx][vy] == '.')
            {
                dist[vx][vy] = dist[u.F][u.S];
                dq.push_front({vx,vy});
            }
            vy = u.S+1;
            if(vy < m && 1 + dist[u.F][u.S] < dist[vx][vy] && grid[vx][vy] == '.')
            {
                dist[vx][vy] = 1 + dist[u.F][u.S];
                dq.push_back({vx,vy});
            }
            vy = u.S;
            vx = u.F+1;
            if(vx < n && dist[u.F][u.S] < dist[vx][vy] && grid[vx][vy] == '.')
            {
                dist[vx][vy] = dist[u.F][u.S];
                dq.push_front({vx,vy});
            }
            vx = u.F-1;
            if(vx >= 0 && dist[u.F][u.S] < dist[vx][vy] && grid[vx][vy] == '.')
            {
                dist[vx][vy] = dist[u.F][u.S];
                dq.push_front({vx,vy});
            }
        }
    }
}
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif // ONLINE_JUDGE
 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    cin >> n >> m >> r >> c >> X >> Y;
    r--;
    c--;
 
    for(int i=0; i<n; i++)
    {
        cin >> grid[i];
    }
 
    memset(dist,127,sizeof(dist));
 
    BFS01();
 
    int cnt = 0;
    int L, R;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            //cout << setw(2) << dist[i][j] << " ";
            R = dist[i][j];
            if(R == -1)
                continue;
            L = R - j + c;
            if(L <= X && R <= Y)
                cnt++;
        }
        //cout << endl;
    }
 
    cout << cnt << endl;
 
    return 0;
}