#include <cstdio>
 
int main()
{
   int n, m, l, r;
   scanf("%d", &n);
   int a[n];
   for(int i=0; i<n; i++)
      scanf("%d", &a[i]);
 
   char ans[2][5] = {"even", "odd"};
   int cnt = 0;
 
   for(int i=0; i<n; i++)
   {
      for(int j=i+1; j<n; j++)
      {
         if(a[j]<a[i])
            cnt++;
      }
   }
 
   scanf("%d", &m);
   for(int k=0; k<m; k++)
   {
      scanf("%d %d", &l, &r);
      if( ((r-l+1)>>1)&1 )  // divided by two, then checked if odd
         cnt++;
      puts(ans[cnt&1]);
   }
   return 0;
}