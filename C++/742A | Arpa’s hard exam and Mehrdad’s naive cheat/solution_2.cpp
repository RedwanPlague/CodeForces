#include <stdio.h>
 
int bigmod(int a, int b, int m)
{
   if(b==0) return 1%m;
   int x = bigmod(a,b/2,m);
   x = (x*x)%m;
   if(b%2) x = (x*a)%m;
   return x;
}
 
int main()
{
   int b;
   scanf("%d", &b);
   printf("%d\n", bigmod(1378,b,10));
   return 0;
}