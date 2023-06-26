#include <stdio.h>
 
int main()
{
   int n, i, j, h[30], g[30], cnt=0;
   scanf("%d", &n);
   for(i=0; i<n; i++)
      scanf("%d %d", &h[i], &g[i]);
   for(i=0; i<(n-1); i++)
   for(j=i+1; j<n; j++) {
      if(h[i]==g[j])
         cnt++;
      if(g[i]==h[j])
         cnt++;
   }
   printf("%d\n", cnt);
   return 0;
}