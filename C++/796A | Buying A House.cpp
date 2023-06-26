#include <stdio.h>
int main()
{
   int n, m, k, i, j;
   scanf("%d %d %d", &n, &m, &k);
   m--;
   int a[n];
   for(i=0; i<n; i++)
      scanf("%d", &a[i]);
   for(i=m; i<n; i++)
      if(a[i] && a[i]<=k) break;
   for(j=m; j>=0; j--)
      if(a[j] && a[j]<=k) break;
   if(i==n) i=1000000;
   if(j<0) j=-1000000;
   i = (i-m)<(m-j)?(i-m):(m-j);
   printf("%d", 10*i);
   return 0;
}