#include <stdio.h>
#include <string.h>
int main()
{
   int n, m, k, who, index;
   scanf("%d %d", &n, &m);
   char a[2][n+1], traitor, confirm=0;
   while(m--) {
      scanf("%d", &k);
      memset(a[0],0,n+1);
      memset(a[1],0,n+1);
      traitor=1;
      while(k--) {
         scanf("%d", &who);
         index=(who<0)?-who:who;
         if(who<0) a[0][index]++;
         else a[1][index]++;
         if(a[0][index]>0 && a[1][index]>0) traitor=0;
      }
      if(traitor) confirm=1;
   }
   if(confirm) printf("YES");
   else printf("NO");
   return 0;
}