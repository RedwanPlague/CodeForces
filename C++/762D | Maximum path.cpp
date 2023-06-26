#include <iostream>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
const int MX = 100005;
 
ll grid[MX][3];
ll dp[MX][5];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int N;
    cin>>N;
 
    for(int j=0; j<3; j++)
        for(int i=0; i<N; i++)
            cin>>grid[i][j];
 
    dp[0][2] = grid[0][0];
    dp[0][3] = grid[0][0] + grid[0][1];
    dp[0][0] = dp[0][1] = dp[0][4] =  grid[0][0] + grid[0][1] + grid[0][2];
 
    for(int i=1; i<N; i++)
    {
        dp[i][0] = dp[i-1][2] + grid[i][0] + grid[i][1] + grid[i][2];
        dp[i][1] = dp[i-1][4] + grid[i][1] + grid[i][0] + grid[i][2];
        dp[i][2] = max( max( max( dp[i-1][1] + grid[i][0] + grid[i][1] + grid[i][2], dp[i-1][2] + grid[i][0] ), dp[i-1][3] + grid[i][0] + grid[i][1] ), dp[i-1][4] + grid[i][0] + grid[i][1] + grid[i][2]);
        dp[i][3] = max( max( dp[i-1][2] + grid[i][0] + grid[i][1], dp[i-1][3] + grid[i][1] ), dp[i-1][4] + grid[i][1] + grid[i][2]);
        dp[i][4] = max( max( max( dp[i-1][0] + grid[i][0] + grid[i][1] + grid[i][2], dp[i-1][4] + grid[i][2] ), dp[i-1][3] + grid[i][2] + grid[i][1] ), dp[i-1][2] + grid[i][0] + grid[i][1] + grid[i][2]);
    }
 
    /*for(int way=0; way<5; way++)
    {
        for(int i=0; i<N; i++)
            cout<<dp[i][way]<<' ';
        cout<<endl;
    }*/
 
    cout<<dp[N-1][4]<<endl;
 
    return 0;
}