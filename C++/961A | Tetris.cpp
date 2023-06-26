#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 107
 
int main()
{
   ios_base::sync_with_stdio(0);
 
   int n, m, a;
   cin>>n>>m;
   int col[n];
   memset(col, 0, sizeof(col));
 
   int ans = 0;
 
   for(int i=0; i<m; i++)
   {
      cin>>a;
      col[a-1]++;
      bool full = true;
      /*for(int j=0; j<n; j++)
         cout<<col[j]<<' ';
      cout<<endl;*/
      for(int j=0; j<n; j++)
      {
         if(col[j] == 0)
         {
            full = false;
            break;
         }
      }
      if(full)
      {
         ans++;
         for(int j=0; j<n; j++)
            col[j]--;
      }
   }
 
   cout<<ans<<endl;
 
   return 0;
}
 
 