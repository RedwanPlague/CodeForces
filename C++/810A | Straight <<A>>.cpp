#include <stdio.h>
int main()
{
   int n, i, c=0;
   double a, S=0, k;
   scanf("%d %lf", &n, &k);
   for(i=0; i<n; i++) {
      scanf("%lf", &a);
      S+=a;
   }
   while(S/n<k-0.5) {
      S+=k; n++; c++;
   }
   printf("%d\n", c);
   return 0;
}