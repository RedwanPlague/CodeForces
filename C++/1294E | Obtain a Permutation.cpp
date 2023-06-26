#include <iostream>
#include <vector>
 
using namespace std;
 
typedef vector<int> vi;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, m, a;
    cin >> n >> m;
    vector<vi> grid(n, vi(m));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> a;
            a -= (j+1);
            grid[i][j] = (a%m == 0) ? a/m : -1;
        }
    }
    
    int tot = 0;
    for(int j=0; j<m; j++)
    {
        vi cnt(n,0);
        for(int i=0; i<n; i++)
            if(grid[i][j] != -1 && grid[i][j] < n)
                cnt[ i - grid[i][j] + (grid[i][j] > i ? n : 0)]++;
        
        int mn = n;
        for(int i=0; i<n; i++)
        {
            mn = min(mn, i+n-cnt[i]);
        }
        tot += mn;
        //cout << j << " -> " << mn << endl;
    }
    
    cout << tot << endl;
    
    return 0;
}