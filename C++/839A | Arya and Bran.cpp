#include <bits/stdc++.h>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(false);
   int n, k;
   cin>>n>>k;
   int candy = 0, a, days = 0;
   for(int i=0; i<n; i++)
   {
      cin>>a;
      candy += a;
      k -= min(candy,8);
      candy -= min(candy,8);
      days++;
      if(k<=0)
         break;
   }
   if(k>0)
      cout<<"-1"<<endl;
   else
      cout<<days<<endl;
   return 0;
}