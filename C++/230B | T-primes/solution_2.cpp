#include <stdio.h>
#include <math.h>
#define MAX 1000000
char mark[MAX];
void make()
{
   int i, j, limit=sqrt(MAX+1);
   mark[1]=1;
   for(i=4; i<=MAX; i+=2)
      mark[i]=1;
   for(i=3; i<=MAX; i+=2) {
      if(!mark[i] && i<=limit) {
         for(j=i*i; j<=MAX; j+=2*i)
            mark[j]=1;
      }
   }
}
 
int main()
{
   make();
   int n;
   double x, y;
   scanf("%d", &n);
   while(n--) {
      scanf("%lf", &x);
      y=sqrt(x);
      if(y-(int)y==0 && !mark[(int)y]) printf("YES\n");
      else printf("NO\n");
   }
   return 0;
}