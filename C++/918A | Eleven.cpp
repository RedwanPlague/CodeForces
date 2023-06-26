#include <cstdio>
#include <cstring>
 
int main()
{
   bool fib[1005];
   memset(fib, false, sizeof(fib));
   fib[1] = true;
   for(int a = 1, b = 1, c = 2; c <= 1000; a = b, b = c, c = a + b)
   {
      fib[c] = true;
   }
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++)
   {
      if(fib[i])
         putchar('O');
      else
         putchar('o');
   }
   return 0;
}
 
 