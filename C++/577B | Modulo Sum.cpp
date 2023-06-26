#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
 int n, m;
 cin >> n >> m;
 
 vector<ll> a(n);
 
 for(int i=0; i<n; i++)
     cin >> a[i];
     
 if(n > m)
 {
     ll sum = 0;
     vector<bool> mark(m,0);
     for(int i=0; i<n; i++)
     {
         sum = (sum + a[i])%m;
         if(mark[sum])
         {
             cout << "YES" << endl;
             return 0;
         }
         else 
             mark[sum] = true;
     }
     cout << "NO" << endl;
 }
 else 
 {
     vector< vector<bool> > dp(n,vector<bool>(m,0));
     for(int i=0; i<n; i++)
         dp[i][(a[i]%m)] = 1;
     for(int i=1; i<n; i++)
     {
         for(int j=0; j<m; j++)
         {
             dp[i][j] = dp[i][j] || dp[i-1][j] || dp[i-1][(j+m-(a[i]%m))%m];
         }
     }
     if(dp[n-1][0])
         cout << "YES" << endl;
     else 
         cout << "NO" << endl;
 }
 
 return 0;
}