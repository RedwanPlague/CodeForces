#include <stdio.h>
int main()
{
   int n, m, d=0;
   scanf("%d %d", &n, &m);
   while(n>=m)
   {
      n = n-m+1;
      d += m;
   }
   d += n;
   printf("%d\n", d);
   return 0;
}