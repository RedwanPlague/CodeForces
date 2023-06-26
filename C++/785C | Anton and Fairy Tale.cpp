#include <stdio.h>
#include <math.h>
#define ull unsigned long long
int main()
{
   ull n, m, k;
   scanf("%llu %llu", &n, &m);
   if(m>=n-1) k=n;
   else {
      n-=m;
      ull lo=0, hi=2e9;
      while(lo<hi) {
         k=(lo+hi)/2;
         if(k*(k+1)/2>=n) hi=k;
         else lo=k+1;
      }
      k=lo+m;
   }
   printf("%llu", k);
}