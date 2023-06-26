#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
 
#define MX 501
 
int cycle_count[MX][MX];
int vis[MX];
vector <int> edge[MX];
vector < pair<int,int> > cycles;
 
int find_cycle(int u)
{
   if(vis[u] == 1)
      return u;
   vis[u] = 1;
   for(int i=0; i<edge[u].size(); i++)
   {
      int& v = edge[u][i];
      if(vis[v] != 2)
      {
         int origin = find_cycle(v);
         //printf("%d %d found %d\n", u, v, origin);
         if(origin == 0)
            continue;
         if(origin == -1)
            return -1;
         if(origin == u)
         {
            cycles.push_back(make_pair(u,v));
            return -1;
         }
         cycles.push_back(make_pair(u,v));
         return origin;
      }
   }
   vis[u] = 2;
   return 0;
}
 
bool is_cycle(int u, int del_u, int del_v)
{
   if(vis[u] == 1)
      return true;
   vis[u] = 1;
   bool found_cycle = false;
   for(int i=0; i<edge[u].size(); i++)
   {
      int& v = edge[u][i];
      if(vis[v] != 2 && !(u == del_u && v == del_v))
         if(is_cycle(v, del_u, del_v))
            return true;
   }
   vis[u] = 2;
   return found_cycle;
}
 
int main()
{
   int n, m, u, v;
   scanf("%d %d", &n, &m);
   for(int i=0; i<m; i++)
   {
      scanf("%d %d", &u, &v);
      edge[u].push_back(v);
   }
 
   memset(vis,0,sizeof(vis));
   for(int i=1; i<=n; i++)
   {
      if(find_cycle(i) == -1)
         break;
   }
 
   /*for(int i=0; i<cycles.size(); i++)
   {
      printf("%d %d\n", cycles[i].first, cycles[i].second);
   }*/
 
   for(int i=0; i<cycles.size(); i++)
   {
      //printf("removing %d %d\n", cycles[i].first, cycles[i].second);
      bool cycle_found = false;
      memset(vis,0,sizeof(vis));
      for(int j=1; j<=n; j++)
      {
         cycle_found = cycle_found || is_cycle(j, cycles[i].first, cycles[i].second);
      }
      if(!cycle_found)
      {
         puts("YES");
         return 0;
      }
   }
 
   if(cycles.empty())
      puts("YES");
   else
      puts("NO");
 
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 