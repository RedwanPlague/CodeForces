#include <stdio.h>
 
int main()
{
   int n, i, a, b, grp=1;
   scanf("%d", &n);
   scanf("%d", &a);
   for(i=1; i<n; i++) {
      scanf("%d", &b);
      if(a!=b)
         grp++;
      a=b;
   }
   printf("%d\n", grp);
   return 0;
}