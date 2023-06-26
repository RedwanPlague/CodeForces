#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n, i, j;
   cin>>n;
   int ar[105], odd[55], even[55];
   ar[0] = 0;
   for(i=1; i<=2*n; i++)
      cin>>ar[i];
   sort(ar,ar+2*n+1);
   even[0] = 0;
   for(i=1, j=1; j<=n; i += 2, j++)
   {
      even[j] = even[j-1]+ar[i+1]-ar[i];
   }
   odd[0] = 0;
   for(i=2, j=1; j<n; i += 2, j++)
   {
      odd[j] = odd[j-1]+ar[i+1]-ar[i];
   }
   int ans, minAns = 1<<30;
   for(i=1; i<2*n; i+=2)
   {
      for(j=i+1; j<=2*n; j+=2)
      {
         ans = even[i/2]+odd[j/2-1]-odd[(i-1)/2]+even[n]-even[(j+1)/2];
         minAns = min(minAns,ans);
      }
   }
   cout<<minAns<<endl;
   return 0;
}