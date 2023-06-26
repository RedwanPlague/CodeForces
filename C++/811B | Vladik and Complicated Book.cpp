#include <stdio.h>
int main()
{
   int i, n, m, l, r, x, le, ri;
   scanf("%d %d", &n, &m);
   int a[n];
   for(i=0; i<n; i++)
      scanf("%d", &a[i]);
   while(m--) {
      scanf("%d %d %d", &l, &r, &x);
      l--; r--; x--; le=0; ri=0;
      for(i=l; i<=r; i++) {
         if(a[i]<a[x]) le++;
         else ri++;
      }
      ri--;
      if(ri==r-x && le==x-l) printf("Yes\n");
      else printf("No\n");
   }
   return 0;
}