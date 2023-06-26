#include <stdio.h>
 
int main()
{
   int n, i, j;
   scanf("%d", &n);
   int a, fell[n+1]={0};
   j=n;
   for(i=0; i<n; i++) {
      scanf("%d", &a);
      fell[a]=1;
      while(fell[j]!=0) printf("%d ", j--);
      putchar('\n');
   }
   return 0;
}