#include <stdio.h>
#define MAX 200001
int rec[MAX], sum[MAX];
int main()
{
   int n, k, q, l, r;
   scanf("%d %d %d", &n, &k, &q);
   while(n--) {
      scanf("%d %d", &l, &r);
      rec[l]++;
      rec[r+1]--;
   }
   for(int i=1; i<MAX; i++) {
      rec[i]+=rec[i-1];
      sum[i]+=sum[i-1];
      if(rec[i]>=k) sum[i]++;
   }
   while(q--) {
      scanf("%d %d", &l, &r);
      printf("%d\n", sum[r]-sum[l-1]);
   }
   return 0;
}