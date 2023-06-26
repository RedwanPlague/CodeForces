#include <stdio.h>
int main()
{
   int n, x, i;
   scanf("%d", &n);
   scanf("%d", &x);
   n%=6;
   int a[3][6]={0,1,2,2,1,0,1,0,0,1,2,2,2,2,1,0,0,1};
   for(i=0; i<3; i++) if(a[i][n]==x) break;
   printf("%d", i);
   return 0;
}