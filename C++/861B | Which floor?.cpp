#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[101];
int main()
{
 int n, m, i, j;
 int ki, fi;
 cin>>n>>m;
 for(i=0; i<m; i++)
   {
      cin>>ki>>fi;
      a[ki] = fi;
   }
   int ans = 0;
   for(i=1; i<110; i++)
   {
      for(j=1; j<=100; j++)
      {
         if(a[j] && ((j-1)/i+1)!=a[j])
            break;
      }
      if(j==101)
      {
         if(!ans)
            ans = (n-1)/i+1;
         else if(ans != (n-1)/i+1)
         {
            puts("-1");
            return 0;
         }
      }
   }
   cout<<ans<<endl;
 return 0;
}