#include <bits/stdc++.h>
using namespace std;
 
int n;
string board[401];
string grid[4][101];
 
int minFlip(int mask)
{
   if(mask == 15)
      return 0;
 
   int ret = 10000000;
   int num = 0;
   for(int i=0; i<4; i++)
      if(mask&(1<<i))
         num++;
 
   for(int i=0; i<4; i++)
   {
      if(mask&(1<<i))
         continue;
      int diff = 0;
      for(int j=0; j<n; j++)
      {
         for(int k=0; k<n; k++)
         {
            if(grid[i][j][k] != board[num*n+j][k])
               diff++;
         }
      }
      ret = min(ret, diff + minFlip(mask | (1<<i)));
   }
   return ret;
}
 
int main()
{
   ios_base::sync_with_stdio(0);
 
   cin>>n;
 
   for(int i=0; i<4; i++)
   {
      for(int j=0; j<n; j++)
         cin>>grid[i][j];
   }
 
   int ans = 10000000;
 
   for(int i=0; i<4*n; i++)
   {
      for(int j=0; j<n; j++)
      {
         if((i+j)&1)
            board[i] += '1';
         else
            board[i] += '0';
      }
   }
 
   ans = min(ans, minFlip(0));
 
   for(int i=0; i<4*n; i++)
   {
      for(int j=0; j<n; j++)
      {
         if((i+j)&1)
            board[i][j] = '0';
         else
            board[i][j] = '1';
      }
   }
 
   cout<<min(ans, minFlip(0))<<endl;
 
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 