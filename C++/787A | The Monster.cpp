#include <stdio.h>
int main()
{
   int a, b, c, d, i, t;
   scanf("%d %d", &a, &b);
   scanf("%d %d", &c, &d);
   if(d>b) {
       b=b^d; d=b^d; b=b^d;
       a=a^c; c=a^c; a=a^c;
   }
   for(i=0; i<1e6; i++) {
      t=b+i*a;
      if((t-d)%c==0) {
         printf("%d", t);
         return 0;
      }
   }
   printf("-1");
   return 0;
}