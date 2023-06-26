#include <stdio.h>
int main()
{
   int n, a[105], i;
   int sg = 1;
   scanf("%d", &n);
   for(i=0; i<n; i++)
      scanf("%d", &a[i]);
   for(i=0; i+1<n; i++)
   {
      if(sg==1)
      {
         if(a[i+1]==a[i])
            sg = 2;
         else if(a[i]>a[i+1])
            sg = 3;
      }
      else if(sg==2)
      {
         if(a[i]>a[i+1])
            sg = 3;
         else if(a[i]<a[i+1])
         {
            puts("NO");
            return 0;
         }
      }
      else
      {
         if(a[i]<=a[i+1])
         {
            puts("NO");
            return 0;
         }
      }
   }
   puts("YES");
   return 0;
}