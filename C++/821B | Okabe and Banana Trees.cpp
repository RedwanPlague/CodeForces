#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
 
int main()
{
   ll m, b, i, j;
   cin>>m>>b;
   ll x = 0, y = b;
   /*for(i=0; i<=m*b; i+=m) {
      if((x+1)*(y+1)<(i+1)*(-i/m+b+1)) {
         x=i;
         y=-i/m+b;
      }
   }*/
   //if(x<y) swap(x,y);
   ll ansm = 0, mx, ans;
   for(j=0; j<=m*b; j+=m) {
   x=j; y=-j/m+b; mx=x+y;
   if(x<y) swap(x,y);
   ans = (y*(y+1)*(y+2))/3;
   //cout<<ans<<endl;
   y++;
   ans += y*((x*(x-1))/2-(y*(y-1))/2);
   //cout<<ans<<endl;
   for(i=x; i<=mx; i++, y--) ans += i*y;
   if(ansm<ans) ansm=ans;
   }
   cout<<ansm<<endl;
   return 0;
}