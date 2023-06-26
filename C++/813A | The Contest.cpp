#include <stdio.h>
int main()
{
   int n, i, m, time, S=0;
   scanf("%d", &n);
   for(i=0; i<n; i++) {
      scanf("%d", &time);
      S+=time;
   }
   scanf("%d", &m);
   int tm[m][2];
   for(i=0; i<m; i++) scanf("%d %d", &tm[i][0], &tm[i][1]);
   for(i=0; i<m; i++) {
      if(S>=tm[i][0] && S<=tm[i][1]) {
         printf("%d", S);
         return 0;
      }
      if(S<tm[i][0]) {
         printf("%d", tm[i][0]);
         return 0;
      }
   }
   printf("-1");
   return 0;
}