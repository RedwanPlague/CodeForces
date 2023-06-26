#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MOD 109
#define MAX 107
 
int main()
{
   int n, m;
   cin>>n>>m;
   ll a[n], b[m];
   for(int i=0; i<n; i++)
      cin>>a[i];
   for(int i=0; i<m; i++)
      cin>>b[i];
 
   ll ans = (1LL<<62);
   ll maxNum;
 
   for(int idx = 0; idx < n; idx++)
   {
      maxNum = (-1LL<<62);
      for(int i=0; i<n; i++)
      {
         if(i == idx)
            continue;
         for(int j=0; j<m; j++)
         {
            maxNum = max(maxNum, a[i]*b[j]);
         }
      }
      ans = min(ans, maxNum);
   }
 
   cout<<ans<<endl;
 
   return 0;
}