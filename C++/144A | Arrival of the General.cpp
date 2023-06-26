#include <stdio.h>
int main()
{
   int a[100], N , i, mn=200, mx=-1, j, k, moves;
   scanf("%d", &N);
   for(i=0; i<N; i++)
      scanf("%d", &a[i]);
   for(i=N-1; i>=0; i--) {
      if(mx <= a[i]) {
         mx = a[i];
         j = i;
      }
   }
   for(i=0; i<N; i++) {
      if(mn >= a[i]) {
         mn = a[i];
         k = i;
      }
   }
   moves = j + (N-1-k);
   if(k<j)
      moves--;
   printf("%d\n", moves);
   return 0;
}