#include <stdio.h>
int main()
{
   unsigned long long n, k;
   scanf("%I64d %I64d", &n, &k);
   n = (n+1)/2;
   if(k>n)
      printf("%I64d\n", 2*(k-n));
   else
      printf("%I64d\n", 2*k-1);
   return 0;
}