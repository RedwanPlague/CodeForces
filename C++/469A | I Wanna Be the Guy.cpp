#include <stdio.h>
 
int main()
{
   int p, q, i, N, a[101]={0}, b;
   scanf("%d", &N);
   scanf("%d", &p);
   for(i=0; i<p; i++) {
      scanf("%d", &b);
      a[b]++;
   }
   scanf("%d", &q);
   for(i=0; i<q; i++) {
      scanf("%d", &b);
      a[b]++;
   }
   for(i=1; i<=N; i++) {
      if(a[i]==0)
         break;
   }
   if(i>N)
      printf("I become the guy.\n");
   else
      printf("Oh, my keyboard!\n");
   return 0;
}