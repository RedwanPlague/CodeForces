#include <stdio.h>
 
int gcd(int a, int b)
{
    while (b != 0)
    {
        a %= b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
 
    return a;
}
 
int main()
{
   int a, b, n;
   scanf("%d %d %d", &a, &b, &n);
   do {
      n -= gcd(a,n);
      if(n<0) {
         printf("1");
         break;
      }
      n -= gcd(b,n);
      if(n<0) {
         printf("0");
         break;
      }
   } while(1);
   return 0;
}