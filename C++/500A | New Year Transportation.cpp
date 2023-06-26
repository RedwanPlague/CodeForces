#include <stdio.h>
int main()
{
   int i, n, t;
   scanf("%d %d", &n, &t);
   int a[n-1];
   for(i=0; i<n-1; i++) scanf("%d", &a[i]);
   i=0; t--;
   while(i<n) {
      i+=a[i];
      if(i==t) {
         printf("YES");
         return 0;
      }
   }
   printf("NO");
   return 0;
}