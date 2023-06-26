#include <stdio.h>
 
int ceil(int w, int k)
{
   int c;
   c = w/k ;
   if(w%k)
      c++;
   return c;
}
 
int main()
{
   int n, k, i, j, D=0;
   scanf("%d %d", &n, &k);
   int w[n];
   for(i=0; i<n; i++) {
      scanf("%d", &w[i]);
      D += ceil(w[i], k);
   }
   D = ceil(D,2);
   printf("%d", D);
   return 0;
}