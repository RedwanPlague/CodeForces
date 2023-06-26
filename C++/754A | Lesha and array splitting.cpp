#include <stdio.h>
int main()
{
   int n, S=0;
   scanf("%d", &n);
   int i, a[n];
   for(i=0; i<n; i++) scanf("%d", &a[i]);
   for(i=0; i<n; i++) if(a[i]!=0) S=1;
   if(!S) {
      printf("NO\n");
      return 0;
   }
   printf("YES\n");
   S=0;
   for(i=0; i<n; i++) S+=a[i];
   if(S) {
      printf("1\n1 %d\n", n);
      return 0;
   }
   S=0;
   for(i=0; i<n; i++) {
      S+=a[i];
      if(S) break;
   }
   printf("2\n%d %d\n%d %d\n", 1, i+1, i+2, n);
   return 0;
}