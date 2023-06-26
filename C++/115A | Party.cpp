#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
   ios_base::sync_with_stdio(false);
 int n, mng;
 cin>>n;
 vector <int> v[n+1], roots;
 int lvl[n+1];
 memset(lvl,-1,sizeof(lvl));
 for(int i=1; i<=n; i++)
   {
      cin>>mng;
      if(mng!=-1)
         v[mng].push_back(i);
      else
         roots.push_back(i);
   }
   queue <int> que;
   int maxDepth = 1;
   for(int i: roots)
   {
      que.push(i);
      lvl[i] = 1;
      while(!que.empty())
      {
         int top = que.front();
         for(int j: v[top])
         {
            if(lvl[j]==-1)
            {
               que.push(j);
               lvl[j] = lvl[top]+1;
               maxDepth = max(maxDepth,lvl[j]);
            }
         }
         que.pop();
      }
   }
   cout<<maxDepth<<endl;
 return 0;
}