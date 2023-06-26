#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
 
typedef pair<int,int> ii;
 
#define MAX 105
 
int V, E;
vector <ii> edge[MAX];
int dp[MAX][MAX][26];
 
bool solve(int u, int v, int c)
{
   if(dp[u][v][c] != -1)
      return dp[u][v][c];
 
   bool found = false;
 
   for(int i=0; i<edge[u].size(); i++)
   {
      int x = edge[u][i].first;
      int w = edge[u][i].second;
      if(w >= c && !solve(v, x, w))
         found = true;
   }
   //cout<<u<<' '<<v<<" = "<<found<<'\n';
   return ( dp[u][v][c] = found );
}
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   int u, v;
   char c;
 
   cin>>V>>E;
   for(int i=0; i<E; i++)
   {
      cin>>u>>v>>c;
      edge[u].push_back(make_pair(v,c-'a'));
   }
 
   memset(dp, -1, sizeof(dp));
 
   for(int i=1; i<=V; i++)
   {
      for(int j=1; j<=V; j++)
      {
         //solve(i,j,0);
         if(solve(i,j,0))
            cout<<'A';
         else
            cout<<'B';
      }
      cout<<'\n';
   }
 
   return 0;
}
 