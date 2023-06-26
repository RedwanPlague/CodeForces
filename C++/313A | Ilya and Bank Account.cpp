#include <stdio.h>
int main()
{
   int S, a, b;
   scanf("%d", &S);
   if(S<0) {
      a=10*(S/100)+S%10;
      b=S/10;
      S=(a>b)?a:b;
   }
   printf("%d", S);
   return 0;
}