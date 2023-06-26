#include <iostream>
using namespace std;
 
#define INF 10000000
 
int main()
{
   ios_base::sync_with_stdio(false);
   int node, edge;
   int prime = 100003;
   cin>>node>>edge;
   cout<<prime<<" "<<prime<<"\n";
   for(int i = 1; i < node-1; i++)
   {
      cout<<i<<" "<<i+1<<" 1\n";
      prime--;
   }
   cout<<node-1<<" "<<node<<" "<<prime<<"\n";
   int taken = node;
   for(int i = 1; taken <= edge; i++)
   {
      for(int j = i+2; j <= node && taken <= edge; j++)
      {
         cout<<i<<" "<<j<<" "<<INF<<"\n";
         taken++;
      }
   }
   return 0;
}