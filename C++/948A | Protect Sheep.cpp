#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MAX 30
#define MOD 107
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
int main()
{
   int n, m;
   scanf("%d %d", &n, &m);
 
   char grid[n][m+1];
 
   for(int i=0; i<n; i++)
      scanf("%s", grid[i]);
 
   for(int i=0; i<n; i++)
   {
      for(int j=0; j<m; j++)
      {
         if(grid[i][j] == 'W')
         {
            for(int k=0; k<4; k++)
            {
               if(i+dx[k]<0 || i+dx[k]>=n || j+dy[k]<0 || j+dy[k]>=m) continue;
               if(grid[i+dx[k]][j+dy[k]] == 'S')
               {
                  puts("No");
                  return 0;
               }
               if(grid[i+dx[k]][j+dy[k]] == 'W') continue;
               grid[i+dx[k]][j+dy[k]] = 'D';
            }
         }
      }
   }
 
   puts("Yes");
   for(int i=0; i<n; i++)
      puts(grid[i]);
 
   return 0;
}
 
 
 
 
 
 
 
 
 