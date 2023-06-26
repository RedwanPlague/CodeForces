#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main()
{
   int n, m;
   cin>>n>>m;
   vector <string> grid(n);
   for(int i=0; i<n; i++)
      cin>>grid[i];
 
   bool valid = true;
 
   for(int i=0; i<n; i++)
   {
      for(int j=0; j<m; j++)
      {
         if(grid[i][j] == '.')
            continue;
 
         for(int k=0; k<n; k++)
         {
            if(grid[k][j] == '#' && grid[k] != grid[i])
               valid = false;
         }
 
      }
   }
 
   if(valid)
      cout<<"Yes"<<endl;
   else
      cout<<"No"<<endl;
 
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 