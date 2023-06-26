#include <bits/stdc++.h>
 
#define br '\n'
 
using namespace std;
 
typedef long long ll;
 
const int MX = 1005;
const int MOD = 998244353;
 
ll same[MX][2*MX], diff[MX][2*MX];
 
int main()
{
    int n, k;
    cin >> n >> k;
 
    for(int i=1; i<=n; i++)
    {
        same[i][1] = 2;
    }
    diff[1][2] = 2;
 
    for(int i=2; i<=n; i++)
    {
        for(int j=2; j<=2*n; j++)
        {
            same[i][j] = (same[i-1][j] + same[i-1][j-1] + 2*diff[i-1][j]) % MOD;
            diff[i][j] = (2*same[i-1][j-1] +diff[i-1][j] + diff[i-1][j-2]) %MOD;
        }
    }
 
    /*for(int i=1; i<=2*n; i++)
    {
        for(int j=1; j<=n; j++)
            printf("%3d ", same[j][i]);
        cout << br;
    }
    cout << br;
 
    for(int i=1; i<=2*n; i++)
    {
        for(int j=1; j<=n; j++)
            printf("%3d ", diff[j][i]);
        cout << br;
    }
    cout << br;*/
 
    cout << (same[n][k] + diff[n][k])%MOD << endl;
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 