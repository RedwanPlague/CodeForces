#include <stdio.h>
int main()
{
   int l, r, i, a;
   scanf("%d %d", &l, &r);
   if(r-l>2)
      a=2;
   else if(r-l==2 && l%2==0)
      a=2;
   else
      a=l;
   printf("%d\n", a);
   return 0;
}