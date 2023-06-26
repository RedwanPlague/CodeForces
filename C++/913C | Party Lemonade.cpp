#include <iostream>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
int n;
ll L;
int price[31];
 
ll least(const ll M)
{
   ll cost = 0;
   for(int i=0; i<n-1; i++)
   {
      if((M>>i)&1)
         cost += price[i];
   }
   cost += (M>>(n-1))*price[n-1];
   return cost;
}
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   cin>>n>>L;
 
   cin>>price[0];
 
   for(int i=1; i<n; i++)
   {
      cin>>price[i];
      price[i] = min(2*price[i-1], price[i]);
   }
 
   ll minCost = least(L);
 
   for(int i=0; i<31; i++)
   {
      if((L>>i)&1) continue;
 
      //cout<<( (L|(1<<i)) & (-1<<i) )<<endl;
 
      minCost = min(minCost, least( (L|(1<<i)) & (-1<<i) ));
 
      //cout<<least( (L|(1<<i)) & (-1<<i) )<<endl;
   }
 
   cout<<minCost<<endl;
 
   return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 