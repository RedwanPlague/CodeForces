#include <stdio.h>
#define ll long long
ll value(ll n)
{
   ll s=n;
   while(n) {
      s-=n%10;
      n/=10;
   }
   return s;
}
int main()
{
   ll n, s;
   scanf("%lld %lld", &n, &s);
   ll k, lo=1, hi=n;
   while(lo<hi) {
      k=(lo+hi)/2;
      if(value(k)>=s) hi=k;
      else lo=k+1;
   }
   if(value(n)>=s) n++;
   printf("%lld\n", n-lo);
   return 0;
}