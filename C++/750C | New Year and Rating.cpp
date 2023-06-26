#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
#define INF 1e18
typedef struct {
   ll l, h;
} interval;
 
int main()
{
   ll n, i, j;
   cin>>n;
   ll rt, cum[n+1], div;
   interval inv[n];
   cum[0]=0;
   for(i=0; i<n; i++) {
      cin>>rt>>div;
      cum[i+1]=cum[i]+rt;
      if(div==1) {
         inv[i].l=1900-cum[i];
         inv[i].h=INF;
      }
      else {
         inv[i].l=-INF;
         inv[i].h=1899-cum[i];
      }
   }
   interval ans;
   ans=inv[0];
   for(i=1; i<n; i++) {
      ans.l=max(ans.l,inv[i].l);
      ans.h=min(ans.h,inv[i].h);
      if(ans.l>ans.h) {
         puts("Impossible");
         return 0;
      }
   }
   if(ans.h==INF) puts("Infinity");
   else cout<<ans.h+cum[n]<<endl;
   return 0;
}
 