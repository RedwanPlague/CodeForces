#include <stdio.h>
 
int fc(int N)
{
   int j;
   for(j=2; j<=N; j++)
      if(N%j==0)
         return j;
}
 
int fact(int N)
{
   int i=2, c=0;
   while(i<=N) {
      if(N%i==0) {
         c++;
         N /= i;
      }
      else
         i++;
   }
   return c;
}
 
int main()
{
   int N, k, i;
   scanf("%d %d", &N, &k);
   if(k==1)
      printf("%d\n", N);
   else if(k>fact(N))
      printf("-1\n");
   else {
      i=0;
      while(i<(k-1)) {
         printf("%d ", fc(N));
         i++;
         N = N/fc(N);
      }
   printf("%d\n", N);
   }
   return 0;
}