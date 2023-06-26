#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main()
{
   ios_base::sync_with_stdio(false);
 
   int n, pos, l, r;
   cin>>n>>pos>>l>>r;
 
   int ans;
 
   if(l==1 && r==n)
      ans = 0;
   else if(l==1)
   {
      ans = abs(r-pos)+1;
   }
   else if(r==n)
   {
      ans = abs(l-pos)+1;
   }
   else
   {
      ans = (r-l)+min(abs(l-pos),abs(r-pos))+2;
   }
 
   cout<<ans<<endl;
 
   return 0;
}
 