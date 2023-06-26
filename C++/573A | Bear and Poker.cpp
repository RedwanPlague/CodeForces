#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n, i, gcd;
   cin>>n;
   int a[n];
   cin>>a[0];
   gcd=a[0];
   for(i=1; i<n; i++) {
      cin>>a[i];
      gcd=__gcd(gcd,a[i]);
   }
   for(i=0; i<n; i++) {
      a[i]/=gcd;
      while(a[i]%2==0) a[i]/=2;
      while(a[i]%3==0) a[i]/=3;
      if(a[i]>1) {
         printf("No");
         return 0;
      }
   }
   printf("Yes");
   return 0;
}