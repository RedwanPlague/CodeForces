#include <stdio.h>
int main()
{
   int N, i;
   scanf("%d", &N);
   int a[N], b[N];
   for(i=0; i<N; i++)
      scanf("%d %d", &a[i], &b[i]);
   for(i=0; i<N; i++)
   if(a[i]!=b[i]) {
      printf("rated\n");
      return 0;
   }
   for(i=1; i<N; i++)
   if(a[i]>a[i-1]) {
      printf("unrated\n");
      return 0;
   }
   printf("maybe\n");
   return 0;
}