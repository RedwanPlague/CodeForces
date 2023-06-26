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
   int n, i, j, x, y, f=1, c;
   cin>>n;
   int a[n][n];
   for(i=0; i<n; i++) for(j=0; j<n; j++) cin>>a[i][j];
   for(i=0; i<n; i++) for(j=0; j<n; j++) {
      if(a[i][j]!=1) {
      c=0;
      for(x=0; x<n; x++) for(y=0; y<n; y++) if(a[i][x]+a[y][j]==a[i][j]) c=1;
      if(c==0) f=0;
      }
   }
   if(f==1) puts("Yes");
   else puts("No");
   return 0;
}
 