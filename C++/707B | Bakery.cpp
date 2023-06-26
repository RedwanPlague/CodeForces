#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define PII pair <int,int>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
int main()
{
   ios_base::sync_with_stdio(false);
 int n, m, k;
 cin>>n>>m>>k;
 vector <PII> vec[n+1];
 vector <int> store;
 int info[n+1];
 memset(info,0,sizeof(info));
 for(int i=0, u, v, l; i<m; i++)
   {
      cin>>u>>v>>l;
      vec[u].pb(mp(v,l));
      vec[v].pb(mp(u,l));
   }
   for(int i=0, u; i<k; i++)
   {
      cin>>u;
      store.pb(u);
      info[u] = 1;
   }
   int minDis = (1<<30);
   for(int& u: store)
   {
      for(int v=0; v<vec[u].size(); v++)
      {
         if(info[vec[u][v].first]==0)
            minDis = min(minDis, vec[u][v].second);
      }
   }
   if(minDis == (1<<30))
      minDis = -1;
   cout<<minDis<<endl;
 return 0;
}