/** http://codeforces.com/problemset/problem/377/A */
 
#include <iostream>
 
using namespace std;
 
const int MX = 505;
 
int m, n;
string grid[MX];
bool vis[MX][MX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
 
int build(const int x, const int y, const int k)
{
    if(k <= 0 || x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#' || vis[x][y])
        return 0;
    //cout << x << ' ' << y << ">>\n";
    vis[x][y] = 1;
    int cover = 0;
    for(int i=0; i<4; i++)
    {
        cover += build(x+dx[i], y+dy[i], k-cover);
    }
    if(cover < k)
    {
        grid[x][y] = 'X';
        cover++;
        //cout << '.';
    }
    //cout << x << ' ' << y << "<<\n";
    return cover;
}
 
int main()
{
    int k;
    cin >> m >> n >> k;
    for(int i=0; i<m; i++)
    {
        cin >> grid[i];
    }
 
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(grid[i][j] != '#')
            {
                build(i,j,k);
                for(int i=0; i<m; i++)
                    cout << grid[i] << '\n';
                return 0;
            }
        }
    }
 
    return 0;
}