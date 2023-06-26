#include <iostream>
#include <cstring>
using namespace std;
 
#define MOD 1000000007
 
int k, d;
int dp[2][101];
 
int ways(int state, int n)
{
   if(!n)
      return state;
   if(dp[state][n]!=-1)
      return dp[state][n];
   dp[state][n] = 0;
   for(int i=1; i<=k && i<=n; i++)
   {
      dp[state][n] += ways(state || i>=d, n-i);
      dp[state][n] %= MOD;
   }
   return dp[state][n];
}
 
int main()
{
   int n;
   cin>>n>>k>>d;
   memset(dp,-1,sizeof(dp));
   cout<<ways(0,n);
   return 0;
}