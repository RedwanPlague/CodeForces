#include <iostream>
#include <algorithm>
using namespace std;
 
int n, m, sx, sy;
char grid[51][51];
string ins, dir;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
bool isCorrect()
{
   for(int i=0, x = sx, y = sy; i<ins.length(); i++)
   {
      x += dx[dir[ins[i]-'0']-'0'];
      y += dy[dir[ins[i]-'0']-'0'];
      if(x<0 || x>=n || y<0 || y>=m || grid[x][y] == '#')
         return 0;
      if(grid[x][y] == 'E')
         return 1;
   }
   return 0;
}
 
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
   cin>>n>>m;
 
   for(int i=0; i<n; i++)
   {
      for(int j=0; j<m; j++)
      {
         cin>>grid[i][j];
         if(grid[i][j] == 'S')
         {
            sx = i;
            sy = j;
         }
         //cout<<grid[i][j];
      }
      //cout<<'\n';
   }
   cin>>ins;
   dir = "0123";
 
   int cnt = isCorrect();
 
   while(next_permutation(dir.begin(), dir.end()))
   {
      cnt += isCorrect();
   }
 
   cout<<cnt<<endl;
 
   return 0;
}