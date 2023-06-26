#include <stdio.h>
int main()
{
   int n, i, sx=0, sy=0;
   scanf("%d", &n);
   int x[n], y[n];
   for(i=0; i<n; i++) {
      scanf("%d %d", &x[i], &y[i]);
      sx+=x[i];
      sy+=y[i];
   }
   if(sx%2==0 && sy%2==0) putchar('0');
   else {
      for(i=0; i<n; i++) {
         if((x[i]+y[i])%2) {
            sx+=y[i]-x[i];
            sy+=x[i]-y[i];
            break;
         }
      }
      if(sx%2==0 && sy%2==0) putchar('1');
      else puts("-1");
   }
   return 0;
}