#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
using namespace std;
 
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
   int n, m, u, v;
   cin>>n>>m;
   set <int> all, edge[200001];
 
   for(int i=1; i<=n; i++)
      all.insert(i);
 
   while(m--)
   {
      cin>>u>>v;
      edge[u].insert(v);
      edge[v].insert(u);
   }
 
   vector <int> sizes;
 
   while(!all.empty())
   {
      int old = all.size();
 
      int top = *all.begin();
      all.erase(all.begin());
 
      queue <int> que;
      que.push(top);
 
      while(!que.empty())
      {
         u = que.front();
         que.pop();
         for(set<int>::iterator it = all.begin(); it!=all.end(); )
         {
            if(edge[u].count(*it) == 0)
            {
               que.push(*it);
               it = all.erase(it);
            }
            else
               it++;
         }
      }
 
      sizes.push_back(old - all.size());
   }
 
   sort(sizes.begin(), sizes.end());
 
   cout<<sizes.size()<<'\n';
   for(int i=0; i<sizes.size(); i++)
      cout<<sizes[i]<<' ';
   cout<<endl;
 
   return 0;
}