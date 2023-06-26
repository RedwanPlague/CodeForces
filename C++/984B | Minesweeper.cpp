#include <iostream>
#include <string>
using namespace std;
 
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
string grid[101];
 
int get(char c)
{
    if(c == '*')
        return 1;
    return 0;
}
 
int check(char c)
{
    if(c == '.')
        return 0;
    return (c - '0');
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m; 
    cin>>n>>m;
    
    for(int i=0; i<n; i++)
        cin>>grid[i];
        
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int cnt = 0;
            for(int k=0; k<8; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x >= 0 && x < n && y >= 0 && y < m)
                    cnt += get(grid[x][y]);
            }
            if(grid[i][j] != '*' && check(grid[i][j]) != cnt)
            {
                //cout<<i<<' '<<j<<endl;
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    
    cout<<"YES"<<endl;
    
    return 0;
}