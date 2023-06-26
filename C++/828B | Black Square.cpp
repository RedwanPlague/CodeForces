#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[105][105];
int main()
{
 int n, m, color=0;
 int lc, rc, ur, lr;
 int i, j;
 cin>>n>>m;
 for(i=0; i<n; i++)
      scanf("%s", a[i]);
   for(i=0; i<n; i++) {
      for(j=0; j<m; j++) {
         if(a[i][j]=='B')
            goto here1;
      }
   }
   here1:
   ur = i;
   for(i=n-1; i>=0; i--) {
      for(j=0; j<m; j++) {
         if(a[i][j]=='B')
            goto here2;
      }
   }
   here2:
   lr = i;
   for(j=0; j<m; j++) {
      for(i=0; i<n; i++) {
         if(a[i][j]=='B')
            goto here3;
      }
   }
   here3:
   lc = j;
   for(j=m-1; j>=0; j--) {
      for(i=0; i<n; i++) {
         if(a[i][j]=='B')
            goto here4;
      }
   }
   here4:
   rc = j;
   color = max(lr-ur+1,rc-lc+1);
   if(color>min(m,n)) {
      puts("-1");
      return 0;
   }
   if(lc>=m || rc<0 || ur>=n || lr<0) {
      puts("1");
      return 0;
   }
   color *= color;
   for(i=ur; i<=lr; i++) {
      for(j=lc; j<=rc; j++) {
         if(a[i][j]=='B')
            color--;
      }
   }
   cout<<color<<endl;
 return 0;
}