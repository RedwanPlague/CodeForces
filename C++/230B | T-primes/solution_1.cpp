#include <stdio.h>
#include <math.h>
#define MAX 1000001
#define ll long long
int a[MAX];
 
void make()
{
   int i, j;
   a[1]=1;
   int lim=sqrt(MAX);
   for(i=4; i<MAX; i+=2) a[i]=1;
   for(i=3; i<=lim; i+=2) {
      if(!a[i]) {
      for(j=i*i; j<MAX; j+=2*i)
         a[j]=1;
      }
   }
}
 
int main()
{
   int i, n;
   ll tp, root;
   make();
   //for(i=988000; i<988030; i++) if(!a[i]) printf("%d ", i);
   scanf("%d", &n);
   while(n--) {
      scanf("%I64d", &tp);
      root = sqrt(tp);
      if(!a[root] && root*root==tp) puts("YES");
      else puts("NO");
   }
   return 0;
}