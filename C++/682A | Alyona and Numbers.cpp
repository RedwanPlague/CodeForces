#include <stdio.h>
int main()
{
   int a, b;
   unsigned long long n=0;
   scanf("%d %d", &a, &b);
   if(a>b) {
      a=a^b;
      b=a^b;
      a=a^b;
   }
   for(int i=1; i<=a; i++) n+=((b+i)/5-i/5);
   printf("%llu", n);
   return 0;
}