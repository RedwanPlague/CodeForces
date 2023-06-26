#include <stdio.h>
#include <string.h>
int main()
{
   int i, n, a[6], b[6], gr;
   memset(a,0,sizeof(a));
   memset(b,0,sizeof(b));
   scanf("%d", &n);
   for(i=0; i<n; i++) {
      scanf("%d", &gr);
      a[gr]++;
   }
   for(i=0; i<n; i++) {
      scanf("%d", &gr);
      b[gr]++;
   }
   for(i=1; i<=5; i++)
    if((a[i]+b[i])%2) {
      printf("-1");
      return 0;
   }
   int time=0;
   for(i=1; i<=5; i++) if(a[i]>b[i]) time+=(a[i]-b[i])/2;
   printf("%d", time);
   return 0;
}