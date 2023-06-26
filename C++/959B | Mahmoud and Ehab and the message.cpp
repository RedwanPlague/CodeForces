#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define MX 30
#define MOD 101
 
int main()
{
   ios_base::sync_with_stdio(0);
 
   int n, k, m, a;
   cin>>n>>k>>m;
   string in;
   map <string, int> mp;
   int cost[n+1];
 
   for(int i=1; i<=n; i++)
   {
      cin>>in;
      mp[in] = i;
   }
 
   for(int i=1; i<=n; i++)
   {
      cin>>cost[i];
   }
 
   int memb;
   int minCost[n];
   map <int, int> gr;
 
   for(int i=0; i<k; i++)
   {
      cin>>memb;
      minCost[i] = 1000000007;
      for(int j=0; j<memb; j++)
      {
         cin>>a;
         gr[a] = i;
         minCost[i] = min(minCost[i], cost[a]);
      }
   }
 
   ll totCost = 0;
 
   for(int i=0; i<m; i++)
   {
      cin>>in;
      totCost += minCost[gr[mp[in]]];
   }
 
   cout<<totCost<<endl;
 
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 