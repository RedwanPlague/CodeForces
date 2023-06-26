#include <stdio.h>
int main()
{
   int x, n, teams=0;
   scanf("%d %d", &x, &n);
   while(x>0 && n>0) {
      x--;
      n--;
      if(n>x) n--;
      else x--;
      if(x<0 || n<0) break;
      teams++;
   }
   printf("%d", teams);
   return 0;
}