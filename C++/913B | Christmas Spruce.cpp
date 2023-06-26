#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   int n, a;
   vector <int> children[1005];
   cin>>n;
 
   for(int i=2; i<=n; i++)
   {
      cin>>a;
      children[a].push_back(i);
   }
 
   for(int i=1; i<=n; i++)
   {
      int count = 0;
      for(int j=0; j<children[i].size(); j++)
      {
         int& child = children[i][j];
         if(children[child].size() == 0)
            count++;
      }
      if(children[i].size() != 0 && count < 3)
      {
         cout<<"NO"<<endl;
         return 0;
      }
   }
 
   cout<<"YES"<<endl;
 
   return 0;
}
 