#include <stdio.h>
int main()
{
   int n, x, i, c=0;
   scanf("%d %d", &n, &x);
   for(i=1; i<=n; i++) {
      if(x%i==0 && x/i<=n) c++;
   }
   printf("%d", c);
   return 0;
}