#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n, k, i, j;
   cin>>n>>k;
   int a[n], b[k];
   for(i=0; i<n; i++) cin>>a[i];
   for(i=0; i<k; i++) cin>>b[i];
   sort(b,b+k);
   reverse(b,b+k);
   for(i=0, j=0; i<n&&j<k; i++) {
      if(a[i]==0) a[i]=b[j++];
   }
   for(i=1; i<n; i++) if(a[i]<=a[i-1]) {
      printf("YES");
      return 0;
   }
   printf("NO");
   return 0;
}