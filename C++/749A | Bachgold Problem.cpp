#include <stdio.h>
int main()
{
   int n;
   scanf("%d", &n);
   printf("%d\n", n>>1);
   if(n%2) printf("3 "), n-=3;
   n>>=1;
   while(n--) printf("2 ");
   return 0;
}