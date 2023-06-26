#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   ll n, ts, tf, t, i, time=1e18, need, que;
   scanf("%lld %lld %lld", &ts, &tf, &t);
   scanf("%lld", &n);
   ll a[n+2], b[n+1];
   b[0]=ts;
   for(i=1; i<=n; i++) {
      scanf("%lld", &a[i]);
      b[i]=max(b[i-1],a[i])+t;
   }
   que=ts;
   a[n+1]=b[n]+1;
   for(i=1; i<=n+1; i++) {
      if(a[i]-1>=b[i-1]) need = 0;
      else need = b[i-1]-a[i]+1;
      if(time>need && a[i]-1<=tf-t && a[i]-1>=0) {
         time=need;
         que=a[i]-1;
      }
   }
   printf("%lld", que);
   return 0;
}