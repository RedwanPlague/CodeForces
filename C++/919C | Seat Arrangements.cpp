#include <cstdio>
#include <cstring>
 
int ways(int r, int l)
{
   if(r<l)
      return 0;
   return (r-l+1);
}
 
int main()
{
   int n, m, k;
   scanf("%d %d %d", &n, &m, &k);
   char grid[n][m+1];
   for(int i=0; i<n; i++)
   {
      scanf("%s", grid[i]);
   }
 
   long long ans = 0;
   int count;
 
   if(k == 1)
   {
      for(int i=0; i<n; i++)
         for(int j=0; j<m; j++)
            if(grid[i][j] == '.')
               ans++;
      printf("%d\n", ans);
      return 0;
   }
 
   for(int i=0; i<n; i++)
   {
      count = 0;
      for(int j=0; j<m; j++)
      {
         if(grid[i][j] == '*')
         {
            ans += ways(count,k);
            count = 0;
         }
         else
            count++;
      }
      ans += ways(count,k);
   }
 
   for(int j=0; j<m; j++)
   {
      count = 0;
      for(int i=0; i<n; i++)
      {
         if(grid[i][j] == '*')
         {
            ans += ways(count,k);
            count = 0;
         }
         else
            count++;
      }
      ans += ways(count,k);
   }
 
   printf("%d\n", ans);
 
   return 0;
}